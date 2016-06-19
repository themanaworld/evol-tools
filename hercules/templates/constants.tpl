//================= Hercules Database =====================================
//=       _   _                     _
//=      | | | |                   | |
//=      | |_| | ___ _ __ ___ _   _| | ___  ___
//=      |  _  |/ _ \ '__/ __| | | | |/ _ \/ __|
//=      | | | |  __/ | | (__| |_| | |  __/\__ \
//=      \_| |_/\___|_|  \___|\__,_|_|\___||___/
//================= License ===============================================
//= This file is part of Hercules.
//= http://herc.ws - http://github.com/HerculesWS/Hercules
//=
//= Copyright (C) 2016  Hercules Dev Team
//=
//= Hercules is free software: you can redistribute it and/or modify
//= it under the terms of the GNU General Public License as published by
//= the Free Software Foundation, either version 3 of the License, or
//= (at your option) any later version.
//=
//= This program is distributed in the hope that it will be useful,
//= but WITHOUT ANY WARRANTY; without even the implied warranty of
//= MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//= GNU General Public License for more details.
//=
//= You should have received a copy of the GNU General Public License
//= along with this program.  If not, see <http://www.gnu.org/licenses/>.
//=========================================================================
//= Script Constants Database
//=========================================================================

constants_db: {
/************* Entry structure (short) ************************************
	Identifier: value            // (int)
 ************* Entry structure (full) *************************************
	Identifier: {
		Value: value         // (int)
		Parameter: true      // (boolean)      Defaults to false.
		Deprecated: true     // (boolean)      Defaults to false.
	}
**************************************************************************/
// NOTE:
//   Parameters are special in that they retrieve certain runtime values
//   depending on the specified ID in field Value. Depending on the
//   implementation values assigned by scripts to parameters will affect
//   runtime values, such as Zeny, as well (see pc_readparam/pc_setparam).

