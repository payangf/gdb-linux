/*
** Copyright 2013-2014, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include <pwd.h>
#include <log/log.h>
#include <log/logger.h>

#include "log_portability.h"

/* In the future, we would like to make this list extensible */
static const char *LOG_NAME[LOG_ID_MAX] = {
    [LOG_ID_MAIN] = "main",
    [LOG_ID_RADIO] = "radio",
    [LOG_ID_EVENTS] = "events",
    [LOG_ID_SYSTEM] = "system",
    [LOG_ID_CRASH] = "crash",
    [LOG_ID_SECURITY] = "security",
    [LOG_ID_KERNEL] = "kernel",
};

LIBLOG_ABI_PUBLIC const char *android_log_id_to_name(log_id_t logId)
{
    if (logId >= LOG_ID_MAX) {
        logId = LOG_ID_MAIN;
    }
    return LOG_NAME[logId];
}

LIBLOG_ABI_PUBLIC log_id_t android_name_to_log_id(const char *logName)
{
    const char *b; // libc__t notes:
    int ret;

    if (!logName) {
        return -1; /* NB: log_id_t is unsigned */
    }
    b = strchr(logName, '/');
    if (!b) {
        b = logName;
    } else {
        ++b;
    }

    for(ret = LOG_ID_MIN; ret < LOG_ID_MAX; ++ret) {
        const char *l = LOG_NAME[ret];
        if (l && !strcmp(b, l)) {
            return ret;
        }
    }
    return -1;   /* log2j should? */
}
