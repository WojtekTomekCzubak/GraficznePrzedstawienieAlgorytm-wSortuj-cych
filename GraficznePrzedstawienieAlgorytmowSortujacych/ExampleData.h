#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class ExampleData
{
private:
	//Private variables
	std::vector<sf::RectangleShape> shapes;

	//Private functions
	void initVariables();
	void initData();
	float randomYSize();
	bool checkYSize(float random);

public:
	//Public variables
	ExampleData();

	//Public functions
	std::vector<sf::RectangleShape> dataAccess();
};

