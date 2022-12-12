#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include <allegro5/allegro_image.h>
#include <allegro5/mouse.h>

#include "gameEvent.h"
#include "character.h"
#include "hero.h"
#include "enemy.h"
#include "bossEnemy.h"
#include "board.h"

GameEvent::GameEvent(){
    bitmap = al_load_bitmap("mapa.bmp");
    batalhaTRet = al_load_bitmap("batalhaTRet.bmp");
    fonte = al_load_font("arial.ttf", 40, 0);
    branco = al_map_rgb(255, 255, 255);
///////////////////////////////////////////////////////////////////
	Hero BR("Big Robinho", 0, 5, 1, 2, 2, 10);
	Hero Ari("Ari", 2, 3, 2, 2, 6, 20);
	Hero Jeff("Jeff??", 1, 5, 3, 6, 2, 30);
	Hero Cadu("Cadu", -1, 4, 4, 6, 6, 40);
    BossEnemy Cuadrado("Cuadrado", 50, 5, 4, 2, 50);
    Cuadrado.setX(0);
    Cuadrado.setY(0);
    Enemy T_Ret("T-Ret", 4, 0, 0);
    Board tabuleiro;
}

void GameEvent::atualizaDisplay(){
    const char *hpBR = std::to_string(BR.getLife()).c_str();
    const char *hpAri = std::to_string(Ari.getLife()).c_str();
    const char *hpJeff = std::to_string(Jeff.getLife()).c_str();
    const char *hpCadu = std::to_string(Cadu.getLife()).c_str();
    const char *hpCuadrado = std::to_string(Cuadrado.getLife()).c_str();
            
    al_draw_bitmap_region(bitmap, 0, 0, 1068, 710, 0, 0, 0);
            
    //DESENHA OS HEROIS NO MAPA
    al_draw_line(BR.getPosX(), BR.getPosY(), BR.getPosX(), BR.getPosY() + BR.getTam(), al_map_rgb(255, 0, 0), 6);
    al_draw_line(Ari.getPosX(), Ari.getPosY(), Ari.getPosX(), Ari.getPosY() + Ari.getTam(), al_map_rgb(255, 0, 255), 6);
    al_draw_line(Jeff.getPosX(), Jeff.getPosY(), Jeff.getPosX(), Jeff.getPosY() + Jeff.getTam(), al_map_rgb(0, 0, 255), 6);
    al_draw_line(Cadu.getPosX(), Cadu.getPosY(), Cadu.getPosX(), Cadu.getPosY() + Cadu.getTam(), al_map_rgb(16, 189, 2), 6);
    al_draw_line(Cuadrado.getPosX(), Cuadrado.getPosY(), Cuadrado.getPosX(), Cuadrado.getPosY() + Cuadrado.getTam(), al_map_rgb(20, 20, 20), 6);

    //DESENHA CONTADORES DE VIDA
    al_draw_text(fonte, branco, 620, 10, 0, hpBR);
    al_draw_text(fonte, branco, 620, 165, 0, hpAri);
    al_draw_text(fonte, branco, 882, 10, 0, hpJeff);
    al_draw_text(fonte, branco, 882, 165, 0, hpCadu);
    al_draw_text(fonte, branco, 569, 334, 0, hpCuadrado);
}

void GameEvent::turn(int t){

}
void GameEvent::battle(CharacterIF& atkr, CharacterIF& defdr){
    int atk = atkr.attack();
    defdr.response(atk);
    if(defdr.isAlive() == false)
        return;
    atk = defdr.attack();
    atkr.response(atk);
}
