#pragma once

#include "SortAlgorithm.h"

class ShellSort : public SortAlgorithm
{
protected:
	void sort() override;

public:
	ShellSort();
};
