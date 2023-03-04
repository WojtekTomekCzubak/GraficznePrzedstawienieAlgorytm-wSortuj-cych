#pragma once

#include "ExampleData.h"

class SelectionSort
{
private:
	//Private variables
	ExampleData exampleData;

	std::vector<sf::RectangleShape> shapes;

	//Private function
	void initData();
	void initVariables();

public:
	//Public variables

	//Public functions
	SelectionSort(sf::RenderWindow& window);

	void selectionSortFunction(sf::RenderWindow& window);

	void render(sf::RenderTarget& target);
};

