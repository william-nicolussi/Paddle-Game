#ifndef BLOCKHANDLER_H
#define BLOCKHANDLER_H
/*Classe che si occupa di creare e gestire i blocchi*/
#include "const.h"
#include "blocco.h"

#define BLOCCHI_X 10
#define BLOCCHI_Y 5

class BlockHandler{
	Blocco blocchi[BLOCCHI_X*BLOCCHI_Y];
	
	public:
		BlockHandler();
		void Render(RenderWindow& window);
};

#endif