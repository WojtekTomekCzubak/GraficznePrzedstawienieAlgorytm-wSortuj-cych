#pragma once

#include "SortAlgorithm.h"

class ShakeSort : public SortAlgorithm
{
protected:
	void sort() override;

public:
	ShakeSort();
};
