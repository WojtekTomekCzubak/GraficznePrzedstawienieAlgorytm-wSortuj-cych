#pragma once

#include "BubbleSort.h"
#include "CombSort.h"
#include "ShakeSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "MergeSort.h"

#include <memory>

class Engine
{
	/*
		Engine for the app.
	*/

private:
	sf::RenderWindow window;

	//Private functions
	int makeDecision();
	std::unique_ptr<SortAlgorithm> createAlgorithm(int choice);
	void initWindow();
	void updatePollEvents();
	void gameLoop(const SortAlgorithm& algorithm);
	void update();
	void render(const SortAlgorithm& algorithm);

public:
	void run();
};
