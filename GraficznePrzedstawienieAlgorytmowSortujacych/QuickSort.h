#pragma once

#include "SortAlgorithm.h"

class QuickSort : public SortAlgorithm
{
private:
	//Private functions
	void quickSortFunction(int start, int end);

protected:
	void sort() override;

public:
	QuickSort();
};
