#include "ShakeSort.h"

//Cons / Des
ShakeSort::ShakeSort()
	: SortAlgorithm("ShakeSort")
{
}

//Protected functions
void ShakeSort::sort()
{
	/*
	* @return void.
	*
	* BubbleSort in both directions: highest bar goes to the right, then lowest bar goes to the left.
	*/

	int bottom = 0;
	int top = this->size() - 1;
	bool replace = true;

	while (replace) {
		replace = false;

		for (int i = bottom; i < top; i++) {
			if (this->height(i) > this->height(i + 1)) {
				this->swapBars(i, i + 1);
				replace = true;
			}
		}

		top--;

		for (int i = top; i > bottom; i--) {
			if (this->height(i) < this->height(i - 1)) {
				this->swapBars(i, i - 1);
				replace = true;
			}
		}

		bottom++;
	}
}
