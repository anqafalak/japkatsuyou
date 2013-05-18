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
        libjpconjlink.cpp \
    about.cpp

HEADERS  += jpconjmain.h \
    libjpconjlink.h \
    about.h \
    typeDefs.h

FORMS    += jpconjmain.ui \
    about.ui

TRANSLATIONS    +=  localization/jpconj_en.ts\
                    localization/jpconj_ar.ts

LIBS    += -L../libjpconj-release -llibjpconj
INCLUDEPATH +=  ../libjpconj-release
OTHER_FILES +=

