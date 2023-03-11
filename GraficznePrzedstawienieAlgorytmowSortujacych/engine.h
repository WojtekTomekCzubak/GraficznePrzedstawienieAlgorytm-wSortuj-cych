#pragma once

#include "BubbleSort.h"
#include "CombSort.h"
#include "ShakeSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "MergeSort.h"

#include <vector>
#include <thread>

class Engine
{
	/*
		Engine for the app.
	*/

private:
	BubbleSort* bubbleSort; //Pointer do obiektu klasy BubbleSort aby móc zainicjalizowaæ go jako nullptr.
	CombSort* combSort;
	ShakeSort* shakeSort;
	InsertionSort* insertionSort;
	SelectionSort* selectionSort;
	QuickSort* quickSort;
	ShellSort* shellSort;
	HeapSort* heapSort;
	MergeSort* mergeSort;

	int choice; //Zmienna s³u¿¹ca do wyboru algorytmu.

	sf::RenderWindow *window;

	//Private functions
	void initVariables();
	void makeDecision();
	void switcher();
	void initWindow();
	void updatePollEvents();
	void gameLoop(int choose);
	

public:
	Engine();
	virtual ~Engine();

	//Initlization rest of the classes
	void initBubbleSort(); //Funckja inicjalizuj¹ca klasê BubbleSort ze wzglêdu na optymalizacje i wczeœniejsze zainicjalizowanie jako nullptr.
	void initCombSort();
	void initShakeSort();
	void initInsertionSort();
	void initSelectionSort();
	void initQuickSort();
	void initShellSort();
	void initHeapSort();
	void initMergeSort();

	void update();
	void render(int choose);
};

