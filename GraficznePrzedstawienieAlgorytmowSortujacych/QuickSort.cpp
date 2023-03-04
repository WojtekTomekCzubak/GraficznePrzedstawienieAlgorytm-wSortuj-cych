#include "QuickSort.h"

void QuickSort::initData()
{
	this->shapes = this->exampleData.dataAccess();
}

void QuickSort::initVariables()
{
	this->initData();
}

QuickSort::QuickSort(sf::RenderWindow& window)
{
	this->initVariables();;
}

void QuickSort::initQuickSortFunction(sf::RenderWindow& window)
{
	this->quickSortFunction(window, this->shapes, 0, this->shapes.size()-1);
}

void QuickSort::quickSortFunction(sf::RenderWindow& window, std::vector<sf::RectangleShape>& tabvec, int start, int end)
{
	if (start >= end) return; //Check if arguments are good.

	int p = start - 1, q = end + 1; 
	sf::Vector2f pivot = tabvec[(start + end) / 2].getSize();

	while (true) {
		while (pivot.y > this->shapes[++p].getSize().y);
		while (pivot.y < this->shapes[--q].getSize().y);

		if (p <= q) {
			shapes[p].setFillColor(sf::Color::Red);
			shapes[q].setFillColor(sf::Color::Red);

			sf::Vector2f changePos = tabvec[q].getPosition();
			sf::Vector2f changeSize = tabvec[q].getSize();

			tabvec[q].setSize(sf::Vector2f(tabvec[q].getSize().x, tabvec[p].getSize().y));
			tabvec[q].setPosition(sf::Vector2f(tabvec[q].getPosition().x, tabvec[p].getPosition().y));

			tabvec[p].setSize(sf::Vector2f(tabvec[p].getSize().x, changeSize.y));
			tabvec[p].setPosition(sf::Vector2f(tabvec[p].getPosition().x, changePos.y));

			window.clear();

			for (sf::RectangleShape s : this->shapes) window.draw(s);

			window.display();

			shapes[p].setFillColor(sf::Color::White);
			shapes[q].setFillColor(sf::Color::White);
		}
		else {
			break;
		}
	}

	if (q > start) this->quickSortFunction(window, tabvec, start, q);
	if (p < end) this->quickSortFunction(window, tabvec, p, end);
}

void QuickSort::render(sf::RenderTarget& target)
{
	for (sf::RectangleShape s : this->shapes)
		target.draw(s);
}
