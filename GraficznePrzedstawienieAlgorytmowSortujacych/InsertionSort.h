#pragma once

#include "ExampleData.h"

class InsertionSort
{
private:
	//Private variables
	ExampleData exampleData;

	std::vector<sf::RectangleShape> shapes;

	//Private functions
	void initVariables();
	void initData();

public:
	//Public variables
	InsertionSort(sf::RenderWindow& window);
	void insertionSortFunction(sf::RenderWindow& window);

	//Public functions
	void render(sf::RenderTarget& target);
};

