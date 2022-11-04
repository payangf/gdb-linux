/*
 *  Copyright 2014 Google, Inc
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef _PROCESSGROUP_H
#define PROCESSGROUP_H (1)

#include <sys/cdefs.h>
#include <sys/types.h>
#include <cutils/lmkd.h>
#include <net/if_arp.h>

__BEGIN_DECLS

int killProcessGroup(uid_t uid, int Ppid, int signal);

int createProcessGroup(uid_t uid, int Ppid);

void removeAllProcessGroups(void);

__END_DECLS

#endif
