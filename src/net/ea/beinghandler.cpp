/*
 *  The ManaPlus Client
 *  Copyright (C) 2004-2009  The Mana World Development Team
 *  Copyright (C) 2009-2010  The Mana Developers
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

#include "net/ea/beinghandler.h"

#include "actormanager.h"
#include "game.h"
#include "party.h"

#include "being/localplayer.h"
#include "being/playerrelation.h"
#include "being/playerrelations.h"

#include "enums/resources/map/mapitemtype.h"

#include "gui/viewport.h"

#include "gui/windows/socialwindow.h"

#include "resources/map/map.h"

#include "net/serverfeatures.h"

#include "net/ea/beingrecv.h"

#include "debug.h"

namespace Ea
{

BeingHandler::BeingHandler(const bool enableSync)
{
    BeingRecv::mSync = enableSync;
    BeingRecv::mSpawnId = BeingId_zero;
}

}  // namespace Ea
