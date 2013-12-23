#-------------------------------------------------
#
# Project created by QtCreator 2013-05-12T11:02:40
#
#-------------------------------------------------

QT       -= gui

win32{
TARGET = libjpconj
TARGET_EXT = .dll
}
unix: TARGET = jpconj

VERSION = 1.0

TEMPLATE = lib
DESTDIR = ../libjpconj-bin

DEFINES += LIBJPCONJ_LIBRARY

SOURCES +=  \
            verbstem.cpp \
            inflection.cpp \
            jpconj.cpp

HEADERS += \
            verbstem.h \
            typeDefs.h \
            inflection.h \
            jpconj.h \
            jpconj_global.h

unix {
target.path = /usr/lib/

configfiles.files +=
configfiles.path = /usr/share/

docfiles.files +=
docfiles.path = /usr/share/doc/

manfiles.files +=
manfiles.path = /usr/share/man/man1/

shortcutfiles.files +=
shortcutfiles.path = /usr/share/applications/

INSTALLS += target
INSTALLS += configfiles
INSTALLS += docfiles
INSTALLS += manfiles
}
