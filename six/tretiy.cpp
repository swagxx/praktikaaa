#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandomArray(int* arr, int size, int minVal, int maxVal) {
    srand(time(0)); 
    for (int i = 0; i < size; ++i) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

int* filterElements(const int* source, int size, int& newSize) {
    newSize = 0;
    for (int i = 0; i < size; ++i) {
        if ((source[i] >= -5 && source[i] <= -2) || (source[i] >= 2 && source[i] <= 5)) {
            newSize++;
        }
    }

    int* filtered = new int[newSize];

    int index = 0;
    for (int i = 0; i < size; ++i) {
        if ((source[i] >= -5 && source[i] <= -2) || (source[i] >= 2 && source[i] <= 5)) {
            filtered[index++] = source[i];
        }
    }

    return filtered;
}
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "Введите размер массива: ";
    cin >> size;


    int* originalArray = new int[size];


    generateRandomArray(originalArray, size, -10, 10);

    cout << "Исходный массив: ";
    printArray(originalArray, size);

    int filteredSize;
    int* filteredArray = filterElements(originalArray, size, filteredSize);

    cout << "Отфильтрованный массив (элементы в [-5;-2] или [2;5]): ";
    printArray(filteredArray, filteredSize);

    delete[] originalArray;
    delete[] filteredArray;

    return 0;
}