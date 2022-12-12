#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>

#include "character.h"

class Enemy : public CharacterIF{
    protected:
    std::string _name;
    int _life;
    int _maxLife;
    
    //COORDENADAS PIXEL
    int _dx;
    int _dy;

    public:
    Enemy();
    Enemy(std::string name, int life, int dx, int dy);
    ~Enemy();
    
    virtual std::string getName();
    virtual int getLife();
    virtual void setLife(int x);
    virtual int rollDice();
    virtual int attack();
    virtual void response(int atk);
    virtual int defense(int atk);
    virtual bool dodge(int atk);
    virtual bool isAlive();
    virtual char getDirecao();
    virtual void setDirecao(char d);
    
    //POSICAO EM PIXELS
    int getPosX();
    int getPosY();
    void setPosX(int x);
    void setPosY(int y);

    //POSICAO EM COORDENADAS
    virtual int getX();
    virtual int getY();
    virtual void setX(int x);
    virtual void setY(int y);

};

#endif