# QTDesigner.pro
QT       += core gui

TARGET = QTDesigner
TEMPLATE = app

# Используйте указание версии Qt, если необходимо
# CONFIG += c++11

SOURCES += main.cpp \
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

# Указываем дополнительные библиотеки, если они нужны
# LIBS += -lmy_library

# Если используются модули QT, добавляем их
QT += widgets
