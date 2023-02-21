#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class BubbleSort{
private:
	int random;

	sf::RectangleShape shape;
	std::vector<sf::RectangleShape> shapes;

	//Private functions
	void initVariables();
	void initShapes();

public:
	BubbleSort();
	virtual ~BubbleSort();

	//Private funcition
	void bubbleSortingFunction();
	void update();
	void render(sf::RenderTarget& target);
};
