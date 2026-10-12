#include "InsertionSort.h"

//Cons / Des
InsertionSort::InsertionSort()
	: SortAlgorithm("InsertionSort")
{
}

//Protected functions
void InsertionSort::sort()
{
	/*
	* @return void.
	*
	* Takes next bar and moves higher bars one place to the right, until a place for taken bar is found.
	*/

	for (int i = 1; i < this->size(); i++) {
		float key = this->height(i);
		int j;

		for (j = i - 1; j >= 0 && this->height(j) > key; j--) {
			this->setHeight(j + 1, this->height(j));
			this->showStep({ j + 1 });
		}

		this->setHeight(j + 1, key);
		this->showStep({ j + 1 });
	}
}
