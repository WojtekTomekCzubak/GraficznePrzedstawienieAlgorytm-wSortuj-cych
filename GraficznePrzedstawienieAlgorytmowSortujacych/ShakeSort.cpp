#include "ShakeSort.h"

void ShakeSort::initVariables()
{
	this->initData();
}

void ShakeSort::initData()
{
	this->shapes = this->exampleData.dataAccess();
	this->bottom = 0;
	this->top = this->shapes.size() - 1;
	this->replace = true;
}

ShakeSort::ShakeSort(sf::RenderWindow& window)
{
	this->initVariables();
}

ShakeSort::~ShakeSort()
{
}

void ShakeSort::shakeSortFunction(sf::RenderWindow& target)
{
	while (this->replace) {
		this->replace = false;

		for (int i = this->bottom; i < this->top; i++) {
			if (this->shapes[i].getSize().y > this->shapes[i + 1].getSize().y)
			{

				this->shapes[i].setFillColor(sf::Color::Red);
				this->shapes[i + 1].setFillColor(sf::Color::Red);

				sf::Vector2f change = this->shapes[i].getSize();
				this->shapes[i].setSize(sf::Vector2f(this->shapes[i].getSize().x, this->shapes[i + 1].getSize().y));
				this->shapes[i].setPosition(sf::Vector2f(this->shapes[i].getPosition().x, this->shapes[i + 1].getPosition().y));
				this->shapes[i + 1].setSize(sf::Vector2f(this->shapes[i + 1].getSize().x, change.y));
				this->shapes[i + 1].setPosition(sf::Vector2f(this->shapes[i + 1].getPosition().x, 1000 - change.y));

				replace = true;
				
				target.clear();

				for (sf::RectangleShape& s : this->shapes) target.draw(s);

				target.display();

				this->shapes[i].setFillColor(sf::Color::White);
				this->shapes[i + 1].setFillColor(sf::Color::White);
			}
		}

		this->top--;
		
		for (int i = this->top; i > this->bottom; i--) {
			if (this->shapes[i].getSize().y < shapes[i - 1].getSize().y) {

				this->shapes[i].setFillColor(sf::Color::Red);
				this->shapes[i + 1].setFillColor(sf::Color::Red);

				sf::Vector2f change = this->shapes[i].getSize();
				this->shapes[i].setSize(sf::Vector2f(this->shapes[i].getSize().x, this->shapes[i - 1].getSize().y));
				this->shapes[i].setPosition(sf::Vector2f(this->shapes[i].getPosition().x, this->shapes[i - 1].getPosition().y));
				this->shapes[i - 1].setSize(sf::Vector2f(this->shapes[i - 1].getSize().x, change.y));
				this->shapes[i - 1].setPosition(sf::Vector2f(this->shapes[i - 1].getPosition().x, 1000 - change.y));

				target.clear();

				for (sf::RectangleShape& s : this->shapes) target.draw(s);

				target.display();

				this->shapes[i].setFillColor(sf::Color::White);
				this->shapes[i + 1].setFillColor(sf::Color::White);
			}
		}

		this->bottom++;
	}
}

void ShakeSort::render(sf::RenderTarget& target)
{
	for (sf::RectangleShape s : this->shapes)
		target.draw(s);
}
