# mk file to copy VTS specs as part of packaging
#
PRODUCT_COPY_FILES += \
    test/vts/sysfuzzer/libinterfacespecification/specification/CameraHalV1.vts:system/etc/CameraHalV1.vts \
    test/vts/sysfuzzer/libinterfacespecification/specification/GpsHalV1.vts:system/etc/GpsHalV1.vts \
    test/vts/sysfuzzer/libinterfacespecification/specification/GpsHalV1GpsInterface.vts:system/etc/GpsHalV1GpsInterface.vts \
    test/vts/sysfuzzer/libinterfacespecification/specification/LightHalV1.vts:system/etc/LightHalV1.vts
