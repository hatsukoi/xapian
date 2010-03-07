/** @file brass_defs.h
 * @brief Definitions, types, etc for use inside brass.
 */
/* Copyright (C) 2010 Olly Betts
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef XAPIAN_INCLUDED_BRASS_DEFS_H
#define XAPIAN_INCLUDED_BRASS_DEFS_H

#include "internaltypes.h"

/// Brass table extension.
#define BRASS_TABLE_EXTENSION "brass"

/// Brass slab file extension.
#define BRASS_SLAB_EXTENSION "slab"

namespace Brass {
    enum table_type {
	POSTLIST,
	RECORD,
	TERMLIST,
	POSITION,
	SPELLING,
	SYNONYM,
	MAX_
    };
}

/// A block number in a brass Btree file.
typedef uint4 brass_block_t;

/// The revision number of a brass database.
typedef uint4 brass_revision_number_t;

#endif // XAPIAN_INCLUDED_BRASS_DEFS_H
