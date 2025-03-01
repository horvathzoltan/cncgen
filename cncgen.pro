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
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -llogger
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lshortguid # loggerhez kell
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lsignalhelper
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lCommandLineParserHelper
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lcoreappworker
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -lstringhelper
#LIBS += -L$$COMMON_LIBS_FULLPATH/ -ltextfilehelper
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
        compensate.cpp \
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
        generategcode/commenttogcode.cpp \
        generategcode/compensation.cpp \
        generategcode/cuts/circulararccut.cpp \
        generategcode/cuts/helicalcut.cpp \
        generategcode/cuts/linearcut.cpp \
        generategcode/dwell.cpp \
        generategcode/feedtogcode.cpp \
        generategcode/gcodecommon.cpp \
        generategcode/gcodemanager.cpp \
        generategcode/geometry/arctogcode.cpp \
        generategcode/geometry/boxtogcode.cpp \
        generategcode/geometry/holetogcode.cpp \
        generategcode/geometry/linetogcode.cpp \
        generategcode/goto.cpp \
        generategcode/lift.cpp \
        generategcode/mmodetogcode.cpp \
        generategcode/spindle.cpp \
        generategcode/stringtogcode.cpp \
        generategcode/togcodemodel.cpp \
        generategcode/tooltogcode.cpp \
        generategcode/totalstats.cpp \
        generategcode/xymodetogcode.cpp \
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
        helpers/commandlineparserhelper.cpp \
        helpers/filenamehelper.cpp \
        helpers/logger.cpp \
        helpers/signalhelper.cpp \
        helpers/stringhelper.cpp \
        helpers/textfilehelper.cpp \
        lastgeom.cpp \
        main.cpp \
        messages.cpp \
        parsestate.cpp \
        work1.cpp

HEADERS += \
    compensate.h \
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
    generategcode/commenttogcode.h \
    generategcode/compensation.h \
    generategcode/cuts/circulararccut.h \
    generategcode/cuts/helicalcut.h \
    generategcode/cuts/linearcut.h \
    generategcode/dwell.h \
    generategcode/feedtogcode.h \
    generategcode/gcodecommon.h \
    generategcode/gcodemanager.h \
    generategcode/geometry/arctogcode.h \
    generategcode/geometry/boxtogcode.h \
    generategcode/geometry/holetogcode.h \
    generategcode/geometry/linetogcode.h \
    generategcode/goto.h \
    generategcode/lift.h \
    generategcode/mmodetogcode.h \
    generategcode/spindle.h \
    generategcode/stringtogcode.h \
    generategcode/togcodemodel.h \
    generategcode/tooltogcode.h \
    generategcode/totalstats.h \
    generategcode/xymodetogcode.h \
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
    helpers/commandlineparserhelper.h \
    helpers/filenamehelper.h \
    helpers/logger.h \
    helpers/macro.h \
    helpers/nameof.h \
    helpers/signalhelper.h \
    helpers/stringhelper.h \
    helpers/textfilehelper.h \
    lastgeom.h \
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
    testdata/12x36_lampa_alatet.txt \
    testdata/6x15_lampa_alatet.txt \
    testdata/M3_alatet_8db.txt \
    testdata/M3_dupla_alatet_20.txt \
    testdata/M3x10_alatet_5db.txt \
    testdata/M3x6_alatet_4db.txt \
    testdata/M3x6_alatet_6db.txt \
    testdata/M3x7_alatet.txt \
    testdata/M3x9_alatet_6db.txt \
    testdata/M5x10_alatet_4db.txt \
    testdata/StirotexMerleg_fedlap_ledek.txt \
    testdata/StirotexMerleg_hatlap_sablon.txt \
    testdata/StirotexMerleg_hatlap_sablon2.txt \
    testdata/StirotexMerleg_led_beulteto.txt \
    testdata/alatet.txt \
    testdata/bed_flattening.txt \
    testdata/bekapcsolo.txt \
    testdata/bill_tamaszto.txt \
    testdata/cam_elolap.txt \
    testdata/cam_elolap_bolcso.txt \
    testdata/cam_teteje.txt \
    testdata/ceruzatarto.txt \
    testdata/csatlakozo.txt \
    testdata/eger.txt \
    testdata/ethernet2.txt \
    testdata/geom1.txt \
    testdata/geom2.txt \
    testdata/geom3.txt \
    testdata/geom3_1.txt \
    testdata/gomb.txt \
    testdata/gomb6mm.txt \
    testdata/hammond_doboz_lab_4db.txt \
    testdata/hammond_doboz_tap2.txt \
    testdata/hammond_doboz_tap3.txt \
    testdata/hdmi.txt \
    testdata/head.gcode \
    testdata/holetest.txt \
    testdata/huto.txt \
    testdata/huto_furatsablon.txt \
    testdata/kocsma_doboz_alja.txt \
    testdata/kocsma_doboz_alja_1mm.txt \
    testdata/kocsma_doboz_alja_1mm_keret.txt \
    testdata/kocsma_doboz_alja_2mm.txt \
    testdata/kocsma_doboz_alja_2mm2.txt \
    testdata/kocsma_doboz_oldala.txt \
    testdata/kocsma_doboz_oldala_csakhdmi.txt \
    testdata/kocsma_doboz_oldala_csakhdmi_2.txt \
    testdata/linetest.txt \
    testdata/luk.txt \
    testdata/mestercipo_csatlakozo_belezes.txt \
    testdata/mestercipo_doboz_fedlap.txt \
    testdata/mestercipo_doboz_felso_furat.txt \
    testdata/mestercipo_doboz_felso_szerelolap.txt \
    testdata/mestercipo_doboz_hatlap_felso.txt \
    testdata/mestercipo_doboz_hatlap_hp.txt \
    testdata/mestercipo_doboz_hatlap_lenovo.txt \
    testdata/mestercipo_logger_led.txt \
    testdata/mestercipo_logger_oldal.txt \
    testdata/mestercipo_tap_szerelolap_1.txt \
    testdata/mestercipo_tap_szerelolap_also.txt \
    testdata/mestercipo_tap_szerelolap_also_2.txt \
    testdata/meton_doboz_also_szerelolap.txt \
    testdata/meton_doboz_felso_szerelolap.txt \
    testdata/meton_doboz_felso_szerelolap_4.txt \
    testdata/meton_doboz_hatlap_sablon.txt \
    testdata/meton_kepernyobeulteto.txt \
    testdata/meton_panel_rogzito.txt \
    testdata/ms_kamera_tarto.txt \
    testdata/pi_alatet_24db.txt \
    testdata/pi_alatet_4db.txt \
    testdata/pi_alatet_5db.txt \
    testdata/pi_bolcso_15.txt \
    testdata/pi_bolcso_15_2.txt \
    testdata/pi_hatlap.txt \
    testdata/ping1.txt \
    testdata/ping2.txt \
    testdata/t1.txt \
    testdata/t2.txt \
    testdata/tamaszto.txt \
    testdata/tamaszto2.txt \
    testdata/tamaszto3.txt \
    testdata/tap_fesu.txt \
    testdata/tap_fesu_12.txt \
    testdata/tapdugo_furosablon.txt \
    testdata/telefontarto.txt \
    testdata/uniturn_doboz_fedlap_2.txt \
    testdata/uniturn_doboz_hatlap_sablon.txt \
    testdata/uniturn_doboz_szerelolap.txt \
    testdata/uniturn_kartyalovaso_rogzito.txt \
    testdata/uniturn_kartyaolvaso.txt \
    testdata/uniturn_kartyaolvaso_alatet.txt \
    testdata/uniturn_kartyaolvaso_patent.txt \
    testdata/uniturn_kartyaolvaso_patent_dual.txt \
    testdata/uniturn_pizero_bolcso.txt \
    testdata/uniturn_relay_doboz_hatlap.txt \
    testdata/uniturn_relay_felso_szerelolap.txt \
    testdata/uniturn_relay_relays.txt \
    testdata/uniturn_relay_szerelolap.txt \
    testdata/uniturn_tap_panel_rogzito.txt \
    testdata/uniturn_tavtarto_5mm.txt \
    testdata/uniturn_tavtarto_5mm_2oldalas.txt \
    testdata/uniturn_tavtarto_5mm_csapos.txt \
    testdata/uniturn_tavtarto_6mm.txt \
    testdata/uniturn_usb_kengyel.txt \
    testdata/uniturn_usb_kengyel_rogzito.txt \
    testdata/usb.txt \
    testdata/villaskulcs_10.txt \
    testdata/villaskulcs_11,8.txt \
    testdata/villaskulcs_14,8.txt \
    testdata/villaskulcs_16.txt \
    testdata/villaskulcs_17.txt \
    testdata/villaskulcs_19.txt \
    testdata/villaskulcs_22.txt \
    testdata/villaskulcs_22_2.txt \
    testdata/villaskulcs_27.txt \
    testdata/villaskulcs_27_2.txt
