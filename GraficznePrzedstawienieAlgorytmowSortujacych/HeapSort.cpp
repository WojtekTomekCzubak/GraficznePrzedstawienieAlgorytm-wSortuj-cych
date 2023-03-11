/*
	std::vector<int> shapes = {8, 11, 2, 6, 4, 8, 3, 9, 0};

	int n = shapes.size();

	for (int i : shapes) std::cout << i << " ";

	std::cout << std::endl;

	for (int i = n / 2 - 1; i >= 0; i--) { //nale¿y dodaæ dwa elementy aby index ostatniego rodzica siê zmniejszy³.
		validateMaxHeap(shapes, n, i); //tworzymy pierwszy maksymalny kopiec.
	}

	for (int i = n - 1; i > 0; i--) {
		swapik(shapes, 0, i); //swapujemy ostatni element z pierwszym
		validateMaxHeap(shapes, --n, 0); //tworzymy maksymalny kopiec bez ostatniego elementu bo mamy pewnosc ze jest na odpowiedniej pozycji z odpowiednia wartoscia
	}

	for (int i : shapes) std::cout << i << " ";

	std::cout << std::endl;
	*/

#include "HeapSort.h"

void HeapSort::initData()
{
	this->shapes = exampleData.dataAccess();
}

void HeapSort::initVariables()
{
	this->initData();
}

void HeapSort::validateMaxHeap(sf::RenderWindow& window, int heapSize, int parentIndex)
{
	int maxIndex = parentIndex;
	int leftChild = parentIndex * 2 + 1;
	int rightChild = parentIndex * 2 + 2;

	if (leftChild < heapSize && shapes[leftChild].getSize().y > shapes[maxIndex].getSize().y) {
		maxIndex = leftChild;
	}

	if (rightChild < heapSize && shapes[rightChild].getSize().y > shapes[maxIndex].getSize().y) {
		maxIndex = rightChild;
	}

	if (maxIndex != parentIndex) {
		swapik(window, maxIndex, parentIndex);
		validateMaxHeap(window, heapSize, maxIndex);
	}
}

void HeapSort::swapik(sf::RenderWindow& window, int index1, int index2)
{
	sf::Vector2f tempSize = this->shapes[index1].getSize();
	sf::Vector2f tempPos = this->shapes[index1].getPosition();

	this->shapes[index1].setFillColor(sf::Color::Red);
	this->shapes[index2].setFillColor(sf::Color::Red);

	shapes[index1].setSize(shapes[index2].getSize());
	shapes[index1].setPosition(sf::Vector2f(this->shapes[index1].getPosition().x, shapes[index2].getPosition().y));

	shapes[index2].setSize(tempSize);
	shapes[index2].setPosition(sf::Vector2f(this->shapes[index2].getPosition().x, tempPos.y));

	window.clear();

	for (sf::RectangleShape s : this->shapes) {
		window.draw(s);
	}

	window.display();

	this->shapes[index1].setFillColor(sf::Color::White);
	this->shapes[index2].setFillColor(sf::Color::White);
}

HeapSort::HeapSort()
{
	this->initVariables();
}

void HeapSort::heapSortFunction(sf::RenderWindow& window)
{
	int n = this->shapes.size();
	
	for (int i = n / 2 - 1; i >= 0; i--) {
		validateMaxHeap(window, n, i);
	}

	for (int i = n - 1; i > 0; i--) {
		swapik(window, 0, i);
		validateMaxHeap(window, --n, 0);
	}
}

void HeapSort::render(sf::RenderTarget& target)
{
	for (sf::RectangleShape s : this->shapes) target.draw(s);
}
