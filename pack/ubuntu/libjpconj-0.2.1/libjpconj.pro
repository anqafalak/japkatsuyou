#-------------------------------------------------
#
# Project created by QtCreator 2013-05-12T11:02:40
#
#-------------------------------------------------

QT       -= gui

VERSION = 0.2

TARGET = libjpconj
TEMPLATE = lib

DEFINES += LIBJPCONJ_LIBRARY

SOURCES +=  libjpconj.cpp \
            verbform.cpp

HEADERS +=  libjpconj.h\
            libjpconj_global.h \
            verbform.h \
            typeDefs.h

            
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