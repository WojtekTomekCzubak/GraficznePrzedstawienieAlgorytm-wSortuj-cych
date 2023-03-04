#include "InsertionSort.h"

void InsertionSort::initVariables()
{
	this->initData();
}

void InsertionSort::initData()
{
	this->shapes = this->exampleData.dataAccess();
}

InsertionSort::InsertionSort(sf::RenderWindow& window)
{
	this->initVariables();
}

void InsertionSort::insertionSortFunction(sf::RenderWindow& window)
{
	int j, pos;
	sf::Vector2f size;

	for (int i = 1; i < shapes.size(); i++) {
		size = shapes[i].getSize();
		pos = shapes[i].getPosition().y;

		for (j = i - 1; j >= 0 && shapes[j].getSize().y > size.y; j--) {
			shapes[j + 1].setFillColor(sf::Color::Red);

			shapes[j + 1].setSize(sf::Vector2f(shapes[j+1].getSize().x, shapes[j].getSize().y));
			shapes[j + 1].setPosition(sf::Vector2f(shapes[j+1].getPosition().x, shapes[j].getPosition().y));

			window.clear();

			for (sf::RectangleShape s : this->shapes) {
				window.draw(s);
			}

			window.display();

			shapes[j + 1].setFillColor(sf::Color::White);
		}

		shapes[j + 1].setFillColor(sf::Color::Red);

		shapes[j + 1].setSize(sf::Vector2f(shapes[j+1].getSize().x, size.y));
		shapes[j + 1].setPosition(sf::Vector2f(shapes[j + 1].getPosition().x, pos));

		window.clear();

		for (sf::RectangleShape s : this->shapes) {
			window.draw(s);
		}

		window.display();

		shapes[j + 1].setFillColor(sf::Color::White);
	}
}

void InsertionSort::render(sf::RenderTarget& target)
{
	for (sf::RectangleShape s : shapes) {
		target.draw(s);
	}
}
