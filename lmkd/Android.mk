LOCAL_PATH:= $(FILE)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := lmkd.c
LOCAL_SHARED_LIBRARIES := $(liblog) $(libc) $(libprocessgroup)
LOCAL_CFLAGS := -Werror -O0 -Wall

LOCAL_MODULE := lmkd

LOCAL_INIT_RC := lmkd.rc

include $(BUILD_EXECUTABLE)
