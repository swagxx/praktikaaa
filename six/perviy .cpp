#include <iostream>
using namespace std;

const int SIZE = 10;


int countInIntervals(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if ((arr[i] >= -5 && arr[i] <= -2) || (arr[i] >= 2 && arr[i] <= 5)) {
            count++;
        }
    }
    return count;
}

int sumOutsideIntervals(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (!((arr[i] >= -5 && arr[i] <= -2) || (arr[i] >= 2 && arr[i] <= 5))) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[SIZE] = { -6, -3, -2, 0, 1, 3, 6, 8, 5, -7 };

    cout << "Массив: ";
    for (int i = 0; i < SIZE; ++i)
        cout << arr[i] << " ";
    cout << endl;

    int count = countInIntervals(arr, SIZE);
    int sum = sumOutsideIntervals(arr, SIZE);

    cout << "Количество элементов в интервалах [-5;-2] и [2;5]: " << count << endl;
    cout << "Сумма элементов вне этих интервалов: " << sum << endl;

    return 0;
}
