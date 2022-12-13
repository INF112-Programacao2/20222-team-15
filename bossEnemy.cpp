#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include <allegro5/allegro_image.h>

#include <iostream>
#include <string>
#include <time.h>

#include "enemy.h"
#include "bossEnemy.h"
#include "character.h"
#include "hero.h"
#include "board.h"

BossEnemy::BossEnemy(std::string nome, int life, int dx, int dy, int especial,  int desloc, char di) :
    Enemy(nome, life, dx, dy), _especial(especial), _sw(40), _desloc(desloc), _direcao(di){}

BossEnemy::~BossEnemy(){}

void BossEnemy::walk(char mapa[10][10]){
    int d = rollDice();
    std::cout << "~~~~~~~~~~~~\n" <<  getName() << " jogou o dado: " << d << "\n";
    int x = getX();
    int y = getY();

    while(d != 0){
        //INDO PARA BAIXO
        if(_direcao == 'b'){
            //BIFURCACAO DE FORA
            if(y == 4 && x == 0){
                if((1+rand()%6)%2 == 0){
                    y += 1;
                    d--;
                    continue;
                }
                else{
                    _direcao = 'd';
                    x += 1;
                    d--;
                    continue;
                }
            }
            //BIFURCACAO DE DENTRO  *****ELE ÀS VEZES DESAPARECE QUANDO ESTA SOBRE AS CASAS (4,2) E (3,2), NA TEORIA ELE ESTA LA JA QUE QUANDO SAI REAPARECE ONDE DEVERIA (???)
            if(y == 4 && x == 2){
                if((1+rand()%6)%2 == 0){
                    y += 1;
                    d--;
                    continue;
                }
                else{
                    _direcao = 'e';
                    x -= 1;
                    d--;
                    continue;
                }
            }
            //ENTRADA EXTERNO PRO INTERNO
            if(y == 2 && x == 4){
                _direcao = 'e';
                x -= 1;
                d--;
                continue;
            }
            //SAIDA INTERNO PRO EXTERNO E QUINAS
            if((y == 8 && x == 4) || y+1 > 8 || mapa[x][y+1] == 'P'){
                _direcao = 'd';
                x += 1;
                d--;
                continue;
            }
            else{
                y += 1;
                d--;
                continue;
            }
            if(d == 0) break;
        }

        //INDO PARA DIREITA
        if(_direcao == 'd'){
            //BIFURCACAO DE FORA
            if(y == 8 && x == 4){
                if((1+rand()%6)%2 == 0){
                    x += 1;
                    d--;
                    continue;
                }
                else{
                    _direcao = 'c';
                    y -= 1;
                    d--;
                    continue;
                }
            }
            //BIFURCACAO DE DENTRO
            if(y == 6 && x == 4){
                if((1+rand()%6)%2 == 0){
                    x += 1;
                    d--;
                    continue;
                }
                else{
                    _direcao = 'b';
                    y += 1;
                    d--;
                    continue;
                }
            }
            //ENTRADA EXTERNO PRO INTERNO
            if(y == 4 && x == 2){
                _direcao = 'b';
                y += 1;
                d--;
                continue;
            }
            //SAIDA INTERNO PRO EXTERNO E QUINAS
            if((y == 4 && x == 8) || x+1 > 8 || mapa[x+1][y] == 'P'){
                _direcao = 'c';
                y -= 1;
                d--;
                continue;
            }
            else{
                x += 1;
                d--;
                continue;
            }
            if(d == 0) break;
        }

        //INDO PARA CIMA
        if(_direcao == 'c'){
            //BIFURCACAO DE FORA
            if(y == 4 && x == 8){
                if((1+rand()%6)%2 == 0){
                    y -= 1;
                    d--;
                    continue;
                }
                else{
                    _direcao = 'e';
                    x -= 1;
                    d--;
                    continue;
                }
            }
            //BIFURCACAO DE DENTRO
            if(y == 6 && x == 4){
                if((1+rand()%6)%2 == 0){
                    y -= 1;
                    d--;
                    continue;
                }
                else{
                    _direcao = 'd';
                    x += 1;
                    d--;
                    continue;
                }
            }
            //ENTRADA EXTERNO PRO INTERNO
            if(y == 6 && x == 4){
                _direcao = 'd';
                x += 1;
                d--;
                continue;
            }
            //SAIDA INTERNO PRO EXTERNO E QUINAS
            if((y == 0 && x == 4) || y-1 < 0 || mapa[x][y-1] == 'P'){
                _direcao = 'e';
                x -= 1;
                d--;
                continue;
            }
            else{
                y-= 1;
                d--;
                continue;
            }
            if(d == 0) break;
        }

        //INDO PARA ESQUERDA
        if(_direcao == 'e'){
            //BIFURCACAO DE FORA
            if(y == 0 && x == 4){
                if((1+rand()%6)%2 == 0){
                    x -= 1;
                    d--;
                    continue;
                }
                else{
                    _direcao = 'b';
                    y += 1;
                    d--;
                    continue;
                }
            }
            //BIFURCACAO DE DENTRO
            if(y == 2 && x == 4){
                if((1+rand()%6)%2 == 0){
                    x -= 1;
                    d--;
                    continue;
                }
                else{
                    _direcao = 'c';
                    y -= 1;
                    d--;
                    continue;
                }
            }
            //ENTRADA EXTERNO PRO INTERNO
            if(y == 6 && x == 4){
                _direcao = 'c';
                y -= 1;
                d--;
                continue;
            }
            //SAIDA INTERNO PRO EXTERNO E QUINAS
            if((y == 4 && x == 0) || x-1 < 0|| mapa[x][y] == 'P'){
                _direcao = 'b';
                y += 1;
                d--;
                continue;
            }
            else{
                x -= 1;
                d--;
                continue;
            }
            if(d == 0) break;
        }
    }
    setX(x);
    setY(y);
}

//GETS E SETS
int BossEnemy::getPosX(){
    return _dx;
}
void BossEnemy::setPosX(int x){
    _dx + _desloc;
}

int BossEnemy::getPosY(){
    return _dy;
}
void BossEnemy::setPosY(int y){
   _dy;
}

int BossEnemy::getX(){
    return (_dx - _desloc)/60;
}
void BossEnemy::setX(int x){
    _dx = 60*x + _desloc;
}

int BossEnemy::getY(){
    return _dy/60;
}
void BossEnemy::setY(int y){
   _dy = 60*y + 8;
}

int BossEnemy::getTam(){
    return _sw;
}
char BossEnemy::getDirecao(){
    return _direcao;
}
void BossEnemy::setDirecao(char d){
    _direcao = d;
}