#ifndef PADDLE_H
#define PADDLE_H

#include "const.h"
#include <SFML/Graphics.hpp>

#define TEXTURE_PADDLE "imm/paddle.png"
#define W_TEXTURE_PADDLE 90.0
#define H_TEXTURE_PADDLE 9.0
#define PROPORZ_PADDLE 1/5.0	/*grandezza palla rispetto all'altezza*/

using namespace sf;

class Paddle{
	int x;
	
	Texture t;
	Sprite sp;
	
	public:
		Paddle();
		void Iniz();
		void vaiA(int a);	//fa muovere padde a quella coordinata
		int getX();			//ritorna x		
		bool staToccando(int a);	//dice se la coordinata viene coperta dal paddle
		void Render(RenderWindow& window);
};

#endif