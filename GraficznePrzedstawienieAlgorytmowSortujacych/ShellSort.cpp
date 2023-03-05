#include "ShellSort.h"

void ShellSort::initVariables()
{
	this->initData();
}

void ShellSort::initData()
{
	this->shapes = this->exampleData.dataAccess();
}

ShellSort::ShellSort()
{
	this->initVariables();
}

void ShellSort::shellSortFunction(sf::RenderWindow& window)
{
	/*
	for (int gap = shapes.size() / 2; gap > 0; gap /= 2) { //tworzymy int gap ktory jest roznica pomiedzy miejscami oraz sprawdzamy czy jest wiekszy niz 0
        for (int i = gap; i < shapes.size(); i++) { //prawidlowa petla
            int temp = shapes[i];//przyjmujemy dane miejsce w tabeli jako temporary
            int j; //tworzymy int j jako dana do itercji petli i ponownego uzytku poza petla
            for (j = i; j >= gap && shapes[j - gap] > temp; j -= gap) { //przyjmujemy ze j jest rowne i i sprawdzamy czy miejsce j - gap jest wieksze niz obecna dana
                shapes[j] = shapes[j-gap]; //jezeli warunek sie spelnia dokonujemy zamiany
            }
            shapes[j] = temp;
        }
    }
	*/
	
	for (int gap = this->shapes.size() / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < this->shapes.size(); i++) {
			
			sf::Vector2f tempSizeI = this->shapes[i].getSize();
			sf::Vector2f tempPosI = this->shapes[i].getPosition();

			int j;
			for (j = i; j >= gap && shapes[j - gap].getSize().y > tempSizeI.y; j -= gap) {
				shapes[j].setSize(sf::Vector2f(shapes[j - gap].getSize().x, shapes[j - gap].getSize().y));
				shapes[j].setPosition(sf::Vector2f(shapes[j].getPosition().x, shapes[j-gap].getPosition().y));

				shapes[i].setFillColor(sf::Color::Red);
				shapes[j].setFillColor(sf::Color::Red);

				window.clear();

				for (sf::RectangleShape s : this->shapes) {
					window.draw(s);
				}

				window.display();

				shapes[i].setFillColor(sf::Color::White);
				shapes[j].setFillColor(sf::Color::White);

			}
			shapes[j].setSize(tempSizeI);
			shapes[j].setPosition(sf::Vector2f(shapes[j].getPosition().x, tempPosI.y));
		}
	}
}

void ShellSort::render(sf::RenderTarget& target)
{
	for (sf::RectangleShape s : this->shapes) {
		target.draw(s);
	}
}
