#-------------------------------------------------
#
# Project created by QtCreator 2018-03-04T22:04:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = utils
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += YOUR_PLATFORM



contains(QMAKE_TARGET.arch, x86_64){
    OS=x64
}else{
    OS=i86
}

win32:CONFIG(release, debug|release):{
    message("Release...")
    LIB_SUFFIX=""
}

#window debug platform
win32:CONFIG(debug, debug|release):{
    message("Debug...")
    LIB_SUFFIX=d
}


YOUR_PLATFORM{
    message("Deep Tool!!!")
    THIRD_DIR = $$PWD/../../third_lib
    CONFIG += OPENCV3
}


OPENCV3{
CV_DIR = $${THIRD_DIR}/opencv320
INCLUDEPATH += $${CV_DIR}/include
LIBS += -L$${CV_DIR}/lib/ -lopencv_world320$${LIB_SUFFIX}
}

SOURCES += main.cpp\
        mainwindow.cpp \
    third_utils/misc.cpp \
    filetree.cpp

HEADERS  += mainwindow.h \
    third_utils/misc.h \
    filetree.h

FORMS    += mainwindow.ui
