#include <iostream>
#include <vector>

using namespace std;

void inputArray(vector<int>& arr) {
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    arr.resize(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

void outputArray(const vector<int>& arr) {
    cout << "Массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}


bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}


void insertToSortedArray(vector<int>& arr, int value) {

    size_t pos = 0;
    while (pos < arr.size() && arr[pos] < value) {
        ++pos;
    }


    arr.insert(arr.begin() + pos, value);
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> arr;


    inputArray(arr);


    outputArray(arr);

    if (isSorted(arr)) {
        cout << "Массив упорядочен по возрастанию." << endl;


        int value;
        cout << "Введите значение для вставки: ";
        cin >> value;

        insertToSortedArray(arr, value);
        cout << "После вставки: ";
        outputArray(arr);
    }
    else {
        cout << "Массив не упорядочен по возрастанию." << endl;
    }

    return 0;
}