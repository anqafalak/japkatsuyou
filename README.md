jpconjug
========


A library used to conjugate Japanese verbs. The repo contains the library project and the application project.

1- Library project (libconj)
----------------------------

It contains the library code, witch export one external function: conj.

QString conj(QString verb, int type, int time, bool polite, bool positive);

verb: the verb in dictionary form.
type: type of the verb (Ichidan, Godan, etc.), there is a class containg constants' definition in both library and appliction.
time: conjugation time or form (present, past, condition, etc.) there are constants defining these constnts in both projects.
polite: defining if the conjugation is in polite form or not.
positive: define if the verb is positive (e.g. "Go") or negative (e.g. "Don't go")

2- Application project (jpconj)
-------------------------------

It contains an example on how to use the library. Also it contains some classes to connect with the library.
