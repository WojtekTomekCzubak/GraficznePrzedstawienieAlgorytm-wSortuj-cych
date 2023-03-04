#include "engine.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));

    Engine engine;

    return 0;
}

/*std::vector<int> vec = {9, 2, 5, 1, 6, 10, 8};

int a;

for (int i : vec) std::cout << i << " ";

std::cout << std::endl;

for (int i = 0; i < vec.size(); i++) {
    a = i;

    for (int j = i + 1; j < vec.size(); j++)
        if (vec[a] > vec[j]) a = j;

    int change = vec[a];
    vec[a] = vec[i];
    vec[i] = change;
}

for (int i : vec) std::cout << i << " ";*/