/*
 *  The ManaPlus Client
 *  Copyright (C) 2017  The ManaPlus Developers
 *
 *  This file is part of The ManaPlus Client.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UTILS_ZIP_H
#define UTILS_ZIP_H
#ifndef USE_PHYSFS

#include "localconsts.h"

#include <string>

struct VirtZipEntry;
struct ZipLocalHeader;

namespace Zip
{
    bool readArchiveInfo(VirtZipEntry *const entry);
    std::string getZlibError(const int err);
    void reportZlibError(const std::string &text,
                         const int err);
    uint8_t *readCompressedFile(const ZipLocalHeader *restrict const header);
    uint8_t *readFile(const ZipLocalHeader *restrict const header);
}  // namespace Zip

#endif  // USE_PHYSFS
#endif  // UTILS_ZIP_H
