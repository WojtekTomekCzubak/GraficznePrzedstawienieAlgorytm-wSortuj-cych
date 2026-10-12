#pragma once

#include "SortAlgorithm.h"

class SelectionSort : public SortAlgorithm
{
protected:
	void sort() override;

public:
	SelectionSort();
};
