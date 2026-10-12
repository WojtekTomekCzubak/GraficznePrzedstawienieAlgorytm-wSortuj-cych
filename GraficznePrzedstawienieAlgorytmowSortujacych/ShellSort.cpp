#include "ShellSort.h"

//Cons / Des
ShellSort::ShellSort()
	: SortAlgorithm("ShellSort")
{
}

//Protected functions
void ShellSort::sort()
{
	/*
	for (int gap = shapes.size() / 2; gap > 0; gap /= 2) { //tworzymy int gap ktory jest roznica pomiedzy miejscami oraz sprawdzamy czy jest wiekszy niz 0
        for (int i = gap; i < shapes.size(); i++) { //prawidlowa petla
            int temp = shapes[i];//przyjmujemy dane miejsce w tabeli jako temporary
            int j; //tworzymy int j jako dana do itercji petli i ponownego uzytku poza petla
            for (j = i; j >= gap && shapes[j - gap] > temp; j -= gap) { //przyjmujemy ze j jest rowne i i sprawdzamy czy miejsce j - gap jest wieksze niz obecna dana
                shapes[j] = shapes[j-gap]; //jezeli warunek sie spelnia dokonujemy zamiany
            }
            shapes[j] = temp;
        }
    }
	*/

	for (int gap = this->size() / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < this->size(); i++) {
			float temp = this->height(i);
			int j;

			for (j = i; j >= gap && this->height(j - gap) > temp; j -= gap) {
				this->setHeight(j, this->height(j - gap));
				this->showStep({ j, j - gap });
			}

			if (j != i) {
				this->setHeight(j, temp);
				this->showStep({ j });
			}
		}
	}
}
