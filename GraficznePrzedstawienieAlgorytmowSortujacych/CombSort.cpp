#include "CombSort.h"

void CombSort::initVariables()
{
	this->initShapes();
}

void CombSort::initShapes()
{
	this->shapes = exampleData.dataAccess();
}

CombSort::CombSort()
{
	this->initVariables();
}

void CombSort::combSortingFunction(sf::RenderWindow& target)
{

}

void CombSort::render(sf::RenderTarget& target)
{
	for (sf::RectangleShape s : this->shapes) target.draw(s);
}
