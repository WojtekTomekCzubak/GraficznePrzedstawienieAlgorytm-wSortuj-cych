//heap sort 
//k L:2*k+1 gdzie k to iteracja a L i P to kolejno Lewy i Prawy potomek danego indexu.
//  P:2*k+2

//Pe³ne drzewo binarne to drzwo w którym zape³niamy wartoœci od lewej strony
//Maksymalne drzewo binarne to drzewo w którym ka¿dy rodzic jest wiekszy niz jego potomek
/*
    Przyk³ad drzewa binarnego.
             0
        /         \
        6          10
     /      \        \
     3      8         7
    /  \  /  \      /  \
    9  0  1  5      4  2

    Przyk³ad drzewa binarnego pe³nego.
            0
        /         \
        6          10
     /     \      /
     3      8     7
    /  \  /  \  /  \
    9  0  1  5  4  2

    Przyk³ad drzewa binarnego pe³nego maksymalnego.
            10
        /         \
        9          7
     /     \      /
     6      8     4
    /  \  /  \  /  \
    3  0  1  5  0  2

*/

#pragma once

#include "SortAlgorithm.h"

class HeapSort : public SortAlgorithm
{
private:
	//Private functions
	void validateMaxHeap(int heapSize, int parentIndex);

protected:
	void sort() override;

public:
	HeapSort();
};
