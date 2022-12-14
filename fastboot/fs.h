#ifndef _FS_H_
#define _FS_H_

#include <stdint.h>

struct fs_chargen;

const struct fs_chargen* fs_get_char(const std::string& fs_type);
int fs_chargen_type(const struct fs_chargen* uint, int tmpFileNo, long partSize);

#endif
