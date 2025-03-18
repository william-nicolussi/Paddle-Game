#include "palla.h"

Palla::Palla(){
	Iniz(100, 100);
}

void Palla::Iniz(int a, int b){
	x = a;
	y = b;
	vel = 1;
	dx = vel;
	dy = vel;
	t.loadFromFile(TEXTURE_PALLA);
	sp.setTexture(t);
	//sp.scale(WIDTH*PROPORZ_PALLA/W_TEXTURE_PALLA, WIDTH*PROPORZ_PALLA/H_TEXTURE_PALLA);	//imm originale 12 x 12
	sp.setPosition(x, y);
}

void Palla::muovi(int pdX){
	x += dx;
	y += dy;
	sp.setPosition(x, y);
	//se tocchi i muri
	if (x<0 || x>WIDTH-WIDTH*PROPORZ_PALLA)
	{
		dx = -dx;
	}
	//se tocchi il soffitto
	if (y<0 || y>HEIGHT-WIDTH*PROPORZ_PALLA)
	{
		dy = -dy;
	}
	//se tocchi il paddle
	if(x>pdX && x<pdX+lenPaddle && y>HEIGHT-HEIGHT/10.0-9 && y<HEIGHT-HEIGHT/10.0+2)
	{
		dy = -dy;
	}
}

void Palla::setSpeed(int newSpeed){
	vel = newSpeed;
}

void Palla::addSpeed(int speedAdder){
	vel += speedAdder;
}

void Palla::Render(RenderWindow& window){
	window.draw(sp);
}