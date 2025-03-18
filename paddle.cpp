#include "paddle.h"

Paddle::Paddle(){
	Iniz();
}

void Paddle::Iniz(){
	x = WIDTH/2;
	t.loadFromFile(TEXTURE_PADDLE);
	sp.setTexture(t);
	//sp.scale(WIDTH*PROPORZ_PADDLE/W_TEXTURE_PADDLE, WIDTH*PROPORZ_PADDLE/W_TEXTURE_PADDLE);	//imm originale 720 x 450
	sp.setPosition(x, HEIGHT-HEIGHT/10.0);
}

void Paddle::vaiA(int a){
	if(a>lenPaddle/2 && a<WIDTH-lenPaddle/2)
	{
		x = a-lenPaddle/2;
	}
	sp.setPosition(x, HEIGHT-HEIGHT/10.0);
}

int Paddle::getX(){
	return x;
}

bool Paddle::staToccando(int a){
	if(a>x-lenPaddle/2 && a<x+lenPaddle/2)	//se a si trova sul paddle
	{
		return true;
	}
	return false;
}

void Paddle::Render(RenderWindow& window){
	window.draw(sp);
}