#ifndef BOARD_H
#define BOARD_H

#include "character.h"
#include "hero.h"
#include "bossEnemy.h"

class Board{
    public:
    Board();
    ~Board();
    void isQualCasaHero(Hero& h, char mapa[10][10]);
    void isQualCasaBoss(BossEnemy& b, char mapa[10][10]);
    void isCasaEnemy(Hero& h);
    void isCasaWarp(CharacterIF& c);
    void isCasaDropPineapples(Hero& h);
    void isCasaGetBonus(Hero& h);
    void isCasaDeMimir(Hero& h);

    void battle(CharacterIF& atkr, CharacterIF& defdr);
    void revive(Hero& h);

};
#endif