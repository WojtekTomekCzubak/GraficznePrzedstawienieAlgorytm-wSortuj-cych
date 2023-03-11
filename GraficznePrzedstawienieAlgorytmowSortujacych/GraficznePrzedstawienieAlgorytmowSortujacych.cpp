#include "engine.h"

void printArray(std::vector<int> arr), merge(std::vector<int>& arr, int left, int middle, int right);
void mergeSort(std::vector<int>& arr, int left, int right);

int main()
{
    srand(static_cast<unsigned>(time(0)));

    /*
    //---------MERGE SORT---------
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    std::cout << "Given array: ";
    printArray(arr);
    std::system("PAUSE");

    mergeSort(arr, 0, arr.size()-1);

    std::cout << std::endl << "Sorted array: ";
    printArray(arr);

    //---------KONIEC---------
    */

    Engine engine; 

    return 0;
}

void merge(std::vector<int> &arr, int left, int middle, int right) 
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::cout << middle << std::endl;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right) {
        int middle = (left + right - 1) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

/*---------Wyświetlanie tablicy---------*/
void printArray(std::vector<int> arr)
{
    for (int i : arr)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}