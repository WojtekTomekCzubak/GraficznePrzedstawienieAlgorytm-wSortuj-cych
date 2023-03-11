#include "engine.h"

//Private functions

void Engine::initVariables()
{
    /*
        @return void.

        Initlize variables for better performance.
    */

    this->choice = 0;
    this->window = nullptr;
    this->bubbleSort = nullptr;
    this->combSort = nullptr;
    this->shakeSort = nullptr;
    this->insertionSort = nullptr;
    this->selectionSort = nullptr;
    this->quickSort = nullptr;
    this->shellSort = nullptr;
    this->heapSort = nullptr;
    this->mergeSort = nullptr;
}

void Engine::makeDecision()
{
    /*
        @return int.

        Decision maker for user which sort algorythm he want to use.
    */

    std::cout << "Witaj w programie do graficznego przedstawiania algorytmow!" << std::endl
        << "Wybierz interesujacy ciebie algorytm:" << std::endl
        << "1. BubbleSort" << std::endl
        << "2. CombSort" << std::endl
        << "3. ShakeSort" << std::endl
        << "4. InsertionSort" << std::endl
        << "5. SelectionSort" << std::endl
        << "6. QucikSort" << std::endl
        << "7. ShellSort" << std::endl
        << "8. HeapSort" << std::endl
        << "9. MergeSort" << std::endl;

    std::cout << "Type the number of your choice: ";
    std::cin >> this->choice;

    this->switcher();
}

void Engine::switcher()
{
    /*
        @return void.

        Trigger this sorting algorithm which user picked.
    */
    
    switch (this->choice) {
    case 1:
        this->initWindow();
        this->initBubbleSort();
        this->bubbleSort->bubbleSortingFunction(*this->window);
        this->gameLoop(1);
        this->bubbleSort = nullptr;
        this->makeDecision();
        break;
    case 2:
        this->initWindow();
        this->initCombSort();
        this->combSort->combSortingFunction(*this->window);
        this->gameLoop(2);
        this->combSort = nullptr;
        this->makeDecision();
        break;
    case 3:
        this->initWindow();
        this->initShakeSort();
        this->shakeSort->shakeSortFunction(*this->window);
        this->gameLoop(3);
        this->shakeSort = nullptr;
        this->makeDecision();
        break;
    case 4:
        this->initWindow();
        this->initInsertionSort();
        this->insertionSort->insertionSortFunction(*this->window);
        this->gameLoop(4);
        this->insertionSort = nullptr;
        this->makeDecision();
        break;
    case 5:
        this->initWindow();
        this->initSelectionSort();
        this->selectionSort->selectionSortFunction(*this->window);
        this->gameLoop(5);
        this->selectionSort = nullptr;
        this->makeDecision();
        break;
    case 6:
        this->initWindow();
        this->initQuickSort();
        this->quickSort->initQuickSortFunction(*this->window);
        this->gameLoop(6);
        this->quickSort = nullptr;
        this->makeDecision();
        break;
    case 7:
        this->initWindow();
        this->initShellSort();
        this->shellSort->shellSortFunction(*this->window);
        this->gameLoop(7);
        this->shellSort = nullptr;
        this->makeDecision();
        break;
    case 8:
        this->initWindow();
        this->initHeapSort();
        this->heapSort->heapSortFunction(*this->window);
        this->gameLoop(8);
        this->heapSort = nullptr;
        this->makeDecision();
    case 9:
        this->initWindow();
        this->initMergeSort();
        this->mergeSort->mergeSortFunction(*this->window);
        this->gameLoop(9);
        this->mergeSort = nullptr;
        this->makeDecision();
    default:
        break;
    }
}

void Engine::initWindow()
{
    /*
    * @return void.
    * 
    * Initlizing window.
    * Framerate set at 190 bcs of problems with rendering.
    */

    this->window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Graficzne przedstawienie algorytmow sortujacych", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(20);
}

void Engine::updatePollEvents()
{
    /*
    * @return void.
    * 
    * Function close window if user click "Close" button.
    */

    sf::Event e;

    while (this->window->pollEvent(e)) {
        if (e.type == sf::Event::Closed) this->window->close();
    }
}

void Engine::gameLoop(int choose)
{
    /*
    * @return void.
    * 
    * Game loop.
    */

    while (this->window->isOpen()) {
        this->update();
        this->render(choose);
    }
}

void Engine::initBubbleSort()
{
    /*
    * @return void.
    * 
    * Initialize BubbleSort class.
    */

    if (bubbleSort == nullptr) this->bubbleSort = new BubbleSort(*this->window);
    
}

void Engine::initCombSort()
{
    /*
    * @return void.
    *
    * Initialize CombSort class.
    */

    if (combSort == nullptr) this->combSort = new CombSort(*this->window);
    
}

void Engine::initShakeSort()
{
    if (this->shakeSort == nullptr) this->shakeSort = new ShakeSort(*this->window);
    
}

void Engine::initInsertionSort()
{
    if (insertionSort == nullptr) this->insertionSort = new InsertionSort(*this->window);
}

void Engine::initSelectionSort()
{
    if (this->selectionSort == nullptr) this->selectionSort = new SelectionSort(*this->window);
}

void Engine::initQuickSort()
{
    if (this->quickSort == nullptr) this->quickSort = new QuickSort(*this->window);
}

void Engine::initShellSort()
{
    if (this->shellSort == nullptr) this->shellSort = new ShellSort();
}

void Engine::initHeapSort()
{
    if (this->heapSort == nullptr) this->heapSort = new HeapSort();
}

void Engine::initMergeSort()
{
    if (this->mergeSort == nullptr) this->mergeSort = new MergeSort();
}

//Cons / Des
Engine::Engine()
{
	/*
		Constructor
	*/

    this->initVariables();
    this->makeDecision();
}

Engine::~Engine()
{
	/*
		Destructor
	*/

    delete this->window;
}

void Engine::update()
{
    
    /*
        Zainicjalizowana.
    */

    this->updatePollEvents();
}

void Engine::render(int choose)
{
    /*
        Zainicjalizowana.
    */

    this->window->clear();

    switch (choose)
    {
    case 1:
        this->bubbleSort->render(*this->window);
        break;
    case 2:
        this->combSort->render(*this->window);
        break;
    case 3:
        this->shakeSort->render(*this->window);
        break;
    case 4:
        this->insertionSort->render(*this->window);
        break;
    case 5:
        this->selectionSort->render(*this->window);
        break;
    case 6:
        this->quickSort->render(*this->window);
        break;
    case 7:
        this->shellSort->render(*this->window);
    case 8:
        this->heapSort->render(*this->window);
        break;
    case 9:
        this->mergeSort->render(*this->window);
    default:
        break;
    }

    this->window->display();
}
