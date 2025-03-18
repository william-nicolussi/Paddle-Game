#ifndef PALLA_H
#define PALLA_H

#include "const.h"
#include <SFML/Graphics.hpp>

#define TEXTURE_PALLA "imm/palla.png"
#define W_TEXTURE_PALLA 12.0
#define H_TEXTURE_PALLA 12.0
#define PROPORZ_PALLA 1/25.0	/*grandezza palla rispetto all'altezza*/

using namespace sf;

class Palla{
	int x, y;	//coordinata della palla
	int vel;	//velocita della palla
	int dx, dy;	//direzione della palla
	
	//crea testure e sprite
	Texture t;
	Sprite sp;
	
	public:
		Palla();
		void Iniz(int a, int b);
		void muovi(int pdX); //passa x del paddle così rimbalza se lo tocchi
		void setSpeed(int newSpeed); //funzione per reimpostare vel
		void addSpeed(int speedAdder); //aggiungi a vel questo valore
		void Render(RenderWindow& window); //funzione che disegna la palla
};

#endif