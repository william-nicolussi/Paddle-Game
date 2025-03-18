#include "sfondo.h"

//----------StaticBackground----------

StaticBackground::StaticBackground(const char* NomeTexture){
	t.loadFromFile(NomeTexture);
	sp.setTexture(t);
	sp.setPosition(0,0);
}

void StaticBackground::Render(RenderWindow& window){
	window.draw(sp);
}

void StaticBackground::scaleBackground(RenderWindow& window){
	//ottieni grandezza finestra
	float WidthWindow = window.getSize().x;
	float HeightWindow = window.getSize().y;
	//ottieni grandezza TEXTURE_SFONDO
	float WidthTexture = t.getSize().x;
	float HeightTexture = t.getSize().y;
	//scala
	sp.setScale(WidthWindow/WidthTexture, HeightWindow/HeightTexture);
}

//----------MovableBackground----------

MovableBackground::MovableBackground(const char* NomeTexture){
	t.loadFromFile(NomeTexture);
	sp1.setTexture(t);
	sp2.setTexture(t);
	sp1X = 0;
	sp1Y = 0;
}

void MovableBackground::setMovX(int pX){
	//setta passo e muovi sp2X della grandezza della texture
	passoX = pX;
	passoY = 0;
	sp2X = sp1X + t.getSize().x*sp1.getScale().x;
	sp2Y = 0;
	if(passoX<0)
	{
		dir = 0;//sx
	}
	else if(passoX>0)
	{
		dir = 1;//dx
		sp2X = -sp2X;
	}
}

void MovableBackground::setMovY(int pY){
	passoX = 0;
	passoY = pY;
	sp2X = 0;
	sp2Y = sp1Y + t.getSize().y*sp1.getScale().y;
	if(passoY<0)
	{
		dir = 2;//su
	}
	if(passoY>0)
	{
		dir = 3;//giu
	}
}

void MovableBackground::Update(){
	//ottieni grandezza TEXTURE_SFONDO
	float WidthTexture = t.getSize().x*sp1.getScale().x;
	float HeightTexture = t.getSize().y*sp1.getScale().y;
	//printf("\nWtxt=%f, Htxt=%f", WidthTexture, HeightTexture);
	switch (dir)
	{
		case (0): //direzione da destra a sinistra
			if(sp1X <= -WidthTexture) //se sp1 scorre tutto a sinistra
			{
				sp1X = sp2X + WidthTexture;
			}
			if (sp2X <= -WidthTexture)	//se ps2 scorre tutto a sinistra
			{
				sp2X = sp1X + WidthTexture;
			}
			break;
		case (1): //direzione da sinistra a destra
			if(sp1X >= WidthTexture) //se sp1 scorre tutto a destra
			{
				sp1X = sp2X - WidthTexture;
			}
			if (sp2X >= WidthTexture)	//se ps2 scorre tutto a destra
			{
				sp2X = sp1X - WidthTexture;
			}
			break;
		case (2): //direzione da basso verso alto
			if(sp1Y <= -HeightTexture) //se sp1 scorre tutto in alto
			{
				sp1Y = sp2Y + HeightTexture;
			}
			if (sp2Y <= -HeightTexture)	//se ps2 scorre tutto in alto
			{
				sp2Y = sp1Y + HeightTexture;
			}		
			break;
		case (3): //direzione da alto verso basso
			if(sp1Y >= HeightTexture) //se sp1 scorre tutto in alto
			{
				sp1Y = sp2Y - HeightTexture;
			}
			if (sp2Y >= HeightTexture)	//se ps2 scorre tutto in alto
			{
				sp2Y = sp1Y - HeightTexture;
			}
			break;
	}
	sp1X += passoX;
	sp1Y += passoY;
	sp2X += passoX;
	sp2Y += passoY;
}

void MovableBackground::Render(RenderWindow& window){
	//printf("\nsp1X=%d, sp1Y=%d; sp2X=%d, sp2Y=%d", sp1X, sp1Y, sp2X, sp2Y);
	sp1.setPosition(sp1X, sp1Y);
	sp2.setPosition(sp2X, sp2Y);
	window.draw(sp1);
	window.draw(sp2);
}

void MovableBackground::scaleBackgroundWidth(RenderWindow& window){
	//ottieni grandezza finestra
	float WidthWindow = window.getSize().x;
	//ottieni grandezza TEXTURE_SFONDO
	float WidthTexture = t.getSize().x;
	sp1.setScale(WidthWindow/WidthTexture, 1);
	sp2.setScale(WidthWindow/WidthTexture, 1);
}

void MovableBackground::scaleBackgroundHeight(RenderWindow& window){
	//ottieni grandezza finestra
	float HeightWindow = window.getSize().y;
	//ottieni grandezza TEXTURE_SFONDO
	float HeightTexture = t.getSize().y;
	//scala
	sp1.setScale(1, HeightWindow/HeightTexture);
	sp2.setScale(1, HeightWindow/HeightTexture);
}

void MovableBackground::scaleBackground(RenderWindow& window){
	//ottieni grandezza finestra
	float WidthWindow = window.getSize().x;
	float HeightWindow = window.getSize().y;
	//ottieni grandezza TEXTURE_SFONDO
	float WidthTexture = t.getSize().x;
	float HeightTexture = t.getSize().y;
	//scala
	sp1.setScale(WidthWindow/WidthTexture, HeightWindow/HeightTexture);
	sp2.setScale(WidthWindow/WidthTexture, HeightWindow/HeightTexture);
}