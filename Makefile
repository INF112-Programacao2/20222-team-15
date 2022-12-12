ALLEGRO_VERSION=5.0.10
MINGW_VERSION=6.3.0-1
FOLDER=C:

FOLDER_NAME=\allegro-$(ALLEGRO_VERSION)-mingw-$(MINGW_VERSION)
PATH_ALLEGRO=$(FOLDER)$(FOLDER_NAME)
LIB_ALLEGRO=\lib\liballegro-$(ALLEGRO_VERSION)-monolith-mt.a
INCLUDE_ALLEGRO=\include

all: main.exe

main.exe: main.o hero.o enemy.o bossEnemy.o board.o
	g++ -o main.exe main.o hero.o enemy.o bossEnemy.o board.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

hero.o: hero.cpp hero.h
	g++ -c -o hero.o hero.cpp

enemy.o: enemy.cpp enemy.h
	g++ -c -o enemy.o enemy.cpp

bossEnemy.o: bossEnemy.cpp bossEnemy.h
	g++ -c -o bossEnemy.o bossEnemy.cpp

board.o: board.cpp board.h
	g++ -c -o board.o board.cpp

clean:
	del hero.o
	del main.o 
	del main.exe