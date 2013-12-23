
#-------------------------------------------------
#
# Project created by QtCreator 2013-05-12T10:36:25
#
#-------------------------------------------------

QT       += core gui sql xml webkit network
CONFIG   += help
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jpconj
TEMPLATE = app
DESTDIR = ../jpconj-bin

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

system(cd i18n; lrelease *.ts)

unix {
binfile.files += jpconj
binfile.path = /usr/bin/
configfiles.files += verbs, i18n, img/icon.png
configfiles.files += verbs
configfiles.files += i18n
configfiles.path = /usr/share/jpconj/
docfiles.files +=
docfiles.path = /usr/share/doc/
manfiles.files +=
manfiles.path = /usr/share/man/man1/
shortcutfiles.files += jpconj.desktop
shortcutfiles.path = /usr/share/applications/
INSTALLS += configfiles
INSTALLS += docfiles
INSTALLS += manfiles
INSTALLS += shortcutfiles
INSTALLS += binfile
}