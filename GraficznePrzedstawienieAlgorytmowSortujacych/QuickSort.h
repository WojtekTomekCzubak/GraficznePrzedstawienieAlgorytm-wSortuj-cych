#pragma once

#include "ExampleData.h"

class QuickSort
{
private:
	//Priavte variables
	ExampleData exampleData;

	std::vector<sf::RectangleShape> shapes;

	//Private functions
	void initData();
	void initVariables();
	void quickSortFunction(sf::RenderWindow& window, std::vector<sf::RectangleShape>& tabvec, int start, int end);

public:
	//Public variables

	//Public functions
	QuickSort(sf::RenderWindow& window);
	
	void initQuickSortFunction(sf::RenderWindow& window);

	void render(sf::RenderTarget& target);
};

