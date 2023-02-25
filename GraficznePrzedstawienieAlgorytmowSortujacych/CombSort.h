#pragma once

#include "ExampleData.h"

class CombSort
{
private:
	//Private variables
	ExampleData exampleData;
	std::vector<sf::RectangleShape> shapes;

	//Private functions
	void initVariables();
	void initShapes();

public:
	//Public variables
	CombSort(sf::RenderWindow& window);

	//Public variables
	void combSortingFunction(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);
};

