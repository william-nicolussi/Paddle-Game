#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "const.h"
#include "sfondo.h"
#include "palla.h"
#include "paddle.h"
#include "blockHandler.h"

int main(){
	StaticBackground bg("imm/sfondo.jpg");
	Palla p;
	Paddle pd;
	BlockHandler blockHndlr;
	Clock clock;	//serve per il framerate
    float timer=0;
	
	//----------Inizializzazioni----------
	RenderWindow window(VideoMode(WIDTH, HEIGHT), NOME_APP);	//visualizza finestra
	p.Iniz(100,10);
	pd.Iniz();
	bg.scaleBackground(window);
	
	while (window.isOpen())
	{
		timer += clock.getElapsedTime().asSeconds();
		clock.restart();   
		//questo serve, senno quando tocchi la finestra crasha
		Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)  
			{
				window.close();
			}			 
		}
		//----------Istruzioni da eseguire ogni frame----------
		
		if (timer>FRAME_RATE)
		{
			timer=0;
			p.muovi(pd.getX());
			pd.vaiA(Mouse::getPosition(window).x);
		}
		
		//---------Disegna sul display----------
		window.clear();
		bg.Render(window);
		p.Render(window);
		pd.Render(window);
		blockHndlr.Render(window);
		window.display();
	}
	
	return 0;
}
