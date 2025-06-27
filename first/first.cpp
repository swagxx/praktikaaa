#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double number;

    cout << "Введите вещественное число: ";
    cin >> number;

    int integerPart = static_cast<int>(number);
    double fractionalPart = number - integerPart;
    double rounded = round(number);

    cout << "Целая часть: " << integerPart << endl;
    cout << "Дробная часть: " << fractionalPart << endl;
    cout << "Округлённое значение: " << rounded << endl;

    return 0;
}
