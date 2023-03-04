#pragma once

#include "ExampleData.h"

class ShakeSort
{
private:
	//Private variables
	ExampleData exampleData;

	std::vector<sf::RectangleShape> shapes;

	int bottom;
	int top;
	bool replace;

	//Private functions
	void initVariables();
	void initData();

public:
	//Public variables

	//Public functions
	ShakeSort(sf::RenderWindow& window);
	virtual ~ShakeSort();

	void shakeSortFunction(sf::RenderWindow& target);

	void render(sf::RenderTarget& target);
};

