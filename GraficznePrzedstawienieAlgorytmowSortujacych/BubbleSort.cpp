#include "BubbleSort.h"

//Private functions
void BubbleSort::initVariables()
{
	/*
	* @return void
	* 
	* Initlization for every variable in BubbleSort class.
	*/

	this->initShapes();
}

void BubbleSort::initShapes()
{
	/*
	* @return void.
	*
	* Initlization of graphic data with random height.
	*/

	this->shapes = this->exampleData.dataAccess();
}

//Cons / Des
BubbleSort::BubbleSort(sf::RenderWindow& window)
{
	this->initVariables();
}

BubbleSort::~BubbleSort()
{

}

//Public functions
void BubbleSort::bubbleSortingFunction(sf::RenderWindow& target)
{
	/*
	* @return void.
	* 
	* Function that use bubbleSort alghorithm to sort graphic data with its height.
	* In this function we clear, render and draw whole vector of sf::RectangleShape.
	* This two shapes which are moving are filled with red color and after its move again filled with white color.
	*/

	for (int i = 0; i < shapes.size() - 1; i++) {
		for (int j = 0; j < shapes.size() - i - 1; j++) {
			if (shapes[j].getSize().y > shapes[j + 1].getSize().y && shapes[j].getPosition().x < shapes[j + 1].getPosition().x) {
				float changeSizeY = shapes[j].getSize().y;
				shapes[j].setFillColor(sf::Color::Red);
				shapes[j + 1].setFillColor(sf::Color::Red);
				shapes[j].setSize(sf::Vector2f(shapes[j].getSize().x, shapes[j + 1].getSize().y));
				shapes[j].setPosition(sf::Vector2f(shapes[j].getPosition().x, 1000 - shapes[j].getSize().y));
				shapes[j + 1].setSize(sf::Vector2f(shapes[j + 1].getSize().x, changeSizeY));
				shapes[j + 1].setPosition(sf::Vector2f(shapes[j + 1].getPosition().x, 1000 - shapes[j + 1].getSize().y));

				target.clear();

				for (sf::RectangleShape& shape : shapes) {
					target.draw(shape);
				}

				target.display();

				shapes[j].setFillColor(sf::Color::White);
				shapes[j + 1].setFillColor(sf::Color::White);
			}
		}
	}
}

void BubbleSort::render(sf::RenderTarget& target)
{
	/*
	* @return void.
	* 
	* Function used to render whole vector od sf::RectangleShapes.
	*/

	for (auto i : this->shapes) {
		target.draw(i);
	} 
}
