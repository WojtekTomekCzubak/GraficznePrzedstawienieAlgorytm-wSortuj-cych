#include "QuickSort.h"

//Private functions
void QuickSort::quickSortFunction(int start, int end)
{
	/*
	* @return void.
	*
	* Bars lower than pivot (middle bar) go to the left, higher go to the right.
	* Then both parts are sorted the same way (recursion).
	*/

	if (start >= end) return; //Check if arguments are good.

	int p = start, q = end;
	float pivot = this->height((start + end) / 2);

	//Loop ends as soon as p and q pass each other.
	//Searching again after that went out of the vector (e.g. q = -1 for data {0, 1}).
	while (p <= q) {
		while (this->height(p) < pivot) p++;
		while (this->height(q) > pivot) q--;

		if (p <= q) {
			this->swapBars(p, q);
			p++;
			q--;
		}
	}

	if (q > start) this->quickSortFunction(start, q);
	if (p < end) this->quickSortFunction(p, end);
}

//Cons / Des
QuickSort::QuickSort()
	: SortAlgorithm("QuickSort")
{
}

//Protected functions
void QuickSort::sort()
{
	this->quickSortFunction(0, this->size() - 1);
}
