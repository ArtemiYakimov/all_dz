# MyQtProject.pro

QT       += core sql network
QT       -= gui

CONFIG   += c++11 console
CONFIG   -= app_bundle

SOURCES  += main.cpp

# Необязательные, но полезные настройки
INCLUDEPATH += .

# Убедитесь, что указаны правильные пути к библиотекам, если они не находят их по умолчанию
LIBS += -L"path/to/libs" -lQt5Core -lQt5Sql -lQt5Network

DISTFILES += \
    cmakelists.txt
