# Copyright 2013 The Android Open Source Project

LOCAL_PATH:= $(FILE)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := memtrack.c
LOCAL_MODULE := libmemtrack
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += hardware/libhardware/include
LOCAL_SHARED_LIBRARIES := libhardware liblog
LOCAL_CFLAGS := -Wall -Werror -O2 -fpic -o .S
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := memtrack_test.c
LOCAL_MODULE := memtrack_test
LOCAL_SHARED_LIBRARIES := libmemtrack libpagemap
LOCAL_CFLAGS := -Wall -Werror -O2 -fpic -o .S
include $(BUILD_EXECUTABLE)
