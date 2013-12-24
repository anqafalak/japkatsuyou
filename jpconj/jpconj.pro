
#-------------------------------------------------
#
# Project created by QtCreator 2013-05-12T10:36:25
#
#-------------------------------------------------

QT       += core gui sql webkit network
CONFIG   += help
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jpconj
TEMPLATE = app

VERSION = 1.0
DEFINES += VERSION=\\\"$$VERSION\\\"

SOURCES  += main.cpp\
            jpconjmain.cpp \
            about.cpp \
            edict2.cpp \
            preference.cpp \
            language.cpp \
            export.cpp \
            jpconjhelp.cpp \
            helpviewer.cpp \
            jpconjtray.cpp

HEADERS  += jpconjmain.h \
            about.h \
            edict2.h \
            preference.h \
            paths.h \
            msg.h \
            language.h \
            export.h \
            jpconjhelp.h \
            helpviewer.h \
            jpconjtray.h

FORMS    += jpconjmain.ui \
            about.ui \
            preference.ui \
            jpconjhelp.ui

TRANSLATIONS    +=  i18n/jpconj_ar.ts\
                    i18n/jpconj_ja.ts\
                    i18n/jpconj_fr.ts

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libjpconj-bin/release/ -llibjpconj
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libjpconj-bin/debug/ -llibjpconj
else:symbian: LIBS += -llibjpconj
else:unix: LIBS += -L$$PWD/../libjpconj-bin/ -ljpconj

INCLUDEPATH += ../libjpconj
DEPENDPATH += . ../libjpconj


RESOURCES += \
    icons.qrc \
    about.qrc \
    output.qrc

    
win32:RC_FILE = jpconj.rc



unix {
system(mkdir ../jpconj-bin)


system(cd i18n; lrelease *.ts)
system(mkdir ../jpconj-bin/i18n)
system(mv i18n/*.qm ../jpconj-bin/i18n)
system(cp i18n/*.ini ../jpconj-bin/i18n)

system(cd help; for file in *.qhcp; do qcollectiongenerator $file -o ${file%.qhcp}.qhc; done)
system(mkdir ../jpconj-bin/help)
system(mv help/*.qhc ../jpconj-bin/help)
system(mv help/*.qch ../jpconj-bin/help)

target.path = /usr/bin/
configfiles.files += img/icon.png
configfiles.files += verbs
configfiles.files += styles
configfiles.files += ../jpconj-bin/i18n
configfiles.files += ../jpconj-bin/help
configfiles.path = /usr/share/jpconj/
docfiles.files +=
docfiles.path = /usr/share/doc/
manfiles.files +=
manfiles.path = /usr/share/man/man1/
shortcutfiles.files += jpconj.desktop
shortcutfiles.path = /usr/share/applications/
INSTALLS += target
INSTALLS += configfiles
INSTALLS += docfiles
INSTALLS += manfiles
INSTALLS += shortcutfiles
}