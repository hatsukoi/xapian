/** @file brass_lazytable.h
 * @brief Subclass of BrassTable for deriving lazy tables from.
 */
/* Copyright (C) 2009,2010 Olly Betts
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

#ifndef XAPIAN_INCLUDED_BRASS_LAZYTABLE_H
#define XAPIAN_INCLUDED_BRASS_LAZYTABLE_H

#include "brass_table.h"

class BrassLazyTable : public BrassTable {
  public:
    /** Create a new lazy table.
     *
     *  @param name_		The table's name.
     *  @param path_		The path for the table.
     *  @param readonly_    true if we're opening read-only, else false.
     *  @param compress_    true (or COMPRESS) to zlib compress tags; false (or
     *			    DONT_COMPRESS not to).
     */
    BrassLazyTable(const char * name_, const std::string & path_, bool readonly_,
		   bool compress_)
	: BrassTable(name_, path_, readonly_, compress_, LAZY) { }

    /** Lazy version of BrassTable::create().
     *
     *  This method isn't virtual, but we never call it such that it needs to
     *  be.
     *
     *  @param blocksize_	The blocksize to use for this table.
     *  @param from_scratch	True if this table is know to not be present
     *				already (e.g. because the parent directory
     *				was just created).
     */
    void create(unsigned int blocksize_, bool from_scratch) {
	// This table is created lazily, so if we didn't just create the
	// parent directory, erase it in case we're overwriting an existing
	// database which has this table.
	if (!from_scratch)
	    BrassTable::erase();
	BrassTable::set_block_size(blocksize_);
    }
};

#endif // XAPIAN_INCLUDED_BRASS_LAZYTABLE_H