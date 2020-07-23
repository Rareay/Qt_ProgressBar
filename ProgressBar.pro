CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(progressbarplugin)
TEMPLATE    = lib

HEADERS     = progressbarplugin.h \
    progressbar.h
SOURCES     = progressbarplugin.cpp \
    progressbar.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(progressbar.pri)

FORMS += \
    progressbar.ui
