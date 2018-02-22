LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CERTIFICATE := PRESIGNED
   
# Module name should match apk name to be installed.

LOCAL_MODULE := Youtube

LOCAL_SRC_FILES := $(LOCAL_MODULE).apk

LOCAL_MODULE_CLASS := APPS

LOCAL_MODULE_SUFFIX := $(COMMON_ANDROID_PACKAGE_SUFFIX)
   
include $(BUILD_PREBUILT)
