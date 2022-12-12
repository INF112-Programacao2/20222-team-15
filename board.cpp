#include <iostream>

#include "board.h"
#include "character.h"
#include "hero.h"
#include "enemy.h"
#include "bossEnemy.h"

Board::Board(){
}

Board::~Board(){}

void Board::isQualCasaHero(Hero& h, char mapa[10][10]){
    if(mapa[h.getX()][h.getY()] == 'V'){
        isCasaEnemy(h);
    }
    else if(mapa[h.getX()][h.getY()] == 'R'){
        isCasaWarp(h);
    }
    else if(mapa[h.getX()][h.getY()] == 'L'){
        isCasaDropPineapples(h);
    }
    else if(mapa[h.getX()][h.getY()] == 'A'){
        isCasaGetBonus(h);
    }
    else if(mapa[h.getX()][h.getY()] == 'C'){
        isCasaDeMimir(h);
    }
}

void Board::isQualCasaBoss(BossEnemy& b, char mapa[10][10]){
    if(mapa[b.getX()][b.getY()] == 'R') {isCasaWarp(b);}
}

void Board::isCasaEnemy(Hero& h){
    Enemy T_Ret("T-Ret", 4, 0, 0);
    battle(T_Ret, h);
}
void Board::isCasaWarp(CharacterIF& c){
    c.setX(8 - c.getX());
    c.setY(8 - c.getY());
    if(c.getDirecao() == 'd'){
        c.setDirecao('e');
        return;
    }
    if(c.getDirecao() == 'e'){
        c.setDirecao('d');
        return;
    }
    if(c.getDirecao() == 'c'){
        c.setDirecao('b');
        return;
    }
    if(c.getDirecao() == 'b'){
        c.setDirecao('c');
        return;
    }
}
void Board::isCasaDropPineapples(Hero& h){
    h.setPineapple(-3);
}
void Board::isCasaGetBonus(Hero& h){
    h.setPineapple(4);
}
void Board::isCasaDeMimir(Hero& h){
    h.setLife(h.getMaxLife());
    if(h.getPineapple() >=7){
        h.somaAbacaxi(h.getPineapple());
        h.setPineapple(-50);
    }
}

void Board::battle(CharacterIF& atkr, CharacterIF& defdr){
    std::cout << "\n\n";
    int atk = atkr.attack();
    defdr.response(atk);
    if(!defdr.isAlive()){
        return;
    }
    else{
        atk = defdr.attack();
        atkr.response(atk);
    }
}

void Board::revive(Hero& h){
    h.setLife(h.getMaxLife()/2);
}