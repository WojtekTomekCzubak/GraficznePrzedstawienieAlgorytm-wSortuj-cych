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
        << "6. QucikSort" << std::endl;

    std::cout << "Type the number of your choice: ";
    std::cin >> this->choice;
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
        delete this->bubbleSort;
        break;
    case 2:
        this->initWindow();
        this->initCombSort();
        this->combSort->combSortingFunction(*this->window);
        this->gameLoop(2);
        delete this->combSort;
        break;
    case 3:
        this->initWindow();
        this->initShakeSort();
        this->shakeSort->shakeSortFunction(*this->window);
        this->gameLoop(3);
        delete this->shakeSort;
        break;
    case 4:
        this->initWindow();
        this->initInsertionSort();
        this->insertionSort->insertionSortFunction(*this->window);
        this->gameLoop(4);
        delete this->insertionSort;
        break;
    case 5:
        this->initWindow();
        this->initSelectionSort();
        this->selectionSort->selectionSortFunction(*this->window);
        this->gameLoop(5);
        delete this->selectionSort;
        break;
    case 6:
        this->initWindow();
        this->initQuickSort();
        this->quickSort->initQuickSortFunction(*this->window);
        this->gameLoop(6);
        delete this->quickSort;
        break;
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

    if (bubbleSort == nullptr) {
        this->bubbleSort = new BubbleSort(*this->window);
    }
}

void Engine::initCombSort()
{
    /*
    * @return void.
    *
    * Initialize CombSort class.
    */

    if (combSort == nullptr) {
        this->combSort = new CombSort(*this->window);
    }
}

void Engine::initShakeSort()
{
    if (this->shakeSort == nullptr) this->shakeSort = new ShakeSort(*this->window);
    
}

void Engine::initInsertionSort()
{
    if (insertionSort == nullptr)
        this->insertionSort = new InsertionSort(*this->window);
}

void Engine::initSelectionSort()
{
    if (this->selectionSort == nullptr) this->selectionSort = new SelectionSort(*this->window);
}

void Engine::initQuickSort()
{
    if (this->quickSort == nullptr) this->quickSort = new QuickSort(*this->window);
}

//Cons / Des
Engine::Engine()
{
	/*
		Constructor
	*/

    this->initVariables();
    this->makeDecision();
    this->switcher();
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
    default:
        break;
    }


    this->window->display();
}
