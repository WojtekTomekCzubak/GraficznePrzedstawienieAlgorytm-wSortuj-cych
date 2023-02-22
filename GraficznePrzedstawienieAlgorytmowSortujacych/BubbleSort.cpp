#include "BubbleSort.h"

//Private functions
void BubbleSort::initVariables()
{
	this->initShapes();
}

void BubbleSort::initShapes()
{
	for (int i = 0; i < 30; i ++) {
		sf::RectangleShape shape;
		shape.setSize(sf::Vector2f(20, 20 + (i*10)));
		shape.setPosition(sf::Vector2f(/*Tutaj dodac randomy x i sprawdzenie czy takie wspolrzedne juz sa*/ randomXPos(), 600 - shape.getSize().y));
		this->shapes.push_back(shape);
	}
}

float BubbleSort::randomXPos()
{
	float random = rand() % 30 * 20;

	if (checkXPos(random) == true) {
		return this->randomXPos();
	}
	else {
		return random;
	}
}

bool BubbleSort::checkXPos(float random)
{

	for (sf::RectangleShape s : this->shapes) {
		if (s.getPosition().x == random) {
			return true;
			break;
		}
	}

	return false;
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
	/*
	for (sf::RectangleShape meta : this->shapes) {
		std::cout << "X: " << meta.getPosition().x << " Y: " << meta.getSize().y << std::endl;
	}
	*/

	for (int i = 0; i < shapes.size(); i++) {
		for (int j = 0; j < shapes.size() - 1; j++) {
			if (shapes[j].getSize().y < shapes[j + 1].getSize().y && shapes[j].getPosition().x < shapes[j+1].getPosition().x) {
				float changeX = shapes[j + 1].getPosition().x;
				shapes[j + 1].setPosition(shapes[j].getPosition().x, shapes[j+1].getPosition().y);
				shapes[j].setPosition(changeX, shapes[j].getPosition().y);
			}
			
		}
	}

	/*
	for (sf::RectangleShape meta : this->shapes) {
		std::cout << "X: " << meta.getPosition().x << " Y: " << meta.getSize().y << std::endl;
	}
	*/
}

void BubbleSort::render(sf::RenderTarget& target)
{
	for (auto i : this->shapes) {
		target.draw(i);
	} 
}
