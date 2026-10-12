#pragma once

#include "SortAlgorithm.h"

class InsertionSort : public SortAlgorithm
{
protected:
	void sort() override;

public:
	InsertionSort();
};
