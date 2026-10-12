#include "BubbleSort.h"

//Cons / Des
BubbleSort::BubbleSort()
	: SortAlgorithm("BubbleSort")
{
}

//Protected functions
void BubbleSort::sort()
{
	/*
	* @return void.
	*
	* Function that use bubbleSort algorithm to sort graphic data with its height.
	* Neighbouring bars are compared and swapped if the left one is higher, so after every pass
	* the highest bar from unsorted part goes to the end.
	* If there was no swap in the whole pass, data is already sorted.
	*/

	for (int i = 0; i < this->size() - 1; i++) {
		bool replace = false;

		for (int j = 0; j < this->size() - i - 1; j++) {
			if (this->height(j) > this->height(j + 1)) {
				this->swapBars(j, j + 1);
				replace = true;
			}
		}

		if (!replace) break;
	}
}
