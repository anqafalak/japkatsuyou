===============
**DataBases**
===============
There are two databases:
* edict2verbs.db: contains Japanese verbs
* tatoeba.db: contains examples from [tatoeba.org](http://tatoeba.org/eng/).
-----------
edict2verbs
-----------
To generate this database, please refer to the project [KInfoMiner](https://github.com/kariminf/KInfoMiner). It is written using Java.
The class used to generate it is:
KInfoMiner/test/kariminf/kinfominer/edict2/VerbExtract.java

To get edict2 dictionary, please follow this link http://www.edrdg.org/jmdict/edict.html

-----------
tatoeba.db
-----------
To generate it, we used some python scripts: [See scripts here](../../../scripts/tatoeba/).
