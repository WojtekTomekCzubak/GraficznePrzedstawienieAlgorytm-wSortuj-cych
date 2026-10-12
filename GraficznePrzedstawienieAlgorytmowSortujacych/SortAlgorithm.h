#pragma once

#include "ExampleData.h"

#include <initializer_list>
#include <string>

class SortAlgorithm
{
	/*
		Base class for every sorting algorithm.
		It keeps graphic data and does all of the drawing, so derived classes contain only the algorithm itself.
	*/

private:
	//Private variables
	std::string name;
	std::vector<sf::RectangleShape> shapes;
	sf::RenderWindow* window;
	int delayIndex; //Index in STEP_DELAYS (SortAlgorithm.cpp) - speed of the animation.
	bool paused;

	//Private functions
	void initVariables();
	void initShapes();
	void pollEvents();
	void wait();
	void updateTitle();

protected:
	//Sorting algorithm - every derived class has its own.
	virtual void sort() = 0;

	//Functions used by sorting algorithms
	int size() const;
	float height(int index) const;
	void setHeight(int index, float newHeight);
	void swapBars(int index1, int index2);
	void showStep(std::initializer_list<int> highlighted);

public:
	//Cons / Des
	explicit SortAlgorithm(const std::string& algorithmName);
	virtual ~SortAlgorithm();

	//Public functions
	void run(sf::RenderWindow& target);
	void render(sf::RenderTarget& target) const;
};
