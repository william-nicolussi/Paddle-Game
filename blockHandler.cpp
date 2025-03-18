#include "random.h"
#include "blockHandler.h"

BlockHandler::BlockHandler(){
	for(int i=0; i<BLOCCHI_X; i++)
	{
		for(int j=0; j<BLOCCHI_Y; j++)
		{
			blocchi[i*BLOCCHI_Y + j].setPos(lenBlocco+i*lenBlocco, 70+j*hgtBlocco);
			blocchi[i*BLOCCHI_Y + j].cambiaColore(getRandomInt(0,255),getRandomInt(0,255),getRandomInt(0,255));
		}
	}
}

void BlockHandler::Render(RenderWindow& window){
	for(int i=0; i<BLOCCHI_X*BLOCCHI_Y; i++)
	{
		blocchi[i].Render(window);
	}
}