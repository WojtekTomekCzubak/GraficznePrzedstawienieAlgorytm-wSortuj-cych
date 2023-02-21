#pragma once

#include "BubbleSort.h"

#include <vector>

class Engine
{
	/*
		Engine for the app.
	*/

private:
	BubbleSort bubbleSort;

	int choice;

	sf::RenderWindow *window;

	//Private functions
	void initVariables();
	void makeDecision();
	void switcher();
	void initWindow();
	void updatePollEvents();
	void gameLoop();

public:
	Engine();
	virtual ~Engine();

	void update();
	void render();
};

