#include "SelectionSort.h"

//Cons / Des
SelectionSort::SelectionSort()
	: SortAlgorithm("SelectionSort")
{
}

//Protected functions
void SelectionSort::sort()
{
	/*
	* @return void.
	*
	* Finds the lowest bar in unsorted part and swaps it with the first bar of unsorted part.
	*/

	for (int i = 0; i < this->size() - 1; i++) {
		int k = i;

		for (int j = i + 1; j < this->size(); j++) {
			if (this->height(k) > this->height(j)) k = j;
		}

		this->swapBars(i, k);
	}
}
