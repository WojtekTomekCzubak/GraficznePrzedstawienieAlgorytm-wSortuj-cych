//heap sort 
//k L:2*k+1 gdzie k to iteracja a L i P to kolejno Lewy i Prawy potomek danego indexu.
//  P:2*k+2

//Pe�ne drzewo binarne to drzwo w kt�rym zape�niamy warto�ci od lewej strony
//Maksymalne drzewo binarne to drzewo w kt�rym ka�dy rodzic jest wiekszy niz jego potomek
/*
    Przyk�ad drzewa binarnego.
             0
        /         \
        6          10
     /      \        \
     3      8         7
    /  \  /  \      /  \
    9  0  1  5      4  2

    Przyk�ad drzewa binarnego pe�nego.
            0
        /         \
        6          10
     /     \      /
     3      8     7
    /  \  /  \  /  \
    9  0  1  5  4  2

    Przyk�ad drzewa binarnego pe�nego maksymalnego.
            10
        /         \
        9          7
     /     \      /
     6      8     4
    /  \  /  \  /  \
    3  0  1  5  0  2

*/

#pragma once

#include "ExampleData.h"

class HeapSort
{
private:
	ExampleData exampleData;

	std::vector<sf::RectangleShape> shapes;

	void initData();
	void initVariables();
	void validateMaxHeap(sf::RenderWindow& window, int heapSize, int parentIndex);
	void swapik(sf::RenderWindow& window, int index1, int index2);

public:
	HeapSort();

	void heapSortFunction(sf::RenderWindow& window);
	
	void render(sf::RenderTarget& target);
};

