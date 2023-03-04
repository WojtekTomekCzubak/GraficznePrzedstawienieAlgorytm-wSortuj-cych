#include "SelectionSort.h"

void SelectionSort::initData()
{
	this->shapes = this->exampleData.dataAccess();
}

void SelectionSort::initVariables()
{
	this->initData();
}

SelectionSort::SelectionSort(sf::RenderWindow& window)
{
	this->initVariables();
}

void SelectionSort::selectionSortFunction(sf::RenderWindow& window)
{
	for (int i = 0; i < this->shapes.size(); i++) {
		int k = i;

		for (int j = i + 1; j < shapes.size(); j++) {
			if (shapes[k].getSize().y > shapes[j].getSize().y)
			k = j;
		}

		shapes[k].setFillColor(sf::Color::Red);
		shapes[i].setFillColor(sf::Color::Red);

		sf::Vector2f change = shapes[k].getSize();
		sf::Vector2f pos = shapes[k].getPosition();
		shapes[k].setSize(sf::Vector2f(shapes[k].getSize().x, shapes[i].getSize().y));
		shapes[k].setPosition(sf::Vector2f(shapes[k].getPosition().x, shapes[i].getPosition().y));
		shapes[i].setSize(sf::Vector2f(shapes[i].getSize().x, change.y));
		shapes[i].setPosition(sf::Vector2f(shapes[i].getPosition().x, pos.y));

		window.clear();

		for (sf::RectangleShape s : this->shapes) window.draw(s);

		window.display();

		shapes[k].setFillColor(sf::Color::White);
		shapes[i].setFillColor(sf::Color::White);
	}
}

void SelectionSort::render(sf::RenderTarget& target)
{
	for (sf::RectangleShape s : this->shapes)
		target.draw(s);
}
