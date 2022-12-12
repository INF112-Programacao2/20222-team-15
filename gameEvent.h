#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include <allegro5/allegro_image.h>

#include "character.h"
#include "hero.h"
#include "enemy.h"
#include "bossEnemy.h"
#include "board.h"

class GameEvent{
    ALLEGRO_BITMAP *bitmap;
    ALLEGRO_BITMAP *batalhaTRet;
    ALLEGRO_FONT *fonte;
    ALLEGRO_COLOR branco;
///////////////////////////////////////////////////////////////////
	Hero BR;
	Hero Ari;
	Hero Jeff;
	Hero Cadu;
    BossEnemy Cuadrado;
    Enemy T_Ret;
    Board tabuleiro;

    public:
    GameEvent();
    void atualizaDisplay();
    void turn(int t);
    void battle(CharacterIF& atkr, CharacterIF& defdr);
};

#endif