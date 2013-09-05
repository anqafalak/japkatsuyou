; JapKatuyou.nsi
; This is the installer of Japanese verb conjugation application
; on Windows

;--------------------------------


;to use if else statements
;!include LogicLib.nsh

Unicode true
XPStyle on

;detect if windows installer is higher than 3.1
!include MSI.nsh
; The name of the installer
Name "JapKatsuyou"

; The file to write
OutFile JapKatsuyou-0.2.1.exe

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

; License data
LicenseLangString myLicenseData ${LANG_ENGLISH} "JapKatsuyou\license\en.txt"
LicenseLangString myLicenseData ${LANG_ARABIC} "JapKatsuyou\license\ar.txt"
LicenseLangString myLicenseData ${LANG_JAPANESE} "JapKatsuyou\license\ja.txt"
LicenseData $(myLicenseData)

; Set name using the normal interface (Name command)
LangString Name ${LANG_ENGLISH} "JapKatsuyou"
LangString Name ${LANG_ARABIC} "JapKatsuyou"
LangString Name ${LANG_JAPANESE} "JapKatsuyou"
Name $(Name)

; Section JapKatsuyou
Section "JapKatsuyou"
	SectionIn RO

	;Install visual c++ 2010 redistributable (x86) & windows installer 3.1 if not exist
	SetOutPath $PLUGINSDIR
	Var /GLOBAL update
	Call UpdateMSIVersion
	Pop $update
	IntCmp $update 1 +1 msifound msifound
	;	MessageBox MB_OK|MB_ICONEXCLAMATION \
	;	"Windows Installer 3.1 was not detected; this is required for installation. \
	;	Setup will install the Windows Installer. This may take awhile, please wait."
		File "win\WindowsInstaller-KB893803-v2-x86.exe"
		ExecWait '"$PLUGINSDIR\WindowsInstaller-KB893803-v2-x86.exe"  /quiet /norestart'
	msifound:
	;MessageBox MB_OK|MB_ICONEXCLAMATION \
	;	"MSVC 2010. \
	;	Installing visual c++ 2010 redistributable (x86), please wait."
	File "win\vcredist_x86.exe"
	ExecWait '"$PLUGINSDIR\vcredist_x86.exe"  /quiet /norestart'
	
	
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
Section !$(startM) sec1
  CreateDirectory "$SMPROGRAMS\JapKatsuyou"
  CreateShortCut "$SMPROGRAMS\JapKatsuyou\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\JapKatsuyou\JapKatsuyou.lnk" "$INSTDIR\jpconj.exe" "" "$INSTDIR\jpconj.exe" 0
SectionEnd

; Section Desktop Shortcut
LangString desk ${LANG_ENGLISH} "Desktop Shortcut"
LangString desk ${LANG_ARABIC} "اختصار سطح المكتب"
LangString desk ${LANG_JAPANESE} "デスクトップのショートカット"
Section !$(desk) sec2
  CreateShortCut "$DESKTOP\JapKatsuyou.lnk" "$INSTDIR\jpconj.exe" "" "$INSTDIR\jpconj.exe" 0
SectionEnd

;--------------------------------

Function .onInit

	;Language selection dialog

	Push ""
	Push ${LANG_ENGLISH}
	Push English
	Push ${LANG_ARABIC}
	Push Arabic
	Push ${LANG_JAPANESE}
	Push Japanese
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