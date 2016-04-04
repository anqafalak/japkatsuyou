#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  create.py
#  Used to create the database from tatoeba database
#  
#  Copyright 2016 Abdelkrime Aries <kariminfo0@gmail.com>
#  
#  ---- AUTHORS ----
#  2016    Abdelkrime Aries <kariminfo0@gmail.com>
#  
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Affero General Public License as
#  published by the Free Software Foundation, either version 3 of the
#  License, or (at your option) any later version.
# 
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Affero General Public License for more details.
# 
#  You should have received a copy of the GNU Affero General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#  

import sys
import os
import codecs
from db.litebase import liteBase, liteINTEGER, liteVARCHAR
from db.litebase import liteTable

if __name__ == '__main__':
	
	path = os.path.realpath("tatoeba.db")
	tatodb = liteBase(path)
	linksTable = liteTable()
	if not tatodb.containsTable("links"):
		linksTable.beginTable("links")
		linksTable.addColumn('jpnId', liteINTEGER(), u'', True)
		linksTable.addColumn('id', liteINTEGER(), u'', False)
		linksTable.endTable()
		tatodb.addTable(linksTable)
	else:
		linksTable = tatodb.getTable("links")
	
	f = codecs.open("links.csv", "r", "utf-8")
	lastskip = "0"

	jpnTable = tatodb.getTable('jpn')
	i = 0
	for line in f:
		e = line.split("\t");
		if len(e) < 2:
			continue
		if e[0] == lastskip:
			continue
		
		rows = jpnTable.getData(["id = %s" % e[0]])

		if rows == None or rows.fetchone() == None:
			lastskip = e[0]
			print "skip %s" % e[0]
			continue
		
		print "write %s and %s" % (e[0], e[1])
		data = u'%s, %s' % (e[0],e[1])
		linksTable.insertData(data, u'jpnId, id')
		i = i + 1
		if i >= 1000:
			tatodb.commit() 
			i=0
	tatodb.commit()
