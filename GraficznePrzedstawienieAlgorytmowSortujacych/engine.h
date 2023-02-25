#pragma once

#include "BubbleSort.h"
#include "CombSort.h"

#include <vector>

class Engine
{
	/*
		Engine for the app.
	*/

private:
	BubbleSort* bubbleSort; //Pointer do obiektu klasy BubbleSort aby móc zainicjalizowaæ go jako nullptr.
	CombSort* combSort;

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

	//Initlization rest of the classes
	void initBubbleSort(); //Funckja inicjalizuj¹ca klasê BubbleSort ze wzglêdu na optymalizacje i wczeœniejsze zainicjalizowanie jako nullptr.
	void initCombSort();

	void update();
	void render(int choose);
};

