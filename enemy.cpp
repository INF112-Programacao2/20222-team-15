#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "character.h"
#include "enemy.h"

Enemy::Enemy(){}

Enemy::Enemy(std::string name, int life, int dx, int dy){
    _name = name;
    _life = life;
    _maxLife = life;
    _dx = dx;
    _dy = dy;
}
Enemy::~Enemy(){

}

int Enemy::rollDice(){
    return 1+rand()%6;
}

int Enemy::attack(){
    //PARA VER SE A DEFESA FICA UTIL
    if((1+rand()%6)%2 == 0)
        return rollDice()+1;
    else
        return rollDice();
}

void Enemy::response(int atk){
    std::cout << _name << " foi atacado!" << std:: endl;
    std::cout << "Poder do ataque = " << atk << std::endl;
    
        if(atk > (_life/2)+1){
            int def = defense(atk);
            _life -= (atk - def);
            std::cout << "Defendeu: " << def << "\n" << std::endl;
        }
        else{
            if(dodge(atk) == false){
                _life -= atk;
                std::cout << "Nao conseguiu esquivar\n" << std::endl;
            }
            else
                std::cout << "Esquivou\n" << std::endl;
        }
}

int Enemy::defense(int atk){
    int def = rollDice();
    if(def > atk)
        def = 0;
    return def;
}

bool Enemy::dodge(int atk){
    if(rollDice() > atk)
        return true;
    else
        return false;
}

bool Enemy::isAlive(){
    if(_life <= 0){
        _life = 0;
        return false;
    }
    else
        return true;
}

//GETS E SETS
std::string Enemy::getName(){
    return _name;
}

int Enemy::getLife(){
    return _life;
}

void Enemy::setLife(int x){
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

int Enemy::getPosX(){
    return _dx;
}
void Enemy::setPosX(int x){
    _dx;
    
}

int Enemy::getPosY(){
    return _dy;
}
void Enemy::setPosY(int y){
   _dy;
}

int Enemy::getX(){
    return (_dx)/60;
}
void Enemy::setX(int x){
    _dx = 60*x;
    
}

int Enemy::getY(){
    return _dy/60;
}
void Enemy::setY(int y){
   _dy = 60*y;
}

char Enemy::getDirecao(){}
void Enemy::setDirecao(char d){}
