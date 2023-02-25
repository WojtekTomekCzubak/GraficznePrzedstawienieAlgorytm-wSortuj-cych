#pragma once

#include "BubbleSort.h"

#include <vector>

class Engine
{
	/*
		Engine for the app.
	*/

private:
	BubbleSort* bubbleSort; //Pointer do obiektu klasy BubbleSort aby móc zainicjalizowaæ go jako nullptr.

	int choice; //Zmienna s³u¿¹ca do wyboru algorytmu.

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

	void initBubbleSort(); //Funckja inicjalizuj¹ca klasê BubbleSort ze wzglêdu na optymalizacje i wczeœniejsze zainicjalizowanie jako nullptr.
	void update();
	void render(int choose);
};

