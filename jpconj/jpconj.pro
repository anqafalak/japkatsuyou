#-------------------------------------------------
#
# Project created by QtCreator 2013-05-12T10:36:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jpconj
TEMPLATE = app


SOURCES += main.cpp\
        jpconjmain.cpp \
    libjpconjlink.cpp

HEADERS  += jpconjmain.h \
    libjpconjlink.h \
    verbtype.h \
    verbtime.h

FORMS    += jpconjmain.ui

TRANSLATIONS    +=  localization/jpconj_en.ts

LIBS    += -L../libjpconj-release -llibjpconj
INCLUDEPATH +=  ../libjpconj

OTHER_FILES +=

