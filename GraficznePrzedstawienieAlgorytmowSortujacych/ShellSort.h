#pragma once

#include "ExampleData.h"

class ShellSort
{
private:
	ExampleData exampleData;

	std::vector<sf::RectangleShape> shapes;

	void initVariables();
	void initData();

public:
	ShellSort();

	void shellSortFunction(sf::RenderWindow& window);

	void render(sf::RenderTarget& target);
};

