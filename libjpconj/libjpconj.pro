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

