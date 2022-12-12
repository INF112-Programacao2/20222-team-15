#ifndef HERO_H
#define HERO_H

#include <string>

#include "character.h"

class Hero : public CharacterIF{
    private:
    std::string _name;
    int _atk;
    int _life;
    int _maxLife;
    int _esqv;
    int _pine;
    char _direcao;
    static int _abacaxis;
    
    //TAMANHO DO PERSONAGEM(LARGURA E ALTURA)
    int _sw;

    //COORDENADAS PIXEL
    int _dx;
    int _dy;
    
    public:
    Hero(std::string name, int atk, int life, int esqv, int dx, int dy, int desloc, int pine, char di);
    ~Hero();
    virtual char getDirecao();
    virtual void setDirecao(char d);
    void walk(char mapa[10][10], int x, int y);

    void setPineapple(int x);
    int getPineapple();
    
    virtual std::string getName();
    virtual int getLife();
    virtual void setLife(int x);
    virtual int rollDice();
    virtual int attack();
    virtual void response(int atk);
    virtual int defense(int atk);
    virtual bool dodge(int atk);
    virtual bool isAlive();

    static void somaAbacaxi(int x);
    static int getAbacaxis();

    int getAtk();
    int getMaxLife();
    
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

    int getTam();

    int _desloc; //VARIAVEL PARA GUARDAR O TAMANHO DO PERSONAGEM NO TABULEIRO
};

#endif