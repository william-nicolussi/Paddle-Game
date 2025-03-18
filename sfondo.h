/*
	StaticBackground -> crea uno sfondo statico
	e.g. StaticBackground bg("Sfondo.png");	
*/

#ifndef SFONDO_H
#define SFONDO_H

#include <stdio.h>
#include <SFML\Graphics.hpp>

using namespace sf;

class StaticBackground{
	private:
		Texture t;
		Sprite sp;
	public:
		StaticBackground(const char* NomeTexture);		//costruttore
        void Render(RenderWindow& window);		//funzione che disegna lo sfondo
		void scaleBackground(RenderWindow& window);	//scala bg in modo che entri nella finestra
};

/*
	MovableBackground -> crea uno sfondo che si muove
	e.g. 	MovableBackground bg("Sfondo.png");
			bg.setMovX(100);
			bg.scaleBackground(window);
			bg.Update();
			bg.Render();
*/

class MovableBackground{
	private:
		Texture t;
		Sprite sp1;
		Sprite sp2;
		int dir;	//0=sx, 1=dx, 2=su, 3=giu
		int sp1X, sp1Y;	//posizione sprite
		int sp2X, sp2Y;
		int passoX, passoY;	//velocità con cui si muove lo sfondo [pixel/frame]
	public:
		MovableBackground(const char* NomeTexture);	//costruttore
		void setMovX(int pX);	//setta passo x e y
		void setMovY(int pY);
		void Update();	//sposta lo sfondo
        void Render(RenderWindow& window);		//funzione che disegna lo sfondo
		void scaleBackgroundWidth(RenderWindow& window);//scala solo lungo X
		void scaleBackgroundHeight(RenderWindow& window);//scala solo lungo Y
		void scaleBackground(RenderWindow& window);	//scala bg in modo che entri nella finestra
};

#endif