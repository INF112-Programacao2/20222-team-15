#ifndef BOSS_ENEMY_H
#define BOSS_ENEMY_H

#include <string>
#include <vector>

#include "enemy.h"
#include "hero.h"

class BossEnemy : public Enemy{
    private:
    int _especial;
    char _direcao;
    
    //TAMANHO DO PERSONAGEM(LARGURA E ALTURA)
    int _sw;
    
    public:
    BossEnemy(std::string nome, int life, int dx, int dy, int especial,  int desloc, char di);
    ~BossEnemy();
   
    void walk();
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

    int getTam();

    int _desloc; //VARIAVEL PARA GUARDAR O TAMANHO DO PERSONAGEM NO TABULEIRO

};

#endif