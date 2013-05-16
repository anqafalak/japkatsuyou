#ifndef VERBTIME_H
#define VERBTIME_H

class verbTime
{
public:
    static const int _TeForm             = 0; // no polite form
    static const int _Present            = 1; // る、　ます
    static const int _Past               = 2; // た、ました
    static const int _Provision          = 3; // ば
    static const int _Condition          = 4; // ta＋ら
    static const int _Imperative         = 5; // え、ろ
    static const int _Lets               = 6; // おう、ましょう
    static const int _PresentContinuous  = 7; // te + いる
    static const int _PastContinuous     = 8; // te + いる
    static const int _Desire             = 9; // i + たい
    static const int _WhileDoing         = 10; // ながら
    static const int _WayOfDoing         = 11; // かた・方
    static const int _Passive            = 12; // a＋れる a＋られる
    static const int _Causative          = 13; // a＋せる a＋させる
    static const int _CausativePassive   = 14; // a＋せられる a＋させられる
    static const int _Potential          = 15; // e＋る e＋られる
    static const int _Raison             = 16; // ta＋から
};

#endif // VERBTIME_H
