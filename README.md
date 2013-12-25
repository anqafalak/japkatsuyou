===============
**JapKatsuyou**
===============

-----------
What is it?
-----------
JapKatsuyou is a free open source application used for Japanese verb conjugation.
* It is destined for Japanese language learners, in the hope that it will simplify conjugation task.
* It can be used, also, to simplify making sentences for advanced learners, since it contains some complex forms.

-----------
Architecture
-----------
JapKatsuyou project is, actually, devided to two sub-projects: 
* LibJpConj: is a library which gives us the conjugation of a verb, knowing its dictionary form and its type, and giving conjugation tense, politeness, and polarity.
* JpConj: is the user interface which contact with the library. It uses a verb database to detect the verb's availability along with its type. 

The verb database is created from 
[The EDICT Dictionary](http://www.csse.monash.edu.au/~jwb/edict.html). 

--------
Features:
--------

version 1.0.0

The application can afford the following features:
* Search for the existence of a verb, using its dictionary form. Eg. 食べる, 飲む, 行く, etc.
* If the verb is found, shows its type. Eg. 食べる: ichidan verb.
* The verbs' database contains nouns which are used with the auxiliary verb "する". Eg. 勉強する, 選択する, 連絡する, etc.
* The user interface is translated into four languages: Arabic, English, French, and Japanese.
* The conjugation tables can be exported to three formats: pdf, odt, and htm.

--------
Authors:
--------

Check the [Authors](./Authors.rst) list  


--------
License:
--------

The JapKatsuyou project is under [GPL v3](./LICENSE) license  


-------------
Documentation
-------------

The documentation uptodate can be founded on the [FAQ file](./FAQ.rst) . 

------------
Installation
------------

See the file named [INSTALL](./INSTALL.rst) for further information.

--------
Accounts
--------

Available accounts [Sourceforge](https://sourceforge.net/projects/japkatsuyou/) ; [Launchpad](https://launchpad.net/~dzcoding/+archive/japkatsuyou).

------------
Contacts
------------

- If you have a concrete bug report please go to the [Tracker](https://github.com/DzCoding/JapKatsuyou/issues) ; submit your report and tag it "bug".

- If you want to participate in developing JapKatsuyou,by testing or by coding we invite you to read this [How to contribute?](./FAQ.rst#how-to-contribute) 

- If you want to follow the project news or you have some feedbacks, you can contact us by subscribing in our mailing list in [launchepad](https://launchpad.net/~dzcoding)

- You can also contact us on our google user group: dzgroup@googlegroup.com
