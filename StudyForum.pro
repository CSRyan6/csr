#-------------------------------------------------
#
# Project created by QtCreator 2018-11-05T01:01:29
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudyForum
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logininterface.cpp \
    userwindow.cpp \
    changename.cpp \
    changepsd.cpp \
    registe.cpp

HEADERS += \
        mainwindow.h \
    logininterface.h \
    userwindow.h \
    user.h \
    changename.h \
    changepsd.h \
    registe.h

FORMS += \
        mainwindow.ui \
    logininterface.ui \
    userwindow.ui \
    changename.ui \
    changepsd.ui \
    registe.ui

RESOURCES += \
    resource.qrc
