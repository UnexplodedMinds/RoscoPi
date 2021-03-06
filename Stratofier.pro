#-------------------------------------------------
#
# Stratofier
# Copyright 2019 Sky Fun
#
#-------------------------------------------------

QT += core gui websockets widgets network concurrent xml

VPATH += ./include \
         ../include \
         ../Stratofier/ui \
         ../Stratofier/include

android {
QT += androidextras
CONFIG += mobility
VPATH += $$PWD/android
ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

ANDROID_NDK_PLATFORM = android-29

DISTFILES += AndroidManifest.xml \
#             gradle/wrapper/gradle-wrapper.jar \
#             gradlew \
             res/values/libs.xml \
             res/drawable-ldpi/icon.png \
             res/drawable-mdpi/icon.png \
             res/drawable-hdpi/icon.png \
#             build.gradle \
#             gradle/wrapper/gradle-wrapper.properties \
#             gradlew.bat

SOURCES += ScreenLocker.cpp
HEADERS += ScreenLocker.h
}

TARGET = Stratofier
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += ./include \
               ../include \
               ./gen/uic \
               ./gen/rcc

DESTDIR = ./bin
OBJECTS_DIR = ./obj

UI_DIR = ./gen/uic
MOC_DIR = ./gen/moc
RCC_DIR = ./gen/rcc

QMAKE_CXXFLAGS += -Wno-reorder

SOURCES += main.cpp \
           StreamReader.cpp \
           AHRSCanvas.cpp \
           AHRSDraw.cpp \
           AHRSMainWin.cpp \
           BugSelector.cpp \
           Keypad.cpp \
           TrafficMath.cpp \
           Canvas.cpp \
           MenuDialog.cpp \
           Builder.cpp \
           TimerDialog.cpp \
           FuelTanksDialog.cpp \
           ClickLabel.cpp \
           SettingsDialog.cpp \
           AirportDialog.cpp \
           CountryDialog.cpp \
           DetailsDialog.cpp \
           Overlays.cpp \
           Keyboard.cpp

HEADERS += StratuxStreams.h \
           StreamReader.h \
           AHRSCanvas.h \
           AHRSDraw.h \
           AHRSMainWin.h \
           BugSelector.h \
           Keypad.h \
           TrafficMath.h \
           Canvas.h \
           MenuDialog.h \
           Builder.h \
           StratofierDefs.h \
           TimerDialog.h \
           ScreenLocker.h \
           FuelTanksDialog.h \
           ClickLabel.h \
           SettingsDialog.h \
           AirportDialog.h \
           CountryDialog.h \
           DetailsDialog.h \
           Overlays.h \
           Keyboard.h

FORMS += AHRSMainWin.ui \
         BugSelector.ui \
         Keypad.ui \
         MenuDialog.ui \
         TimerDialog.ui \
         FuelTanksDialog.ui \
         FuelTanksDialogLandscape.ui \
         SettingsDialog.ui \
         AirportDialog.ui \
         CountryDialog.ui \
         DetailsDialog.ui \
         Overlays.ui \
         Keyboard.ui

RESOURCES += AHRSResources.qrc

ANDROID_ABIS = armeabi-v7a
