#include <stdlib.h>
#include <time.h>
#include "random.h"

int getRandomInt(int min, int max){
	int Numero;
	if(min==max)	//se i due numeri sono uguali restituiscilo
	{
		return min;
	}
	else if(min>max)	//se min>max, scambia le posizioni
	{
		Numero = min;
		min = max;
		max = Numero;
	}
	//srand(time(0));
	Numero = rand() % (max + 1 - min) + min;
	return Numero;
}

float getRandomFloat(float min, float max){
	float Numero;
	if(min==max)
	{
		return min;
	}
	else if(min>max)
	{
		Numero = min;
		min = max;
		max = Numero;
	}
	Numero = ((float)rand()/(float)(RAND_MAX)) * (max+min) + min;
	return Numero;
}
