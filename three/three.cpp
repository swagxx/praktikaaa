#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    while (true) {
        int a, b;
        cout << "Введите два натуральных числа (a и b): ";
        cin >> a >> b;


        if (a <= 0 || b <= 0) {
            cout << "Оба числа должны быть натуральными. Повторите ввод.\n";
            continue;
        }

        int originalA = a, originalB = b;

        while (a != b) {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }

        cout << "НОД(" << originalA << ", " << originalB << ") = " << a << "\n";

        char again;
        cout << "Повторить? (y/n): ";
        cin >> again;
        if (again != 'y' && again != 'Y') break;

        cout << endl;
    }

    return 0;
}
