
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
DESTDIR = ../jpconj-bin

VERSION = 1.0.1
DEFINES += VERSION=\\\"$$VERSION\\\"
DEFINES += dataFolder=\\\"./\\\" #/usr/share/jpconj/


SOURCES  += main.cpp\
            Ui/jpconjmain.cpp \
            Ui/about.cpp \
            Conj/edict2.cpp \
            Ui/preference.cpp \
            UiHelper/language.cpp \
            UiHelper/export.cpp \
            Ui/jpconjhelp.cpp \
            Ui/helpviewer.cpp \
            UiHelper/jpconjtray.cpp \
            UiHelper/style.cpp \
            Ui/conjframe.cpp

HEADERS  += Ui/jpconjmain.h \
            Ui/about.h \
            Conj/edict2.h \
            Ui/preference.h \
            UiHelper/msg.h \
            UiHelper/language.h \
            UiHelper/export.h \
            Ui/jpconjhelp.h \
            Ui/helpviewer.h \
            UiHelper/jpconjtray.h \
            UiHelper/style.h \
            Ui/conjframe.h

FORMS    += Ui/jpconjmain.ui \
            Ui/about.ui \
            Ui/preference.ui \
            Ui/jpconjhelp.ui \
            Ui/conjframe.ui

TRANSLATIONS    +=  i18n/jpconj_ar.ts\
                    i18n/jpconj_ja.ts\
                    i18n/jpconj_fr.ts

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libjpconj-bin/ -llibjpconj
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libjpconj-bin/debug/ -llibjpconj
else:symbian: LIBS += -llibjpconj
else:unix: LIBS += -L$$PWD/../libjpconj-bin/ -ljpconj

INCLUDEPATH += ../libjpconj
DEPENDPATH += . ../libjpconj


RESOURCES += \
    Media/about.qrc \
    Media/icons.qrc \
    Media/output.qrc

    
win32:RC_FILE = jpconj.rc



unix {
system(mkdir ../jpconj-bin)


system(cd i18n; lrelease *.ts)
system(mkdir ../jpconj-bin/i18n)
system(mv i18n/*.qm ../jpconj-bin/i18n)
system(cp i18n/*.ini ../jpconj-bin/i18n)
system(cd i18n; for i in *.ts; do j=${i$${LITERAL_HASH}jpconj}; cp /usr/share/qt4/translations/qt${j%ts}qm ../../jpconj-bin/i18n; done)

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
