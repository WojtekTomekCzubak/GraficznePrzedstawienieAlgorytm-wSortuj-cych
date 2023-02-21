#include "BubbleSort.h"

//Private functions
void BubbleSort::initVariables()
{
	this->random = 0;
	this->initShapes();
}

void BubbleSort::initShapes()
{
	for (int i = 10; i <= 30; i += 10) {
		sf::RectangleShape shape;
		shape.setSize(sf::Vector2f(10, 10 + i));
		shape.setPosition(sf::Vector2f((rand()%10 + 1) * 10 + (i * 5), 550 - shape.getSize().y));
		this->shapes.push_back(shape);
	}
}

//Cons / Des
BubbleSort::BubbleSort()
{
	this->initVariables();
}

BubbleSort::~BubbleSort()
{

}

//Public functions
void BubbleSort::bubbleSortingFunction()
{
	for (sf::RectangleShape meta : this->shapes) {
		std::cout << "X: " << meta.getPosition().x << " Y: " << meta.getSize().y << std::endl;
	}

	std::cout << std::endl;
	std::cout << shapes.size();
	std::cout << std::endl;

	for (int i = 0; i < shapes.size(); i++) {
		for (int j = 0; j < shapes.size() - 1; j++) {
			if (shapes[j].getSize().y < shapes[j + 1].getSize().y && shapes[j].getPosition().x < shapes[j+1].getPosition().x) {
				float changeX = shapes[j + 1].getPosition().x;
				shapes[j + 1].setPosition(shapes[j].getPosition().x, shapes[j+1].getPosition().y);
				shapes[j].setPosition(changeX, shapes[j].getPosition().y);
			}
			
		}
	}

	/* for (int i = 0; i < this->shapes.size() - 1; i++) {
		for (int j = 0; j < this->shapes.size() - i - 1; j++) {
			if (shapes[j].getSize().y > shapes[j + 1].getSize().y) {
				sf::Vector2f change = shapes[j].getPosition();
				std::swap(shapes[j], shapes[j + 1]);
				shapes[j+1].setPosition(shapes[j].getPosition());
				shapes[j].setPosition(change);
			}
		}
	} */

	for (sf::RectangleShape meta : this->shapes) {
		std::cout << "X: " << meta.getPosition().x << " Y: " << meta.getSize().y << std::endl;
	}
}

void BubbleSort::update()
{

}

void BubbleSort::render(sf::RenderTarget& target)
{
	for (auto i : this->shapes) {
		target.draw(i);
	} 
}
