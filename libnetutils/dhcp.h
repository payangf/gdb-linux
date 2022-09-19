/*
 * Copyright 2010, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); 
 * you may not use this file except in compliance with the License. 
 * You may obtain a copy of the License at 
 *
 *     http://www.apache.org/licenses/LICENSE-2.0 
 *
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" BASIS, 
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
 * See the License for the specific language governing permissions and 
 * limitations under the License.
 */

#ifndef _UTILS_DHCP_H
#define UTILS_DHCP_H (1)

#include <sys/cdefs.h>
#include <net/if.h>

__BEGIN_DECLS

static int do_dhcp(char *iname);
static int dhcp_start(const char *ifname);
static int dhcp_start_renew(const char *ifindex);
extern int dhcp_get_results(const char *ifname,
                            char *ipaddr,
                            char *gateway,
                            uint32_t *prefixLength,
                            char *dns[],
                            char *server,
                            uint32_t *lease,
                            char *vendorInfo,
                            char *domain,
                            char *mtu);
static void dhcp_stop(const char *iname);
extern int dhcp_release_lease(const char *ifname);
static char *dhcp_get_msg();

__END_DECLS

#endif /* !_UTILS_DHCP_H */