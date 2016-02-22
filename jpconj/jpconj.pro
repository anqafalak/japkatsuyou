
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


VERSION = 1.0.1
DEFINES += VERSION=\\\"$$VERSION\\\"
DEFINES += dataFolder=\\\"./\\\" #/usr/share/jpconj/


SOURCES  += main.cpp\
            Ui/jpconjmain.cpp \
            Ui/about.cpp \
            Func/edict2.cpp \
            Ui/preference.cpp \
            UiHelper/language.cpp \
            UiHelper/export.cpp \
            Ui/jpconjhelp.cpp \
            Ui/helpviewer.cpp \
            UiHelper/jpconjtray.cpp \
            UiHelper/style.cpp \
            Ui/conjframe.cpp \
    UiHelper/funcframe.cpp \
    Func/jtrans.cpp

HEADERS  += Ui/jpconjmain.h \
            Ui/about.h \
            Func/edict2.h \
            Ui/preference.h \
            UiHelper/msg.h \
            UiHelper/language.h \
            UiHelper/export.h \
            Ui/jpconjhelp.h \
            Ui/helpviewer.h \
            UiHelper/jpconjtray.h \
            UiHelper/style.h \
            Ui/conjframe.h \
    UiHelper/funcframe.h \
    Func/jtrans.h

FORMS    += Ui/jpconjmain.ui \
            Ui/about.ui \
            Ui/preference.ui \
            Ui/jpconjhelp.ui \
            Ui/conjframe.ui

TRANSLATIONS    +=  Media/i18n/jpconj_ar.ts\
                    Media/i18n/jpconj_ja.ts\
                    Media/i18n/jpconj_fr.ts

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libjpconj-bin/ -llibjpconj
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libjpconj-bin/debug/ -llibjpconj
else:symbian: LIBS += -llibjpconj
else:unix: LIBS += -L../libjpconj-bin/ -ljpconj

INCLUDEPATH += ../libjpconj
DEPENDPATH += . ../libjpconj-bin


RESOURCES += \
    Media/about.qrc \
    Media/icons.qrc \
    Media/output.qrc

    
win32:RC_FILE = jpconj.rc


#Used when packaging only
DESTDIR = ../jpconj-bin
unix {
system(mkdir ../jpconj-bin)


system(cd Media/i18n; lrelease *.ts)
system(mkdir ../jpconj-bin/i18n)
system(mv Media/i18n/*.qm ../jpconj-bin/i18n)
system(cp Media/i18n/*.ini ../jpconj-bin/i18n)
system(cd Media/i18n; for i in *.ts; do j=${i$${LITERAL_HASH}jpconj}; cp /usr/share/qt4/translations/qt${j%ts}qm ../../jpconj-bin/i18n; done)

system(cd Media/help; for file in *.qhcp; do qcollectiongenerator $file -o ${file%.qhcp}.qhc; done)
system(mkdir ../jpconj-bin/help)
system(mv Media/help/*.qhc ../jpconj-bin/help)
system(mv Media/help/*.qch ../jpconj-bin/help)

system(mkdir ../jpconj-bin/verbs)
system(cp Media/verbs/* ../jpconj-bin/verbs)

system(mkdir ../jpconj-bin/styles)
system(cp Media/styles/* ../jpconj-bin/styles)

#target.path = /usr/bin/
#configfiles.files += img/icon.png
#configfiles.files += verbs
#configfiles.files += styles
#configfiles.files += ../jpconj-bin/i18n
#configfiles.files += ../jpconj-bin/help
#configfiles.path = /usr/share/jpconj/
#docfiles.files +=
#docfiles.path = /usr/share/doc/
#manfiles.files +=
#manfiles.path = /usr/share/man/man1/
#shortcutfiles.files += jpconj.desktop
#shortcutfiles.path = /usr/share/applications/
#INSTALLS += target
#INSTALLS += configfiles
#INSTALLS += docfiles
#INSTALLS += manfiles
#INSTALLS += shortcutfiles
}
