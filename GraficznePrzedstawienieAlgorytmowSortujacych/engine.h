#pragma once

#include "BubbleSort.h"

#include <vector>

class Engine
{
	/*
		Engine for the app.
	*/

private:
	BubbleSort* bubbleSort; //Pointer do obiektu klasy BubbleSort aby m�c zainicjalizowa� go jako nullptr.

	int choice; //Zmienna s�u��ca do wyboru algorytmu.

	sf::RenderWindow *window;

	//Private functions
	void initVariables();
	void makeDecision();
	void switcher();
	void initWindow();
	void updatePollEvents();
	void gameLoop(int choose);
	

public:
	Engine();
	virtual ~Engine();

	void initBubbleSort(); //Funckja inicjalizuj�ca klas� BubbleSort ze wzgl�du na optymalizacje i wcze�niejsze zainicjalizowanie jako nullptr.
	void update();
	void render(int choose);
};

