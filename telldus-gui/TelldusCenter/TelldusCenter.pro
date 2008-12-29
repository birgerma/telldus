# -------------------------------------------------
# Project created by QtCreator 2008-12-11T11:01:36
# -------------------------------------------------
TARGET = TelldusCenter
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    tellduscenterapplication.cpp \
    autoupdater.cpp
HEADERS += mainwindow.h \
    tellduscenterapplication.h \
    autoupdater.h \
    CocoaInitializer.h
FORMS += 
RESOURCES += resource.qrc
macx {
    HEADERS += sparkleautoupdater.h
    LIBS += -framework TelldusGui -framework Sparkle
    OBJECTIVE_SOURCES += SparkleAutoUpdater.mm \
        CocoaInitializer.mm
    QMAKE_INFO_PLIST = Info.plist
}
!macx:LIBS += -ltelldus-gui
VERSION = 1.3.0
