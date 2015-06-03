/*
 *  The ManaPlus Client
 *  Copyright (C) 2011-2015  The ManaPlus Developers
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

#ifndef NET_PACKETLIMITER_H
#define NET_PACKETLIMITER_H

#include "enums/net/packettype.h"

#include <string>

#include "localconsts.h"

namespace PacketLimiter
{
    void initPacketLimiter();

    void writePacketLimits(const std::string &packetLimitsName);

    bool limitPackets(const PacketTypeT type) A_WARN_UNUSED;

    bool checkPackets(const PacketTypeT type) A_WARN_UNUSED;
}

#endif  // NET_PACKETLIMITER_H
