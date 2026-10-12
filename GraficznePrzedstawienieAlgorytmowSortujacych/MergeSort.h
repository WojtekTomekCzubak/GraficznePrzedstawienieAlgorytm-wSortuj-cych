#pragma once

#include "SortAlgorithm.h"

class MergeSort : public SortAlgorithm
{
private:
	//Private functions
	void mergeSort(int left, int right);
	void merge(int left, int middle, int right);

protected:
	void sort() override;

public:
	MergeSort();
};
