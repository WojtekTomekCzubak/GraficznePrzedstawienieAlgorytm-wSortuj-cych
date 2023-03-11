#include "MergeSort.h"

void MergeSort::initData()
{
	this->shapes = this->exampleData.dataAccess();
}

void MergeSort::initVariables()
{
	this->initData();
}

void MergeSort::mergeSort(std::vector<sf::RectangleShape>& arr, int left, int right, sf::RenderWindow& window)
{
	if (left < right) {
		int middle = (left + right - 1) / 2;

		mergeSort(arr, left, middle, window);
		mergeSort(arr, middle + 1, right, window);

		merge(arr, left, middle, right, window);
	}
}

void MergeSort::merge(std::vector<sf::RectangleShape>& arr, int left, int middle, int right, sf::RenderWindow& window)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;
	
	std::vector<sf::RectangleShape> L(n1), R(n2);

	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[middle + 1 + i];
	}

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (L[i].getSize().y <= R[j].getSize().y)
		{
			arrSwap(arr, k, L, i);
			drawing(arr, k, i, window);
			i++;
		}

		else 
		{
			arrSwap(arr, k, R, j);
			drawing(arr, k, j, window);
			j++;
		}

		k++;
	}

	while (i < n1) 
	{
		arrSwap(arr, k, L, i);
		drawing(arr, k, i, window);
		i++;
		k++;
	}

	while (j < n2) 
	{
		arrSwap(arr, k, R, j);
		drawing(arr, k, j, window);
		j++;
		k++;
	}
}

void MergeSort::arrSwap(std::vector<sf::RectangleShape>& arr1, int f1, std::vector<sf::RectangleShape> arr2, int f2)
{
	arr1[f1].setSize(sf::Vector2f(arr1[f1].getSize().x, arr2[f2].getSize().y));
	arr1[f1].setPosition(sf::Vector2f(arr1[f1].getPosition().x, arr2[f2].getPosition().y));
}

void MergeSort::drawing(std::vector<sf::RectangleShape> s1, int i1, int i2, sf::RenderWindow& window)
{
	s1[i1].setFillColor(sf::Color::Red);
	s1[i2].setFillColor(sf::Color::Red);

	window.clear();

	for (sf::RectangleShape s : s1) {
		window.draw(s);
	}

	window.display();

	s1[i1].setFillColor(sf::Color::White);
	s1[i2].setFillColor(sf::Color::White);
}

MergeSort::MergeSort()
{
	this->initVariables();
}

void MergeSort::mergeSortFunction(sf::RenderWindow& window)
{
	this->mergeSort(this->shapes, 0, this->shapes.size() - 1, window);
}

void MergeSort::render(sf::RenderTarget& target)
{
	for (sf::RectangleShape s : this->shapes) {
		target.draw(s);
	}
}
