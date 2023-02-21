#include "engine.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));

    Engine engine;

    return 0;
}

/* std::vector<sf::RectangleShape> shapes;
    sf::RectangleShape shape;

    shape.setFillColor(sf::Color::White);
    shape.setSize(sf::Vector2f(20, 200));
    shape.setPosition(sf::Vector2f(0, 500));
    shapes.push_back(shape);

    shape.setFillColor(sf::Color::White);
    shape.setSize(sf::Vector2f(20, 400));
    shape.setPosition(sf::Vector2f(30, 500));
    shapes.push_back(shape);

    shape.setFillColor(sf::Color::White);
    shape.setSize(sf::Vector2f(20, 100));
    shape.setPosition(sf::Vector2f(50, 500));
    shapes.push_back(shape);

    for (sf::RectangleShape i : shapes) {
        std::cout << i.getPosition().x << " " << i.getSize().y << std::endl;
    }

    std::cout << "------------------" << std::endl;

    for (int i = 0; i < shapes.size() - 1; i++) {
        for (int j = 0; j < shapes.size() - i - 1; j++) {
            if (shapes[j].getSize().y > shapes[j + 1].getSize().y) {
                sf::Vector2f change = shapes[j].getPosition();
                std::swap(shapes[j], shapes[j + 1]);
                shapes[j + 1].setPosition(shapes[j].getPosition());
                shapes[j].setPosition(change.x, 0.f);
            }
        }
    }

    for (sf::RectangleShape i : shapes) {
        std::cout << i.getPosition().x << " " << i.getSize().y << std::endl;
    } */

/* std::vector<int> arr = {5, 3, 8, 10, 2};
    int arrSize = arr.size();

    for (int i : arr) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i : arr) {
        std::cout << i << " ";
    } */
