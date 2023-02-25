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
        std::cout << choice;
        break;
    case 3:
        std::cout << choice;
        break;
    case 4:
        std::cout << choice;
        break;
    case 5:
        std::cout << choice;
        break;
    case 6:
        std::cout << choice;
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
    this->window->setFramerateLimit(190);
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
        this->bubbleSort = new BubbleSort();
    }
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
    case 0:
        break;
    case 1:   
        this->bubbleSort->render(*this->window);
    }

    this->window->display();
}
