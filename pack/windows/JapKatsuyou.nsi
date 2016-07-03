; JapKatuyou.nsi
; This is the installer of Japanese verb conjugation application
; on Windows

;--------------------------------


;to use if else statements
;!include LogicLib.nsh

;Unicode true
XPStyle on

;detect if windows installer is higher than 3.1
;!include MSI.nsh
; The name of the installer
Name "JapKatsuyou"

; The file to write
OutFile JapKatsuyou-2.0.0.exe

; The default installation directory
InstallDir $PROGRAMFILES\JapKatuyou

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\JapKatsuyou" "Install_Dir"

; Request application privileges for Windows Vista
RequestExecutionLevel admin

;--------------------------------
Page license
Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles
;--------------------------------

; First is default
LoadLanguageFile "${NSISDIR}\Contrib\Language files\English.nlf"
LoadLanguageFile "${NSISDIR}\Contrib\Language files\Arabic.nlf"
LoadLanguageFile "${NSISDIR}\Contrib\Language files\Japanese.nlf"
LoadLanguageFile "${NSISDIR}\Contrib\Language files\French.nlf"

; License data
LicenseLangString myLicenseData ${LANG_ENGLISH} "JapKatsuyou\license\en.txt"
LicenseLangString myLicenseData ${LANG_ARABIC} "JapKatsuyou\license\ar.txt"
LicenseLangString myLicenseData ${LANG_JAPANESE} "JapKatsuyou\license\ja.txt"
LicenseLangString myLicenseData ${LANG_FRENCH} "JapKatsuyou\license\fr.txt"
LicenseData $(myLicenseData)

; Set name using the normal interface (Name command)
LangString Name ${LANG_ENGLISH} "JapKatsuyou"
LangString Name ${LANG_ARABIC} "JapKatsuyou"
LangString Name ${LANG_JAPANESE} "JapKatsuyou"
LangString Name ${LANG_FRENCH} "JapKatsuyou"
Name $(Name)

; Section JapKatsuyou
Section "JapKatsuyou"
	SectionIn RO
	
	; Set output path to the installation directory.
	SetOutPath $INSTDIR
	
	; Put file there
	File /r "JapKatsuyou\*"
	
	; Write the installation path into the registry
	WriteRegStr HKLM SOFTWARE\JapKatsuyou "Install_Dir" "$INSTDIR"
	
	; Write the uninstall keys for Windows
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\JapKatsuyou" "DisplayName" "JapKatsuyou"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\JapKatsuyou" "UninstallString" '"$INSTDIR\uninstall.exe"'
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\JapKatsuyou" "NoModify" 1
	WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\JapKatsuyou" "NoRepair" 1
	WriteUninstaller "uninstall.exe"
  
SectionEnd

; Section Start Menu Shortcuts
LangString startM ${LANG_ENGLISH} "Start Menu Shortcuts"
LangString startM ${LANG_ARABIC} "اختصارات قائمة ابدأ"
LangString startM ${LANG_JAPANESE} "スタートメニューのショートカット"
LangString startM ${LANG_FRENCH} "Raccourcis du menu Démarrer"
Section !$(startM) sec1
  CreateDirectory "$SMPROGRAMS\JapKatsuyou"
  CreateShortCut "$SMPROGRAMS\JapKatsuyou\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\JapKatsuyou\JapKatsuyou.lnk" "$INSTDIR\jpconj.exe" "" "$INSTDIR\jpconj.exe" 0
SectionEnd

; Section Desktop Shortcut
LangString desk ${LANG_ENGLISH} "Desktop Shortcut"
LangString desk ${LANG_ARABIC} "اختصار سطح المكتب"
LangString desk ${LANG_JAPANESE} "デスクトップのショートカット"
LangString desk ${LANG_FRENCH} "Raccourci du bureau"
Section !$(desk) sec2
  CreateShortCut "$DESKTOP\JapKatsuyou.lnk" "$INSTDIR\jpconj.exe" "" "$INSTDIR\jpconj.exe" 0
SectionEnd

;--------------------------------

Function .onInit

	ReadRegStr $R0 HKLM \
	"Software\Microsoft\Windows\CurrentVersion\Uninstall\JapKatsuyou" \
	"UninstallString"
	StrCmp $R0 "" done
 
	MessageBox MB_OKCANCEL|MB_ICONEXCLAMATION \
	"JapKatsuyou is already installed. $\n$\nClick `OK` to remove the \
	previous version or `Cancel` to cancel this upgrade." \
	IDOK uninst
	Abort
 
	;Run the uninstaller
	uninst:
	ClearErrors
	ExecWait '$R0 _?=$INSTDIR' ;Do not copy the uninstaller to a temp file
 
	IfErrors no_remove_uninstaller done
	;You can either use Delete /REBOOTOK in the uninstaller or add some code
    ;here to remove the uninstaller. Use a registry key to check
    ;whether the user has chosen to uninstall. If you are using an uninstaller
    ;components page, make sure all sections are uninstalled.
	no_remove_uninstaller:
	Abort
	done:

	;Language selection dialog

	Push ""
	Push ${LANG_ENGLISH}
	Push English
	Push ${LANG_ARABIC}
	Push Arabic
	Push ${LANG_JAPANESE}
	Push Japanese
	Push ${LANG_FRENCH}
	Push French
	Push A ; A means auto count languages
	       ; for the auto count to work the first empty push (Push "") must remain
	LangDLL::LangDialog "Installer Language" "Please select the language of the installer"

	Pop $LANGUAGE
	StrCmp $LANGUAGE "cancel" 0 +2
		Abort
FunctionEnd

; Uninstaller

Section "Uninstall"
  
	; Remove registry keys
	DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\JapKatsuyou"
	DeleteRegKey HKLM SOFTWARE\JapKatsuyou

	; Remove files and uninstaller
	;Delete /r $INSTDIR\*
	;Delete $INSTDIR\uninstall.exe
	RMDir /r "$INSTDIR"
	
	; Remove shortcuts, if any
	Delete "$SMPROGRAMS\JapKatsuyou\*.*"
	Delete "$DESKTOP\JapKatsuyou.lnk"

	; Remove directories used
	RMDir "$SMPROGRAMS\JapKatsuyou"
  

SectionEnd