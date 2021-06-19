#-------------------------------------------------
#
# Project created by QtCreator 2021-06-18T21:16:28
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_StoreStocksWeb
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

RESOURCES += \
    resources.qrc

RC_FILE = myapp.rc
