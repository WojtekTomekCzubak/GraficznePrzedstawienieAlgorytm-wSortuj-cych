/*
	std::vector<int> shapes = {8, 11, 2, 6, 4, 8, 3, 9, 0};

	int n = shapes.size();

	for (int i : shapes) std::cout << i << " ";

	std::cout << std::endl;

	for (int i = n / 2 - 1; i >= 0; i--) { //nale¿y dodaæ dwa elementy aby index ostatniego rodzica siê zmniejszy³.
		validateMaxHeap(shapes, n, i); //tworzymy pierwszy maksymalny kopiec.
	}

	for (int i = n - 1; i > 0; i--) {
		swapik(shapes, 0, i); //swapujemy ostatni element z pierwszym
		validateMaxHeap(shapes, --n, 0); //tworzymy maksymalny kopiec bez ostatniego elementu bo mamy pewnosc ze jest na odpowiedniej pozycji z odpowiednia wartoscia
	}

	for (int i : shapes) std::cout << i << " ";

	std::cout << std::endl;
	*/

#include "HeapSort.h"

//Private functions
void HeapSort::validateMaxHeap(int heapSize, int parentIndex)
{
	/*
	* @return void.
	*
	* Moves parent down until it is higher than both of its children (max heap).
	*/

	int maxIndex = parentIndex;
	int leftChild = parentIndex * 2 + 1;
	int rightChild = parentIndex * 2 + 2;

	if (leftChild < heapSize && this->height(leftChild) > this->height(maxIndex)) {
		maxIndex = leftChild;
	}

	if (rightChild < heapSize && this->height(rightChild) > this->height(maxIndex)) {
		maxIndex = rightChild;
	}

	if (maxIndex != parentIndex) {
		this->swapBars(maxIndex, parentIndex);
		this->validateMaxHeap(heapSize, maxIndex);
	}
}

//Cons / Des
HeapSort::HeapSort()
	: SortAlgorithm("HeapSort")
{
}

//Protected functions
void HeapSort::sort()
{
	int n = this->size();

	for (int i = n / 2 - 1; i >= 0; i--) {
		this->validateMaxHeap(n, i);
	}

	for (int i = n - 1; i > 0; i--) {
		this->swapBars(0, i);
		this->validateMaxHeap(i, 0);
	}
}
