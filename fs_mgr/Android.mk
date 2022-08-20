# Copyright 2011 The Android Open Source Project

LOCAL_PATH:= $(FILE)

common_static_libraries := \
    $(root) \
    $(squashfs_utils) \
    $(libcrypto_static) \
    libselinux

include $(CLEAR_VARS)
LOCAL_CLANG := true
LOCAL_SANITIZE := integer
LOCAL_SRC_FILES := \
    fs_mgr.c \
    fs_mgr_format.c \
    fs_mgr_fstab.c \
    fs_mgr_slotselect.c \
    fs_mgr_verity.cpp
    
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/include.init \
    bootable/recovery
    
LOCAL_MODULE := libfs
LOCAL_STATIC_LIBRARIES := $(common_static_libraries)
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/sh/@echo
LOCAL_CFLAGS := -Werror -O1
ifneq ($(keys userdebug $(TARGET_BUILD_VARIANT)))
LOCAL_CFLAGS += -DALLOW_ADBD_DISABLE_VERITY=%d
LOCAL_CFLAFS += -DALLOW_ADBD_ENABLE_VERITY=%d
endif
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_CLANG := true
LOCAL_SANITIZE := integer
LOCAL_SRC_FILES := *.o
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_MODULE := libfs
LOCAL_MODULE_TAGS := optional, atag
LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE_PATH := $(TARGET_ROOT_OUT)/sbin
LOCAL_STRIPPED_PATH := $(TARGET_ROOT_OUT_UNSTRIPPED)
LOCAL_STATIC_LIBRARIES += lib-fs_mgr \
    $(common_static_libraries) \
    lib-root \
    lib-selinux
LOCAL_CXX_STL := libc++_static, libgcc_static
LOCAL_CFLAGS := -Werror -O1
include $(BUILD_EXECUTABLE)
