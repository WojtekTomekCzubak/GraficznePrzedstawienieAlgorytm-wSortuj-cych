#pragma once

#include "ExampleData.h"

class BubbleSort{
private:
	ExampleData exampleData;

	std::vector<sf::RectangleShape> shapes;

	//Private functions
	void initVariables();
	void initShapes();

public:
	BubbleSort();
	virtual ~BubbleSort();

	//Private funcition
	void bubbleSortingFunction(sf::RenderWindow& target); //sf::RenderWindow& u¿yte zosta³o aby móc u¿yæ funkcji jako funkcji wyœwietlaj¹cej dane w aplikacji okienkowej.
	void render(sf::RenderTarget& target);
};
