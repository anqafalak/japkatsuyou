;*********************************************************************
; UpdateMSIVersion
;
; This function will check the version of the installed Windows
; Installer. This is done by checking the version of the
; $SYSDIR\MSI.dll (recommended method by the installer team).
;
; Usage
; Call UpdateMSIVersion
; Pop $MSI_UPDATE ; If $MSI_UPDATE is 1, install latest MSI.
;*********************************************************************
Function UpdateMSIVersion
  GetDllVersion "$SYSDIR\MSI.dll" $R0 $R1
  IntOp $R2 $R0 / 0x00010000
  IntOp $R3 $R0 & 0x0000FFFF
 
  IntCmp $R2 3 0 InstallMSI RightMSI
  IntCmp $R3 1 RightMSI InstallMSI RightMSI
 
  RightMSI:
    Push 0
    Goto ExitFunction
 
  InstallMSI:
    Push 1
    Goto ExitFunction
 
  ExitFunction:
 
FunctionEnd