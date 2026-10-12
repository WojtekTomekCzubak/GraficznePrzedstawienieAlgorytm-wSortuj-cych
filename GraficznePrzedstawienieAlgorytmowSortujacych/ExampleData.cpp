#include "ExampleData.h"

#include <algorithm>
#include <random>

void ExampleData::initVariables()
{
	this->initData();
}

void ExampleData::initData()
{
	/*
	* @return void.
	*
	* Creates bars with heights BAR_WIDTH, 2 * BAR_WIDTH, ..., WINDOW_SIZE in random order.
	* Every height is different and every bar fits in the window.
	* Shuffling is used instead of drawing random numbers again and again until a free one is found.
	*/

	std::vector<float> heights;

	for (int i = 1; i <= BAR_COUNT; i++) heights.push_back(static_cast<float>(i) * BAR_WIDTH);

	static std::mt19937 generator(std::random_device{}());
	std::shuffle(heights.begin(), heights.end(), generator);

	for (int i = 0; i < BAR_COUNT; i++) {
		sf::RectangleShape shape(sf::Vector2f(BAR_WIDTH, heights[i]));
		shape.setPosition(sf::Vector2f(static_cast<float>(i) * BAR_WIDTH, WINDOW_SIZE - heights[i]));
		this->shapes.push_back(shape);
	}
}

ExampleData::ExampleData()
{
	this->initVariables();
}

const std::vector<sf::RectangleShape>& ExampleData::dataAccess() const
{
	return this->shapes;
}
