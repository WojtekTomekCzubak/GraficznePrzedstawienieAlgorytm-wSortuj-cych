#include "ExampleData.h"

void ExampleData::initVariables()
{
	this->initData();
}

void ExampleData::initData()
{
	for (int i = 0; i < 50; i++) {
		sf::RectangleShape shape;
		shape.setSize(sf::Vector2f(20, randomYSize()));
		shape.setPosition(sf::Vector2f(i * 20, 1000 - shape.getSize().y));
		this->shapes.push_back(shape);
	}
}

float ExampleData::randomYSize()
{
	/*
	* @return float.
	*
	* Function that draw float number(future height) and check if any other shape in vector have the same shape.
	* If yes then it will use recursion to draw good number.
	*/

	float random = (rand() % 50 + 2) * 20;

	if (checkYSize(random) == true) return this->randomYSize();
	else return random;
}

bool ExampleData::checkYSize(float random)
{
	/*
	* @return bool.
	*
	* Function that checks if given number is equal to any height of object.
	*/

	for (sf::RectangleShape s : this->shapes) {
		if (s.getSize().y == random) {
			return true;
			break;
		}
	}

	return false;
}

ExampleData::ExampleData()
{
	this->initVariables();
}

std::vector<sf::RectangleShape> ExampleData::dataAccess()
{
	return this->shapes;
}
