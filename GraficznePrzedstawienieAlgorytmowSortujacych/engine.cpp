#include "engine.h"

#include <iostream>
#include <limits>

//Private functions

int Engine::makeDecision()
{
    /*
        @return int.

        Decision maker for user which sort algorithm he wants to use.
    */

    std::cout << std::endl
        << "Witaj w programie do graficznego przedstawiania algorytmow!" << std::endl
        << "Wybierz interesujacy ciebie algorytm:" << std::endl
        << "1. BubbleSort" << std::endl
        << "2. CombSort" << std::endl
        << "3. ShakeSort" << std::endl
        << "4. InsertionSort" << std::endl
        << "5. SelectionSort" << std::endl
        << "6. QuickSort" << std::endl
        << "7. ShellSort" << std::endl
        << "8. HeapSort" << std::endl
        << "9. MergeSort" << std::endl
        << "0. Wyjscie" << std::endl;

    std::cout << "Wpisz numer wybranej opcji: ";

    int choice = 0;

    while (!(std::cin >> choice)) {
        if (std::cin.eof()) return 0;

        //Not a number - clear the error and skip the rest of the line.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "To nie jest liczba, sprobuj jeszcze raz: ";
    }

    return choice;
}

std::unique_ptr<SortAlgorithm> Engine::createAlgorithm(int choice)
{
    /*
        @return std::unique_ptr<SortAlgorithm>.

        Creates sorting algorithm which user picked (nullptr if there is no such option).
        unique_ptr deletes the object by itself, so there are no memory leaks.
    */

    switch (choice) {
    case 1: return std::make_unique<BubbleSort>();
    case 2: return std::make_unique<CombSort>();
    case 3: return std::make_unique<ShakeSort>();
    case 4: return std::make_unique<InsertionSort>();
    case 5: return std::make_unique<SelectionSort>();
    case 6: return std::make_unique<QuickSort>();
    case 7: return std::make_unique<ShellSort>();
    case 8: return std::make_unique<HeapSort>();
    case 9: return std::make_unique<MergeSort>();
    default: return nullptr;
    }
}

void Engine::initWindow()
{
    /*
    * @return void.
    *
    * Initlizing window.
    */

    this->window.create(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Graficzne przedstawienie algorytmow sortujacych", sf::Style::Close | sf::Style::Titlebar);
}

void Engine::updatePollEvents()
{
    /*
    * @return void.
    *
    * Function close window if user click "Close" button or press Escape.
    */

    sf::Event e;

    while (this->window.pollEvent(e)) {
        if (e.type == sf::Event::Closed) this->window.close();
        if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) this->window.close();
    }
}

void Engine::gameLoop(const SortAlgorithm& algorithm)
{
    /*
    * @return void.
    *
    * Game loop - shows sorted data until window is closed.
    */

    this->window.setFramerateLimit(60);

    while (this->window.isOpen()) {
        this->update();
        this->render(algorithm);
    }
}

void Engine::update()
{
    this->updatePollEvents();
}

void Engine::render(const SortAlgorithm& algorithm)
{
    this->window.clear();
    algorithm.render(this->window);
    this->window.display();
}

//Public functions

void Engine::run()
{
    /*
        @return void.

        Main loop of the program: menu -> sorting animation -> menu ... until user picks 0.
    */

    while (true) {
        int choice = this->makeDecision();

        if (choice == 0) break;

        std::unique_ptr<SortAlgorithm> algorithm = this->createAlgorithm(choice);

        if (algorithm == nullptr) {
            std::cout << "Nie ma takiej opcji!" << std::endl;
            continue;
        }

        std::cout << "Sterowanie w oknie: [Gora/Dol] predkosc, [Spacja] pauza, [Esc] przerwij / powrot do menu" << std::endl;

        this->initWindow();
        algorithm->run(this->window);
        this->gameLoop(*algorithm);
    }
}
