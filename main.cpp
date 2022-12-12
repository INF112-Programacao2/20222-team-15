#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include <allegro5/allegro_image.h>
#include <allegro5/mouse.h>

#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>

#include "character.h"
#include "hero.h"
#include "enemy.h"
#include "bossEnemy.h"
#include "board.h"

char mapa[10][10] = {
        //v = vermelho, r = roxo, b = branco, a = amarelo, l = laranja, p = preto, c = ciano
        "VRBBVBABR",
        "RPPPLPPPA",
        "APCLBVCPV",
        "BPVPPPVPB",
        "ALBPPPBLA",
        "BPVPPPVPB",
        "VPCVBLCPA",
        "APPPLPPPR",
        "RBABVBBRV",
};

const float FPS = 100;
const int SCREEN_W = 1068;
const int SCREEN_H = 720;
const int TAM_CASA = 60;

int main(){
    //    INICIALIZA TELA, FILA E TIMER   //
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
        
    //INICIA ALLEGRO
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	
    //INICIA PRIMITIVAS
    if(!al_init_primitives_addon()){
		fprintf(stderr, "failed to initialize primitives!\n");
        return -1;
    }	
	
	//INICIA MODULO DE CARREGAR IMAGEM
	if(!al_init_image_addon()){
		fprintf(stderr, "failed to initialize image module!\n");
		return -1;
	}
   
	//CRIA TEMPORIZADOR
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
 
	//CRIA TELA (LARGURA, ALTURA) EM PIXELS
	display = al_create_display(SCREEN_W, SCREEN_H);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize keyboard!\n");
		return -1;
	}

	if(!al_install_mouse()) {
		fprintf(stderr, "failed to initialize mouse!\n");
		return -1;
	}

    al_init_font_addon();
	//INICIA MODULO QUE INTERPRETA FONTES TFF
	if(!al_init_ttf_addon()) {
		fprintf(stderr, "failed to load tff font module!\n");
		return -1;
	}

 	//CRIA FILA DE EVENTOS
	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
    
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());  	
	al_register_event_source(event_queue, al_get_keyboard_event_source());  	

	ALLEGRO_BITMAP *bitmap = al_load_bitmap("mapa.bmp");
    ALLEGRO_BITMAP *batalhaTRet = al_load_bitmap("batalhaTRet.bmp");
    ALLEGRO_FONT *fonte = al_load_font("arial.ttf", 40, 0);
    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);
///////////////////////////////////////////////////////////////////
	Hero BR("Big Robinho", 0, 5, 0, 2, 2, 10, 0, 'b');
	Hero Ari("Ari", 2, 3, 3, 2, 6, 20, 0, 'd');
	Hero Jeff("Jeff??", 1, 5, 1, 6, 2, 30, 0, 'e');
	Hero Cadu("Cadu", -1, 4, 0, 6, 6, 40, 0, 'c');
    BossEnemy Cuadrado("Cuadrado", 40, 5, 4, 2, 50, 'b');
    Cuadrado.setX(0);
    Cuadrado.setY(0);
    Enemy T_Ret("T-Ret", 4, 0, 0);
    Board tabuleiro;
	int auxCharacter = 0;
	bool ganhou = false;

	//TEMPORIZADOR
    al_start_timer(timer);
	srand(time(NULL));

	int emJogo = 1;
	while(emJogo) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
        //al_clear_to_color(al_map_rgb(0, 0, 0));
        
        const char *hpBR = std::to_string(BR.getLife()).c_str();
        const char *hpAri = std::to_string(Ari.getLife()).c_str();
        const char *hpJeff = std::to_string(Jeff.getLife()).c_str();
        const char *hpCadu = std::to_string(Cadu.getLife()).c_str();
        const char *hpCuadrado = std::to_string(Cuadrado.getLife()).c_str();

		const char *contAbacaxi = std::to_string(BR.getAbacaxis()).c_str();
		const char *abacaxiBR = std::to_string(BR.getPineapple()).c_str();
        const char *abacaxiAri = std::to_string(Ari.getPineapple()).c_str();
        const char *abacaxiJeff = std::to_string(Jeff.getPineapple()).c_str();
        const char *abacaxiCadu = std::to_string(Cadu.getPineapple()).c_str();
            
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
        al_draw_text(fonte, al_map_rgb(255, 0, 0), 957, 330, 0, hpCuadrado);
		al_draw_text(fonte, al_map_rgb(0, 0, 0), 615, 410, 0, contAbacaxi);
		al_draw_text(fonte, branco, 734, 101, 0, abacaxiBR);
        al_draw_text(fonte, branco, 734, 255, 0, abacaxiAri);
        al_draw_text(fonte, branco, 990, 101, 0, abacaxiJeff);
        al_draw_text(fonte, branco, 990, 255, 0, abacaxiCadu);
        
        al_flip_display();
        
		
		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			emJogo = 0;
		}
		if(BR.getAbacaxis() == 40) {
			ganhou = true;
			emJogo = 0;
			break;
		}
		if(Cuadrado.getLife() == 0) {
			ganhou = true;
			emJogo = 0;
			
		}
		if(BR.getLife() == 0 && Ari.getLife() == 0 && Jeff.getLife() == 0 && Cadu.getLife() == 0) {
			ganhou = false;
			emJogo = 0;
			
		}
        
		if(auxCharacter == 0){
			if(!BR.isAlive()){
				auxCharacter=1;
				continue;
			}
			if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if(ev.mouse.x <= 548 && ev.mouse.y <=548){ 
					BR.walk(mapa, ev.mouse.x/60, ev.mouse.y/60);
					tabuleiro.isQualCasaHero(BR, mapa);
					if(BR.getX() == Ari.getX() && BR.getY() == Ari.getY() && !Ari.isAlive()) tabuleiro.revive(Ari);
					if(BR.getX() == Jeff.getX() && BR.getY() == Jeff.getY() && !Jeff.isAlive()) tabuleiro.revive(Jeff);
					if(BR.getX() == Cadu.getX() && BR.getY() == Cadu.getY() && !Cadu.isAlive()) tabuleiro.revive(Cadu);

				}

				auxCharacter=1;
			}

		}

		else if(auxCharacter == 1){
			if(!Ari.isAlive()){
				auxCharacter=2;
				continue;
			}
			if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if(ev.mouse.x <= 548 && ev.mouse.y <=548){              
                	Ari.walk(mapa, ev.mouse.x/60, ev.mouse.y/60);
					tabuleiro.isQualCasaHero(Ari, mapa);
					if(Ari.getX() == BR.getX() && Ari.getY() == BR.getY() && !BR.isAlive()) tabuleiro.revive(BR);
					if(Ari.getX() == Jeff.getX() && Ari.getY() == Jeff.getY() && !Jeff.isAlive()) tabuleiro.revive(Jeff);
					if(Ari.getX() == Cadu.getX() && Ari.getY() == Cadu.getY() && !Cadu.isAlive()) tabuleiro.revive(Cadu);
				}

				auxCharacter=2;
			}

		}

		else if(auxCharacter == 2){
			if(!Jeff.isAlive()){
				auxCharacter=3;
				continue;
			}
			if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if(ev.mouse.x <= 548 && ev.mouse.y <=548){              
                	Jeff.walk(mapa, ev.mouse.x/60, ev.mouse.y/60);
					tabuleiro.isQualCasaHero(Jeff, mapa);
					if(Jeff.getX() == BR.getX() && Jeff.getY() == BR.getY() && !BR.isAlive()) tabuleiro.revive(BR);
					if(Jeff.getX() == Ari.getX() && Jeff.getY() == Ari.getY() && !Ari.isAlive()) tabuleiro.revive(Ari);
					if(Jeff.getX() == Cadu.getX() && Jeff.getY() == Cadu.getY() && !Cadu.isAlive()) tabuleiro.revive(Cadu);
				}

				auxCharacter=3;
			}

		}

		else if(auxCharacter == 3){
			if(!Cadu.isAlive()){
				auxCharacter=4;
				continue;
			}
			if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				if(ev.mouse.x <= 548 && ev.mouse.y <=548){              
                	Cadu.walk(mapa, ev.mouse.x/60, ev.mouse.y/60);
					tabuleiro.isQualCasaHero(Cadu, mapa);
					if(Cadu.getX() == BR.getX() && Cadu.getY() == BR.getY() && !BR.isAlive()) tabuleiro.revive(BR);
					if(Cadu.getX() == Ari.getX() && Cadu.getY() == Ari.getY() && !Ari.isAlive()) tabuleiro.revive(Ari);
					if(Cadu.getX() == Jeff.getX() && Cadu.getY() == Jeff.getY() && !Jeff.isAlive()) tabuleiro.revive(Jeff);
				}

				auxCharacter=4;
			}

		}

		else if(auxCharacter == 4){
		 	Cuadrado.walk();
			al_flip_display();
			tabuleiro.isQualCasaBoss(Cuadrado, mapa);				
			if(Cuadrado.getX() == BR.getX() && Cuadrado.getY() == BR.getY()) tabuleiro.battle(Cuadrado, BR);
			if(Cuadrado.getX() == Ari.getX() && Cuadrado.getY() == Ari.getY()) tabuleiro.battle(Cuadrado, Ari);
			if(Cuadrado.getX() == Jeff.getX() && Cuadrado.getY() == Jeff.getY()) tabuleiro.battle(Cuadrado, Jeff);
			if(Cuadrado.getX() == Cadu.getX() && Cuadrado.getY() == Cadu.getY()) tabuleiro.battle(Cuadrado, Cadu);

			auxCharacter=0;
		}
		
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap_region(bitmap, 0, 0, 1068, 710, 0, 0, 0);
        
        delete hpAri;
        delete hpBR;
        delete hpCadu;
        delete hpJeff;
        delete hpCuadrado;
		delete contAbacaxi;
		delete abacaxiAri;
        delete abacaxiBR;
        delete abacaxiCadu;
        delete abacaxiJeff;

    }
	if(ganhou) std::cout << "\n\nVOCE GANHOU\n\n";
	else std::cout << "\n\nVOCE PERDEU\n\n";

    //DESTROOOOOOOOOOOOOOOOOI
    al_destroy_bitmap(bitmap);
    al_destroy_font(fonte);
    al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

}
