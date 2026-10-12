#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

//Size of the window and of the graphic data.
constexpr unsigned WINDOW_SIZE = 1000;
constexpr int BAR_COUNT = 50;
constexpr float BAR_WIDTH = static_cast<float>(WINDOW_SIZE) / BAR_COUNT;

class ExampleData
{
private:
	//Private variables
	std::vector<sf::RectangleShape> shapes;

	//Private functions
	void initVariables();
	void initData();

public:
	//Public variables
	ExampleData();

	//Public functions
	const std::vector<sf::RectangleShape>& dataAccess() const;
};
