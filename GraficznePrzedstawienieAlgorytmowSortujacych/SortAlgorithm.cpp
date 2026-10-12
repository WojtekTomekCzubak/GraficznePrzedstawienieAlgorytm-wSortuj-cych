#include "SortAlgorithm.h"

namespace
{
	//Delays between steps of sorting (in milliseconds), changed with arrow keys.
	const int STEP_DELAYS[] = { 0, 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };
	const int STEP_DELAYS_COUNT = static_cast<int>(sizeof(STEP_DELAYS) / sizeof(STEP_DELAYS[0]));
	const int DEFAULT_DELAY_INDEX = 6; //50 ms - the same speed as old framerate limit (20 fps).

	//Thrown when user closes the window in the middle of sorting.
	//It gets out of every sorting function at once, also from recursive ones (QuickSort, HeapSort, MergeSort).
	struct SortAborted {};
}

//Private functions
void SortAlgorithm::initVariables()
{
	this->window = nullptr;
	this->delayIndex = DEFAULT_DELAY_INDEX;
	this->paused = false;
}

void SortAlgorithm::initShapes()
{
	this->shapes = ExampleData().dataAccess();
}

void SortAlgorithm::pollEvents()
{
	/*
	* @return void.
	*
	* Handles events in the middle of sorting.
	* Without it window freezes ("Not responding") and can't be closed until sorting ends.
	*/

	sf::Event e;

	while (this->window->pollEvent(e)) {
		if (e.type == sf::Event::Closed ||
			(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)) {
			this->window->close();
			throw SortAborted();
		}

		if (e.type == sf::Event::KeyPressed) {
			switch (e.key.code) {
			case sf::Keyboard::Up:
				if (this->delayIndex > 0) this->delayIndex--;
				break;
			case sf::Keyboard::Down:
				if (this->delayIndex < STEP_DELAYS_COUNT - 1) this->delayIndex++;
				break;
			case sf::Keyboard::Space:
				this->paused = !this->paused;
				break;
			default:
				break;
			}

			this->updateTitle();
		}
	}
}

void SortAlgorithm::wait()
{
	/*
	* @return void.
	*
	* Slows down the animation without freezing the window.
	* One long sf::sleep() (or a loop without pollEvent) freezes it, because system thinks the program doesn't respond,
	* so we wait in small pieces and handle events all the time.
	*/

	sf::Clock clock;

	this->pollEvents();

	while (this->paused || clock.getElapsedTime() < sf::milliseconds(STEP_DELAYS[this->delayIndex])) {
		sf::sleep(sf::milliseconds(1));
		this->pollEvents();
	}
}

void SortAlgorithm::updateTitle()
{
	std::string title = this->name + " | opoznienie: " + std::to_string(STEP_DELAYS[this->delayIndex]) + " ms";

	if (this->paused) title += " | PAUZA";

	title += " | [Gora/Dol] predkosc, [Spacja] pauza, [Esc] przerwij";

	this->window->setTitle(title);
}

//Protected functions
int SortAlgorithm::size() const
{
	return static_cast<int>(this->shapes.size());
}

float SortAlgorithm::height(int index) const
{
	return this->shapes[index].getSize().y;
}

void SortAlgorithm::setHeight(int index, float newHeight)
{
	/*
	* @return void.
	*
	* Changes height of the bar. Bars stand on the bottom of the window, so position has to be changed too.
	*/

	this->shapes[index].setSize(sf::Vector2f(BAR_WIDTH, newHeight));
	this->shapes[index].setPosition(sf::Vector2f(this->shapes[index].getPosition().x, WINDOW_SIZE - newHeight));
}

void SortAlgorithm::swapBars(int index1, int index2)
{
	float tempHeight = this->height(index1);

	this->setHeight(index1, this->height(index2));
	this->setHeight(index2, tempHeight);

	this->showStep({ index1, index2 });
}

void SortAlgorithm::showStep(std::initializer_list<int> highlighted)
{
	/*
	* @return void.
	*
	* Draws current state of data with highlighted (red) bars and waits before next step.
	*/

	for (int index : highlighted) this->shapes[index].setFillColor(sf::Color::Red);

	this->window->clear();
	this->render(*this->window);
	this->window->display();

	for (int index : highlighted) this->shapes[index].setFillColor(sf::Color::White);

	this->wait();
}

//Cons / Des
SortAlgorithm::SortAlgorithm(const std::string& algorithmName)
	: name(algorithmName)
{
	this->initVariables();
	this->initShapes();
}

SortAlgorithm::~SortAlgorithm()
{
}

//Public functions
void SortAlgorithm::run(sf::RenderWindow& target)
{
	/*
	* @return void.
	*
	* Runs sorting algorithm with animation in given window.
	* When sorting ends all bars are green.
	*/

	this->window = &target;
	this->window->setFramerateLimit(0); //Speed of the animation is controlled by wait().
	this->updateTitle();

	try {
		this->sort();

		for (sf::RectangleShape& shape : this->shapes) shape.setFillColor(sf::Color::Green);

		this->window->setTitle(this->name + " | posortowano! | [Esc] powrot do menu");
	}
	catch (const SortAborted&) {
		//Window was closed in the middle of sorting - nothing more to do.
	}

	this->window = nullptr;
}

void SortAlgorithm::render(sf::RenderTarget& target) const
{
	for (const sf::RectangleShape& shape : this->shapes) target.draw(shape);
}
