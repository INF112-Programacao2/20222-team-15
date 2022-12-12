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

#include "character.h"
#include "hero.h"

int Hero::_abacaxis = 0;

Hero::Hero(std::string name, int atk, int life, int esqv, int dx, int dy, int desloc, int pine, char di){
    _name = name;
    _atk = atk;
    _life = life;
    _maxLife = life;
    _sw = 40;
    _desloc = desloc;
    _dx = 60*dx + _desloc;
    _dy = 60*dy + 8;
    _pine = pine;
    _direcao = di;

}

Hero::~Hero(){
}

void Hero::walk(char mapa[10][10], int x, int y){
    int d = rollDice();
    int opc = 0;
    std::cout << "\n\n" <<  getName() << "\nDado: " << d << "\n";
    while(d != 0){
        if(_direcao == 'b'){
            //encrusilhada de fora
            if(getY() == 4 && getX() == 0){
                std::cout << "Bifurcacao faltam " << d << " casas para andar\n1. Baixo\n2. Direita";
                while (opc != 1 && opc !=2){
                    std::cin >> opc;
                }
                if(opc == 1){
                    setY(getY()+1);
                    d--;
                    continue;
                }
                else{
                    setX(getX()+1);
                    d--;
                    _direcao = 'd';
                    continue;
                }
            }
            //encrusilhada de dentro
            else if(getY() == 4 && getX() == 2){
                std::cout << "Bifurcacao, faltam " << d << " casas para andar\n1. Baixo\n2. Esquerda\n";
                while (opc != 1 && opc !=2){
                    std::cin >> opc;
                }
                
                if(opc == 1){
                    setY(getY()+1);
                    d--;
                    continue;
                }
                else{
                    setX(getX()-1);
                    d--;
                    _direcao = 'e';
                    continue;
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
                std::cout << "Bifurcacao, faltam " << d << " casas para andar\n1. Direita\n2. Cima\n";
                while (opc != 1 && opc !=2){
                    std::cin >> opc;
                }
                
                if(opc == 1){
                    setX(getX()+1);
                    d--;
                    continue;
                }
                else if(opc == 2){
                    setY(getY()-1);
                    d--;
                    _direcao = 'c';
                    continue;
                }
            }
            //encrusilhada de dentro
            else if(getY() == 6 && getX() == 4){
                std::cout << "Bifurcacao, faltam " << d << " casas para andar\n1. Direita\n2. Baixo\n";
                while (opc != 1 && opc !=2){
                    std::cin >> opc;
                }
                
                if(opc == 1){
                    setX(getX()+1);
                    d--;
                    continue;
                }
                else if(opc == 2){
                    setY(getY()+1);
                    d--;
                    _direcao = 'b';
                    continue;
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
                std::cout << "Bifurcacao, faltam " << d << " casas para andar\n1. Cima\n2. Esquerda\n";
                while (opc != 1 && opc !=2){
                    std::cin >> opc;
                }
                
                if(opc == 1){
                    setY(getY()-1);
                    d--;
                    continue;
                }
                else if(opc == 2){
                    setX(getX()-1);
                    d--;
                    _direcao = 'e';
                }
            }
            //encrusilhada de dentro
            else if(getY() == 4 && getX() == 6){
                std::cout << "Bifurcacao, faltam " << d << " casas para andar\n1. Cima\n2. Direita\n";
                while (opc != 1 && opc !=2){
                    std::cin >> opc;
                }
                
                if(opc == 1){
                    setY(getY()-1);
                    d--;
                    continue;
                }
                else if(opc == 2){
                    setX(getX()+1);
                    d--;
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
                std::cout << "Bifurcacao, faltam " << d << " casas para andar\n1. Esquerda\n2. Baixo\n";
                while (opc != 1 && opc !=2){
                    std::cin >> opc;
                }
                
                if(opc == 1){
                    setX(getX()-1);
                    d--;
                    continue;
                }
                else{
                    setY(getY()+1);
                    d--;
                    _direcao = 'b';
                    continue;
                }
            }
            //encrusilhada de dentro
            else if(getY() == 2 && getX() == 4){
                std::cout << "Bifurcacao, faltam " << d << " casas para andar\n1. Esquerda\n2. Cima\n";
                while (opc != 1 && opc !=2){
                    std::cin >> opc;
                }
                
                if(opc == 1){
                    setX(getX()-1);
                    d--;
                    continue;
                }
                else{
                    setY(getY()-1);
                    d--;
                    _direcao = 'c';
                    continue;
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

}


int Hero::rollDice(){
    return 1+rand()%6;
}

int Hero::attack(){
    return rollDice() + _atk;
}

void Hero::response(int atk){
    std::cout << _name << " foi atacado!" << std:: endl;
    std::cout << "Poder do ataque = " << atk << std::endl;
    
    while(true){
        std::cout << "1. Defender\n2. Esquivar" << std::endl;
        int action;
        std::cin >> action;

        if(action == 1){
            int def = defense(atk);
            _life -= (atk - def);
            std::cout << "Defendeu = " << def << "\n" << std::endl;
            break;
        }
        else if(action == 2){ 
            if(dodge(atk) == false){
                _life -= atk;
                std::cout << "Nao conseguiu esquivar\n" << std::endl;
            }
            else
                std::cout << "Esquivou\n" << std::endl;
            break;
        }
        else
            continue;
    }
}

int Hero::defense(int atk){
    int def = rollDice();
    if(def > atk){
        def = 0;
    }
    return def;
}

bool Hero::dodge(int atk){
    if(rollDice() + _esqv > atk)
        return true;
    else
        return false;
}

bool Hero::isAlive(){
    if(_life <= 0){
        _life = 0;
        setPineapple(-5);
        return false;
    }
    else
        return true;
}

//GETS E SETS
std::string Hero::getName(){
    return _name;
}

int Hero::getAtk(){
    return _atk;
}

int Hero::getLife(){
    return _life;
}
void Hero::setLife(int x){
    if(_life+x > _maxLife){
        _life = _maxLife; 
        return;
    }
    if(_life+x < 0){
        _life = 0;
        return;
    }
    _life += x;

}

int Hero::getMaxLife(){
    return _maxLife;
}

int Hero::getPosX(){
    return _dx;
}
void Hero::setPosX(int x){
    _dx + _desloc;
}

int Hero::getPosY(){
    return _dy;
}
void Hero::setPosY(int y){
   _dy;
}

int Hero::getX(){
    return (_dx - _desloc)/60;
}
void Hero::setX(int x){
    _dx = 60*x + _desloc;
    
}

int Hero::getY(){
    return _dy/60;
}
void Hero::setY(int y){
   _dy = 60*y + 8;
}

int Hero::getTam(){
    return _sw;
}

int Hero::getPineapple(){
    return _pine;
}
void Hero::setPineapple(int x){
    if(_pine + x < 0){
        _pine = 0; 
        return;
    }
    else
        _pine+=x;
}

char Hero::getDirecao(){
    return _direcao;
}
void Hero::setDirecao(char d){
    _direcao = d;
}

void Hero::somaAbacaxi(int x){
    _abacaxis +=x;
}
int Hero::getAbacaxis(){
    return _abacaxis;
}