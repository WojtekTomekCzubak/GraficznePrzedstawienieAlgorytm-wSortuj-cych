#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class BubbleSort{
private:

	sf::RectangleShape shape;
	std::vector<sf::RectangleShape> shapes;

	//Private functions
	void initVariables();
	void initShapes();
	float randomXPos();
	bool checkXPos(float random);
	float randomYSize();
	bool checkYSize(float random);

public:
	BubbleSort();
	virtual ~BubbleSort();

	//Private funcition
	void bubbleSortingFunction();
	void render(sf::RenderTarget& target);
};
