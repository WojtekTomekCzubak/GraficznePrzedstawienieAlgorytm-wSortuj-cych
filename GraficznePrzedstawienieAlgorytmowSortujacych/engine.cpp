#include "engine.h"

//Private functions

void Engine::initVariables()
{
    /*
        @return void.

        Initlize variables for better performance.
        Zainicjalizowana.
    */

    this->choice = 0;
    this->window = nullptr;
}

void Engine::makeDecision()
{
    /*
        @return int.

        Decision maker for user which sort algorythm he want to use.
        Zainicjalizowana.
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
        Zainicjalizowana.
    */
    
    switch (this->choice) {
    case 1:
        this->initWindow();
        this->gameLoop();
        this->bubbleSort.bubbleSortingFunction();
        this->initWindow();
        this->gameLoop();
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
    * Niezainicjalizowana.
    */

    this->window = new sf::RenderWindow(sf::VideoMode(600, 600), "Graficzne przedstawienie algorytmow sortujacych", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
}

void Engine::updatePollEvents()
{
    sf::Event e;

    while (this->window->pollEvent(e)) {
        if (e.type == sf::Event::Closed) this->window->close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) this->window->close();
    }
}

void Engine::gameLoop()
{
    while (this->window->isOpen()) {
        this->update();
        this->render();
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
    //this->bubbleSort.bubbleSortingFunction();
    //this->initWindow();
    //this->gameLoop();
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

void Engine::render()
{
    /*
        Zainicjalizowana.
    */

    this->window->clear();

    this->bubbleSort.render(*this->window);

    this->window->display();
}
