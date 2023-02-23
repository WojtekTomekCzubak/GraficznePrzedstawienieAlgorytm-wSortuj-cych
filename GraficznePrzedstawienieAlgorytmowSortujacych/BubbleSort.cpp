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
		shape.setSize(sf::Vector2f(20, randomYSize()));
		shape.setPosition(sf::Vector2f(i*20, 600 - shape.getSize().y));
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

float BubbleSort::randomYSize()
{
	float random = (rand()%30 + 2) * 20;

	if (checkYSize(random) == true) return this->randomYSize();
	else return random;
}

bool BubbleSort::checkYSize(float random)
{
	for (sf::RectangleShape s : this->shapes) {
		if (s.getSize().y == random) {
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
	for (int i = 0; i < shapes.size() - 1; i++) {
		for (int j = 0; j < shapes.size() - i - 1; j++) {
			if (shapes[j].getSize().y > shapes[j + 1].getSize().y && shapes[j].getPosition().x < shapes[j + 1].getPosition().x) {
				float changeSizeY = shapes[j].getSize().y;
				shapes[j].setSize(sf::Vector2f(shapes[j].getSize().x, shapes[j + 1].getSize().y));
				shapes[j].setPosition(sf::Vector2f(shapes[j].getPosition().x, 600 - shapes[j].getSize().y));
				shapes[j + 1].setSize(sf::Vector2f(shapes[j + 1].getSize().x, changeSizeY));
				shapes[j + 1].setPosition(sf::Vector2f(shapes[j + 1].getPosition().x, 600 - shapes[j + 1].getSize().y));
			}

		}
	}
}

void BubbleSort::render(sf::RenderTarget& target)
{
	for (auto i : this->shapes) {
		target.draw(i);
	} 
}
