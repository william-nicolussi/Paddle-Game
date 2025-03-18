#include "blocco.h"

Blocco::Blocco(){
	Iniz(Color(255,0,0));
}

void Blocco::Iniz(Color colore){
	x = WIDTH/2;
	t.loadFromFile(TEXTURE_BLOCCO);
	sp.setTexture(t);
	sp.setColor(colore);
}

void Blocco::cambiaColore(int red, int green, int blue){
	sp.setColor(Color(red, green, blue));
}

void Blocco::setPos(int x0, int y0){
	x = x0;
	y = y0;
	sp.setPosition(x, y);
}

bool Blocco::isBlocco(int xNow, int yNow){
	if(xNow>=x && xNow<=x+lenBlocco)	//se la x cade dentro
	{
		if(yNow>=y && yNow<=y+hgtBlocco)
		{
			return true;
		}
	}
	return false;
}

Sprite Blocco::getSprite(){
	return sp;
}

void Blocco::Render(RenderWindow& window){
	window.draw(sp);
}