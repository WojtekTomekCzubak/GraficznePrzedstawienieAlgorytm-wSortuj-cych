#include "MergeSort.h"

//Private functions
void MergeSort::mergeSort(int left, int right)
{
	/*
	* @return void.
	*
	* Divides data into two halves, sorts both of them (recursion) and merges them together.
	*/

	if (left < right) {
		int middle = left + (right - left) / 2;

		this->mergeSort(left, middle);
		this->mergeSort(middle + 1, right);

		this->merge(left, middle, right);
	}
}

void MergeSort::merge(int left, int middle, int right)
{
	/*
	* @return void.
	*
	* Merges two sorted parts <left, middle> and <middle + 1, right> into one sorted part.
	* Every bar put in its place is shown in red.
	*/

	std::vector<float> L, R;

	for (int i = left; i <= middle; i++) L.push_back(this->height(i));
	for (int i = middle + 1; i <= right; i++) R.push_back(this->height(i));

	size_t i = 0, j = 0;
	int k = left;

	while (i < L.size() && j < R.size()) {
		if (L[i] <= R[j]) this->setHeight(k, L[i++]);
		else this->setHeight(k, R[j++]);

		this->showStep({ k });
		k++;
	}

	while (i < L.size()) {
		this->setHeight(k, L[i++]);
		this->showStep({ k });
		k++;
	}

	while (j < R.size()) {
		this->setHeight(k, R[j++]);
		this->showStep({ k });
		k++;
	}
}

//Cons / Des
MergeSort::MergeSort()
	: SortAlgorithm("MergeSort")
{
}

//Protected functions
void MergeSort::sort()
{
	this->mergeSort(0, this->size() - 1);
}
