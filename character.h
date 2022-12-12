#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class CharacterIF{
    public:
    virtual std::string getName() = 0;
    virtual int getLife() = 0;
    virtual void setLife(int x) = 0;
    virtual int rollDice() = 0;
    virtual int attack() = 0;
    virtual void response(int atk) = 0;
    virtual int defense(int atk) = 0;
    virtual bool dodge(int atk) = 0;
    virtual bool isAlive() = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual void setX(int x) = 0;
    virtual void setY(int y) = 0;
    virtual char getDirecao() = 0;
    virtual void setDirecao(char d) = 0;
};

#endif