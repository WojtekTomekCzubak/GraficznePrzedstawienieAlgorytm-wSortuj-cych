#pragma once

#include "SortAlgorithm.h"

class BubbleSort : public SortAlgorithm
{
protected:
	void sort() override;

public:
	BubbleSort();
};
