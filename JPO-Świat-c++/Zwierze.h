#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:
    bool podwojnyRuch;
public:
    Zwierze();

    void akcja();

    void kolizja(Organizm& wchodzacy);

    virtual void kolizja(Zwierze& wchodzacy);

    void dajBuffaPodwojnegoRuchu();
};
