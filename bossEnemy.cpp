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

BossEnemy::~BossEnemy(){

}

void BossEnemy::walk(){
    int d = rollDice();
    std::cout << "Dado: " << d << "\n";
    while(d != 0){
        if(_direcao == 'b'){
            //encrusilhada de fora
            if(getY() == 4 && getX() == 0){
                if((1+rand()%6)%2 == 0){
                    setY(getY()+1);
                    d--;
                    continue;
                }
                else{
                    _direcao = 'd';
                }
            }
            //encrusilhada de dentro
            else if(getY() == 4 && getX() == 2){
                if((1+rand()%6)%2 == 0){
                    setY(getY()+1);
                    d--;
                    continue;
                }
                else{
                    _direcao = 'e';
                }
            }
            //entrada do quadrado externo pro interno
            else if(getY() == 2 && getX() == 4){
                _direcao = 'e';
            }
            //saida do quadrado interno pro externo
            else if(getY() == 8 && getX() == 4){
                _direcao = 'd';
            }
            //quinas
            else if((getY() == 8 && getX() == 0) || (getY() == 6 && getX() == 2)){
                _direcao = 'd';
            }

            else{
                setY(getY()+1);
                d--;
                continue;
            }
        }
        if(d == 0) break;
    
        if(_direcao == 'd'){
            //encrusilhada de fora
            if(getY() == 8 && getX() == 4){
                if((1+rand()%6)%2 == 0){
                    setX(getX()+1);
                    d--;
                    continue;
                }
                else{
                    _direcao = 'c';
                }
            }
            //encrusilhada de dentro
            else if(getY() == 6 && getX() == 4){
                if((1+rand()%6)%2 == 0){
                    setX(getX()+1);
                    d--;
                    continue;
                }
                else{
                    _direcao = 'b';
                }
            }
            //entrada do quadrado externo pro interno
            else if(getY() == 4 && getX() == 2){
                _direcao = 'b';
            }
            //saida do quadrado interno pro externo
            else if(getY() == 4 && getX() == 8){
                _direcao = 'c';
            }
            //quinas
            else if((getY() == 8 && getX() == 8) || (getY() == 6 && getX() == 6)){
                _direcao = 'c';
            }

            else{
                setX(getX()+1);
                d--;
                continue;
            }
        }

        if(d == 0) break;

        if(_direcao == 'c'){
            //encrusilhada de fora
            if(getY() == 4 && getX() == 8){
                if((1+rand()%6)%2 == 0){
                    setY(getY()-1);
                    d--;
                    continue;
                }
                else{
                    _direcao = 'e';
                }
            }
            //encrusilhada de dentro
            else if(getY() == 4 && getX() == 6){
                if((1+rand()%6)%2 == 0){
                    setY(getY()-1);
                    d--;
                    continue;
                }
                else{
                    _direcao = 'd';
                }
            }
            //entrada do quadrado externo pro interno
            else if(getY() == 6 && getX() == 4){
                _direcao = 'd';
            }
            //saida do quadrado interno pro externo
            else if(getY() == 0 && getX() == 4){
                _direcao = 'e';
            }
            //quinas
            else if((getY() == 0 && getX() == 8) || (getY() == 2 && getX() == 6)){
                _direcao = 'e';
            }
            
            else{
                setY(getY()-1);
                d--;
                continue;
            }
        }

        if(d == 0) break;

        if(_direcao == 'e'){
            //encrusilhada de fora
            if(getY() == 0 && getX() == 4){
                if((1+rand()%6)%2 == 0){
                    setX(getX()-1);
                    d--;
                    continue;
                }
                else{
                    _direcao = 'b';
                }
            }
            //encrusilhada de dentro
            else if(getY() == 2 && getX() == 4){
                if((1+rand()%6)%2 == 0){
                    setX(getX()-1);
                    d--;
                    continue;
                }
                else{
                    _direcao = 'c';
                }
            }
            //entrada do quadrado externo pro interno
            else if(getY() == 6 && getX() == 4){
                _direcao = 'c';
            }
            //saida do quadrado interno pro externo
            else if(getY() == 4 && getX() == 0){
                _direcao = 'b';
            }
            //quinas
            else if((getY() == 0 && getX() == 0) || (getY() == 6 && getX() == 2)){
                _direcao = 'b';
            }
            
            else{
                setX(getX()-1);
                d--;
                continue;
            }
        }
        if(d == 0) break;
    }

    /*while(d != 0){
        if(getY() == 4 && getX() == 0){
            if((1+rand()%6)%2 == 0)
                setY(getY()+1);
            else
                setX(getX()+2);
            d--;
        }
        if(getY() == 4 && getX() == 2){
            setX(getX()+1);
            d--;
        }
        if(getX()== 0 && getY() < 8){
            setY(getY()+1);
            d--;
        }
        else if(getX() < 8 && getY() == 8){
            setX(getX()+1);
            d--;
        }
        else if(getY() == 0 && getX() > 0){
            setX(getX()-1);
            d--;
        }
        else if(getY() < 8 && getX() == 8){
            setY(getY()-1);
            d--;
        }

        if(d == 0) break;
    }*/
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