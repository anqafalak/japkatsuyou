#-------------------------------------------------
#
# Project created by QtCreator 2013-05-12T10:36:25
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jpconj
TEMPLATE = app

VERSION = 0.2
DEFINES += VERSION=\\\"$$VERSION\\\"

SOURCES += main.cpp\
        jpconjmain.cpp \
        libjpconjlink.cpp \
    about.cpp \
    edict2.cpp \
    preference.cpp

HEADERS  += jpconjmain.h \
    libjpconjlink.h \
    about.h \
    typeDefs.h \
    edict2.h \
    preference.h \
    paths.h

FORMS    += jpconjmain.ui \
    about.ui \
    preference.ui

TRANSLATIONS    +=  i18n/jpconj_en.ts\
                    i18n/jpconj_ar.ts\
                    i18n/jpconj_ja.ts\
                    i18n/jpconj_fr.ts

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libjpconj-bin/release/ -llibjpconj
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libjpconj-bin/debug/ -llibjpconj
else:symbian: LIBS += -llibjpconj
else:unix: LIBS += -L$$PWD/../libjpconj-bin/ -llibjpconj

INCLUDEPATH += -L$$PWD/../libjpconj-bin/release
DEPENDPATH += -L$$PWD/../libjpconj-bin/release

RC_FILE = app.rc

RESOURCES += \
    icons.qrc

