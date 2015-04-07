TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += rtti

SOURCES += main.cpp \
    FindColor.cpp \
    findobject.cpp \
    FindEllipse.cpp \
    dataanalysis.cpp \
    algo/SixData.cpp \
    grabber/CameraGrabber.cpp \
    transmitter/BridgeTransmitter.cpp \
    Application.cpp \
    algo/spherepositionalgoresult.cpp \
    algo/spherepositionalgo.cpp \
    TCP_client.cpp \
    TCPIP_clieat.cpp

INCLUDEPATH += "/opt/local/include/opencv/"
INCLUDEPATH += "/opt/local/include/opencv2/"
INCLUDEPATH += /opt/local/include

#*****************************

#*****************************
#Include these for OpenCV 2.1.
#*****************************
#LIBS +=  "/opt/local/lib/libcv.dylib"
#LIBS +=  "/opt/local/lib/libcxcore.dylib"
#LIBS +=  "/opt/local/lib/libcvaux.dylib"
#LIBS +=  "/opt/local/lib/libhighgui.dylib"
#*****************************

#*****************************
#Include these for OpenCV 2.2.
#*****************************
LIBS += "/opt/local/lib/libopencv_calib3d.dylib"
LIBS += "/opt/local/lib/libopencv_contrib.dylib"
LIBS += "/opt/local/lib/libopencv_core.dylib"
LIBS += "/opt/local/lib/libopencv_features2d.dylib"
LIBS += "/opt/local/lib/libopencv_flann.dylib"
LIBS += "/opt/local/lib/libopencv_gpu.dylib"
LIBS += "/opt/local/lib/libopencv_highgui.dylib"
LIBS += "/opt/local/lib/libopencv_imgproc.dylib"
LIBS += "/opt/local/lib/libopencv_legacy.dylib"
LIBS += "/opt/local/lib/libopencv_ml.dylib"
LIBS += "/opt/local/lib/libopencv_objdetect.dylib"
LIBS += "/opt/local/lib/libopencv_video.dylib"
#*****************************

HEADERS += \
    FfindColor.h \
    findobject.h \
    FindEllipse.h \
    dataanalysis.h \
    algo/ISpherePositionResultCallback.h \
    algo/SixData.h \
    algo/SpherePositionAlgo.h \
    algo/SpherePositionAlgoResult.h \
    grabber/CameraGrabber.h \
    grabber/ICameraGrabberResultCallback.h \
    transmitter/BridgeTransmitter.h \
    transmitter/ITransmitter.h \
    Application.h \
    TCP_client.h \
    TCPIP_clieat.h


