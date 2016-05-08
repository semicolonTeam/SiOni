#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T19:43:27
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = siOni
TEMPLATE = app


SOURCES += main.cpp\
        winhome.cpp \
    form_masuk.cpp \
    form_tentang.cpp \
    form_tambahkelas.cpp

HEADERS  += winhome.h \
    form_masuk.h \
    lib.h \
    form_tentang.h \
    form_tambahkelas.h

FORMS    += winhome.ui \
    form_masuk.ui \
    form_tentang.ui \
    form_tambahkelas.ui

RESOURCES += \
    gambar.qrc
