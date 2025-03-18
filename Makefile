CC = gcc
CPP = g++
NOME_EXE = paddle
PARAM_AGGIUNTIVI = sfondo.cpp palla.cpp paddle.cpp blocco.cpp random.c blockHandler.cpp
PARAM_SFML = -lsfml-graphics -lsfml-window -lsfml-system

#all + nome eseguibile
all: start

#rimuovi questi file col comando clean
clean:
	rm *.exe

#tutte le volte che richiamo start esegue questo
start: main.cpp
	$(CPP) -Wall -o $(NOME_EXE) main.cpp $(PARAM_AGGIUNTIVI) $(PARAM_SFML)