set QtPath=C:\Qt\4.8.5\

mkdir installer\japkatsuyou\license
mkdir installer\win
copy pack\windows\* installer
copy pack\windows\license\* installer\japkatsuyou\license
copy libjpconj-bin\libjpconj.dll installer\japkatsuyou
copy jpconj-bin\jpconj.exe installer\japkatsuyou

mkdir installer\japkatsuyou\verbs
copy jpconj\verbs\* installer\japkatsuyou\verbs

mkdir installer\japkatsuyou\styles
copy jpconj\styles\* installer\japkatsuyou\styles

rem create language files
mkdir installer\japkatsuyou\i18n
setlocal EnableDelayedExpansion
for %%f in (jpconj\i18n\*.ts) do (
lrelease %%f 
set jpconj=%%~nf.qm
set qt=qt!jpconj:jpconj=!
copy %QtPath%translations\!qt! installer\japkatsuyou\i18n
rem echo %QtPath%translations\!qt!
)
move jpconj\i18n\*.qm installer\japkatsuyou\i18n
copy jpconj\i18n\*.ini installer\japkatsuyou\i18n

rem create help files
mkdir installer\japkatsuyou\help
for %%f in (jpconj\help\*.qhcp) do qcollectiongenerator %%f 
move jpconj\help\*.qch installer\japkatsuyou\help
move jpconj\help\*.qhc installer\japkatsuyou\help


rem import libraries needed by this release
copy %QtPath%bin\QtCLucene4.dll installer\japkatsuyou
copy %QtPath%bin\QtCore4.dll installer\japkatsuyou
copy %QtPath%bin\QtGui4.dll installer\japkatsuyou
copy %QtPath%bin\QtHelp4.dll installer\japkatsuyou
copy %QtPath%bin\QtNetwork4.dll installer\japkatsuyou
copy %QtPath%bin\QtSql4.dll installer\japkatsuyou
copy %QtPath%bin\QtWebKit4.dll installer\japkatsuyou
rem plugins
mkdir installer\japkatsuyou\sqldrivers
copy %QtPath%plugins\sqldrivers\qsqlite4.dll installer\japkatsuyou\sqldrivers