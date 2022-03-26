QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += SOURCE_PATH=$$PWD
DEFINES += TARGI=$$TARGET

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

unix:HOME = $$system(echo $HOME)
win32:HOME = $$system(echo %userprofile%)

CONFIG(debug, debug|release){
BUILD = debug
} else {
BUILD = release
}

COMMON_LIBS = commonlib

equals(BUILD,debug) {
    #message( "build is _ debug" )
    COMMON_LIBS = $$COMMON_LIBS"_debug"
}

equals(BUILD,release){
    COMMON_LIBS = $$COMMON_LIBS"_release"
}

equals(QT_ARCH, x86_64){
    COMMON_LIBS = $$COMMON_LIBS"_64"
}

equals(QT_ARCH, x86){
    COMMON_LIBS = $$COMMON_LIBS"_32"
}

equals(QT_ARCH, arm){
    COMMON_LIBS = $$COMMON_LIBS"_arm"
}

message( "architecture = "$$QT_ARCH )
message( "commonlibs folder = "$$COMMON_LIBS )

#unix:HOME = $$system(echo $HOME)
#win32:HOME = $$system(echo %userprofile%)

# INSTALLDIR = $$COMMON_LIBS
COMMON_LIBS_FULLPATH = $$shell_path($$HOME/$$COMMON_LIBS)

message( " commonlibs full path = "$$COMMON_LIBS_FULLPATH)

#unix:!macx: LIBS += -L/home/zoli/build-common-Desktop_Qt_5_12_2_GCC_64bit2-Debug/stringhelper/ -lstringhelper
unix:!macx:
{
message( "hmmmm "$$HOME/$$COMMON_LIBS)
LIBS += -L$$COMMON_LIBS_FULLPATH/ -llogger
LIBS += -L$$COMMON_LIBS_FULLPATH/ -lshortguid # loggerhez kell
LIBS += -L$$COMMON_LIBS_FULLPATH/ -lsignalhelper
LIBS += -L$$COMMON_LIBS_FULLPATH/ -lCommandLineParserHelper
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lcoreappworker
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lstringhelper
LIBS += -L$$COMMON_LIBS_FULLPATH/ -ltextfilehelper
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lfilehelper
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -ldownloadhelper
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lprocesshelper
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lmacrofactory

#LIBS += -L$$COMMON_LIBS_FULLPATH/ -linihelper
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lsettingshelper
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lxmlhelper
}

# unix:QMAKE_RPATHDIR += /usr/mylib
# QMAKE_LFLAGS += -Wl,-rpath, "$$system_path($$HOME/$$INSTALLDIR)"
#QMAKE_LFLAGS += -Wl,-rpath,"$$HOME/$$COMMON_LIBS_FULLPATH"
#QMAKE_LFLAGS += -Wl,-rpath,"/$$HOME/$$INSTALLDIR/macrofactory"
#QMAKE_LFLAGS += -Wl,-rpath,"/home/zoli/build-common-Desktop_Qt_5_9_0_GCC_64bit-Debug/stringhelper"
#QMAKE_LFLAGS += -Wl,-rpath,"/home/zoli/build-common-Desktop_Qt_5_9_0_GCC_64bit-Debug/macrofactory"
#QMAKE_LFLAGS += -Wl,-rpath,"/home/zoli/build-common-Desktop_Qt_5_12_2_GCC_64bit2-Debug/stringhelper"
#QMAKE_LFLAGS += -Wl,-rpath,"/home/zoli/build-common-Desktop_Qt_5_12_2_GCC_64bit2-Debug/macrofactory"
#INCLUDEPATH += $$HOME/common
INCLUDEPATH += $$HOME/common
DEPENDPATH += $$HOME/common

SOURCES += \
        gcode/comment.cpp \
        gcode/cut.cpp \
        gcode/expression.cpp \
        gcode/feed.cpp \
        gcode/gcode.cpp \
        gcode/keyword.cpp \
        gcode/string.cpp \
        gcode/tool.cpp \
        gcode/variable.cpp \
        generategcode.cpp \
        geometry/arc.cpp \
        geometry/box.cpp \
        geometry/boxtype.cpp \
        geometry/gap.cpp \
        geometry/geomath.cpp \
        geometry/gmode.cpp \
        geometry/hole.cpp \
        geometry/line.cpp \
        geometry/mmode.cpp \
        geometry/point.cpp \
        geometry/size.cpp \
        geometry/xymode.cpp \
        main.cpp \
        messages.cpp \
        parsestate.cpp \
        work1.cpp

HEADERS += \
    gcode/comment.h \
    gcode/cut.h \
    gcode/expression.h \
    gcode/feed.h \
    gcode/function.h \
    gcode/gcode.h \
    gcode/keyword.h \
    gcode/string.h \
    gcode/tool.h \
    gcode/variable.h \
    generategcode.h \
    geometry/arc.h \
    geometry/box.h \
    geometry/boxtype.h \
    geometry/gap.h \
    geometry/geomath.h \
    geometry/gmode.h \
    geometry/hole.h \
    geometry/line.h \
    geometry/mmode.h \
    geometry/point.h \
    geometry/size.h \
    geometry/xymode.h \
    helpers/filenamehelper.h \
    helpers/stringhelper.h \
    messages.h \
    parsestate.h \
    work1.h

message(includepath = $$INCLUDEPATH)
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



#\
#    signalhelper.h

DISTFILES += \
    testdata/alatet.txt \
    testdata/ethernet2.txt \
    testdata/geom1.txt \
    testdata/geom2.txt \
    testdata/geom3.txt \
    testdata/geom3_1.txt \
    testdata/head.gcode \
    testdata/holetest.txt \
    testdata/linetest.txt \
    testdata/luk.txt \
    testdata/pi_hatlap.txt \
    testdata/tapdugo.txt \
    testdata/tapdugo2.txt \
    testdata/tapdugo3.txt \
    testdata/uniturn_also.txt \
    testdata/uniturn_doboz_hatlap.txt \
    testdata/uniturn_felso.txt \
    testdata/uniturn_usb_tavtarto.txt \
    testdata/uniturn_usb_tavtarto2.txt \
    testdata/usb.txt
