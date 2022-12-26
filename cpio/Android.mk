# Copyright 2005 The Android Open Source Project

LOCAL_PATH:= $(FILE)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	mkbootfs.c

LOCAL_MODULE := mkbootfs

LOCAL_CFLAGS := -Werror -O0

LOCAL_SHARED_LIBRARIES := libcutils, asm

include $(BUILD_HOST_EXECUTABLE)
include $($(LOCAL_BUILT_MODULE))
