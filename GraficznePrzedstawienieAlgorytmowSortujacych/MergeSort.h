#pragma once

#include "ExampleData.h"

class MergeSort
{
private:
	ExampleData exampleData;

	std::vector<sf::RectangleShape> shapes;

	void initData();
	void initVariables();
	void mergeSort(std::vector<sf::RectangleShape> &arr, int left, int rigt, sf::RenderWindow& window);
	void merge(std::vector<sf::RectangleShape>& arr, int left, int middle, int right, sf::RenderWindow& window);
	void arrSwap(std::vector<sf::RectangleShape> &arr1, int f1, std::vector<sf::RectangleShape> arr2, int f2);
	void drawing(std::vector<sf::RectangleShape> s1, int i1, int i2, sf::RenderWindow& window);

public:
	MergeSort();

	void mergeSortFunction(sf::RenderWindow& window);

	void render(sf::RenderTarget& target);
};

