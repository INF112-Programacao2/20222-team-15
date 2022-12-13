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
#include <exception>

#include "character.h"
#include "hero.h"

int Hero::_abacaxis = 0;

Hero::Hero(std::string name, int atk, int life, int def, int esqv, int dx, int dy, int desloc, int pine, char di){
    _name = name;
    _atk = atk;
    _life = life;
    _def = def;
    _esqv = esqv;
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

void Hero::walk(char mapa[10][10], int mousex, int mousey){
    /*
    setX(mousex); //PARA FACILITAR TESTES
    setY(mousey);
    */
    int d = rollDice();
    int opc = 0;
    std::cout << "~~~~~~~~~~~~\n" <<  getName() << " jogou o dado: " << d << "\n";
    int x = getX();
    int y = getY();

    while(d != 0){
        int opc = 0;
        //INDO PARA BAIXO
        if(_direcao == 'b'){
            //BIFURCACAO DE FORA
            if(y == 4 && x == 0){
                std::cout << "Faltam " << d << " casas para andar\n1. Baixo\n2. Direita\n";
                setOpcao(opc);
                if(opc == 1){
                    y += 1;
                    d--;
                    continue;
                }
                if(opc == 2){
                    _direcao = 'd';
                    x += 1;
                    d--;
                    continue;
                }
            }
            //BIFURCACAO DE DENTRO
            else if(y == 4 && x == 2){
                std::cout << "Faltam " << d << " casas para andar\n1. Baixo\n2. Esquerda\n";
                setOpcao(opc);
                if(opc == 1){
                    y += 1;
                    d--;
                    continue;
                }
                if(opc == 2){
                    _direcao = 'e';
                    x -= 1;
                    d--;
                    continue;
                }
            }
            //ENTRADA EXTERNO PRO INTERNO
            else if(y == 2 && x == 4){
                _direcao = 'e';
                x -= 1;
                d--;
                continue;
            }
            //SAIDA INTERNO PRO EXTERNO E QUINAS
            else if((y == 8 && x == 4) || y+1 > 8 || mapa[x][y+1] == 'P'){
                _direcao = 'd';
                x += 1;
                d--;
                continue;
            }
            else if(mapa[x][y+1] != 'P'){
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
                std::cout << "Faltam " << d << " casas para andar\n1. Direita\n2. Cima\n";
                setOpcao(opc);
                if(opc == 1){
                    x += 1;
                    d--;
                    continue;
                }
                if(opc == 2){
                    _direcao = 'c';
                    y -= 1;
                    d--;
                    continue;
                }
            }
            //BIFURCACAO DE DENTRO
            else if(y == 6 && x == 4){
                std::cout << "Faltam " << d << " casas para andar\n1. Direita\n2. Baixo\n";
                setOpcao(opc);
                if(opc == 1){
                    x += 1;
                    d--;
                    continue;
                }
                if(opc == 2){
                    _direcao = 'b';
                    y += 1;
                    d--;
                    continue;
                }
            }
            //ENTRADA EXTERNO PRO INTERNO
            else if(y == 4 && x == 2){
                _direcao = 'b';
                y += 1;
                d--;
                continue;
            }
            //SAIDA INTERNO PRO EXTERNO E QUINAS
            else if((y == 4 && x == 8) || x+1 > 8 || mapa[x+1][y] == 'P'){
                _direcao = 'c';
                y -= 1;
                d--;
                continue;
            }
            else if(mapa[x+1][y] != 'P'){
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
                std::cout << "Faltam " << d << " casas para andar\n1. Cima\n2. Esquerda\n";
                setOpcao(opc);
                if(opc == 1){
                    y -= 1;
                    d--;
                    continue;
                }
                if(opc == 2){
                    _direcao = 'e';
                    x -= 1;
                    d--;
                    continue;
                }
            }
            //BIFURCACAO DE DENTRO
            else if(_direcao == 'c' && y == 4 && x == 6){
                std::cout << "Faltam " << d << " casas para andar\n1. Cima\n2. Direita\n";
                setOpcao(opc);
                if(opc == 1){
                    y -= 1;
                    d--;
                    continue;
                }
                if(opc == 2){
                    _direcao = 'd';
                    x += 1;
                    d--;
                    continue;
                }
            }
            //ENTRADA EXTERNO PRO INTERNO
            else if(y == 6 && x == 4){
                _direcao = 'd';
                x += 1;
                d--;
                continue;
            }
            //SAIDA INTERNO PRO EXTERNO E QUINAS
            else if((y == 0 && x == 4) || y-1 < 0 || mapa[x][y-1] == 'P'){
                _direcao = 'e';
                x -= 1;
                d--;
                continue;
            }
            else if( mapa[x][y-1] != 'P'){
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
                std::cout << "Faltam " << d << " casas para andar\n1. Esquerda\n2. Baixo\n";
                setOpcao(opc);
                if(opc == 1){
                    x -= 1;
                    d--;
                    continue;
                }
                if(opc == 2){
                    _direcao = 'b';
                    y += 1;
                    d--;
                    continue;
                }
            }
            //BIFURCACAO DE DENTRO
            else if(y == 2 && x == 4){
                std::cout << "Faltam " << d << " casas para andar\n1. Esquerda\n2. Cima\n";
                setOpcao(opc);
                if(opc == 1){
                    x -= 1;
                    d--;
                    continue;
                }
                if(opc == 2){
                    _direcao = 'c';
                    y -= 1;
                    d--;
                    continue;
                }
            }
            //ENTRADA EXTERNO PRO INTERNO
            else if(y == 4 && x == 6){
                _direcao = 'c';
                y -= 1;
                d--;
                continue;
            }
            //SAIDA INTERNO PRO EXTERNO E QUINAS
            else if((y == 4 && x == 0) || x-1 < 0|| mapa[x-1][y] == 'P'){
                _direcao = 'b';
                y += 1;
                d--;
                continue;
            }
            else if(mapa[x-1][y] != 'P'){
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
    int def = rollDice() + _def;
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
    else
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

void Hero::setOpcao(int& opc){
    while(1){
        try{
            std::cin >> opc;
            validarOpcao(opc);
        }catch(std::invalid_argument &e){
            std::cerr << e.what() <<"\n";
            continue;
        }
        break;
    }
}

void Hero::validarOpcao(int opc){
    if(!std::cin){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw std::invalid_argument("Opcao invalida, digite apenas 1 ou 2.\n");
    }
    if(opc != 1 && opc != 2){
        throw std::invalid_argument("Opcao invalida, digite apenas 1 ou 2.\n");
    }
}