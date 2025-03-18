#ifndef BLOCCO_H
#define BLOCCO_H

#include "const.h"
#include <SFML/Graphics.hpp>

#define TEXTURE_BLOCCO "imm/blocco.png"
#define W_TEXTURE_BLOCCO 42.0
#define H_TEXTURE_BLOCCO 20.0
#define PROPORZ_BLOCCO 1/5.0	/*grandezza palla rispetto all'altezza*/

using namespace sf;

class Blocco{
	int x;
	int y;
	
	Texture t;
	Sprite sp;
	
	public:
		Blocco();
		void Iniz(Color colore);			//inizializza con il colore
		void cambiaColore(int red, int green, int blue);	//cambia il colore dell'imm
		void setPos(int x0, int y0);		//imposta la posizione
		bool isBlocco(int xNow, int yNow);	//restituisce 1 se la posizione è occupata dal blocco
		Sprite getSprite();					//restituisce sprite
		void Render(RenderWindow& window);	//disegna passando la finestra
};

#endif