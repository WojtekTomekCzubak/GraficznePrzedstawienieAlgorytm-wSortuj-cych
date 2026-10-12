#include "CombSort.h"

//Cons / Des
CombSort::CombSort()
	: SortAlgorithm("CombSort")
{
}

//Protected functions
void CombSort::sort()
{
	/*
	* @return void.
	*
	* Like bubbleSort, but compares bars which are "gap" places away. Gap gets smaller (/1.3) after every pass.
	*/

	int gap = this->size();
	bool replace = true;

	while (gap > 1 || replace) {
		gap = gap * 10 / 13;

		if (gap == 0) gap = 1;

		replace = false;

		for (int i = 0; i + gap < this->size(); i++) {
			if (this->height(i + gap) < this->height(i)) {
				this->swapBars(i, i + gap);
				replace = true;
			}
		}
	}
}
