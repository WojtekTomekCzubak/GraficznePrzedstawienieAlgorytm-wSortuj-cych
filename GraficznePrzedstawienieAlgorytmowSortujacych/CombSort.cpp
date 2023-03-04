#include "CombSort.h"

void CombSort::initVariables()
{
	this->initShapes();
}

void CombSort::initShapes()
{
	this->shapes = exampleData.dataAccess();
}

CombSort::CombSort(sf::RenderWindow& window)
{
	this->initVariables();
}

void CombSort::combSortingFunction(sf::RenderWindow& target)
{
	int gap = this->shapes.size();
	bool replace = true;

	while (gap > 1 || replace)
	{
		gap = gap * 10 / 13;

		if (gap == 0) gap = 1;

		replace = false;

		for (int i = 0; i + gap < this->shapes.size(); i++) {
			if (shapes[i + gap].getSize().y < shapes[i].getSize().y) {
				shapes[i + gap].setFillColor(sf::Color::Red);
				shapes[i].setFillColor(sf::Color::Red);

				sf::Vector2f change = shapes[i + gap].getSize();
				shapes[i + gap].setSize(sf::Vector2f(change.x, shapes[i].getSize().y));
				shapes[i + gap].setPosition(sf::Vector2f(shapes[i+gap].getPosition().x, 1000 - shapes[i].getSize().y));
				shapes[i].setSize(sf::Vector2f(shapes[i].getSize().x, change.y));
				shapes[i].setPosition(sf::Vector2f(shapes[i].getPosition().x, 1000 - change.y));

				replace = true;
				target.clear();

				for (sf::RectangleShape& shape : shapes) {
					target.draw(shape);
				}

				target.display();

				shapes[i + gap].setFillColor(sf::Color::White);
				shapes[i].setFillColor(sf::Color::White);
			}
		}
	}
}

void CombSort::render(sf::RenderTarget& target)
{
	for (sf::RectangleShape s : this->shapes) target.draw(s);
}
