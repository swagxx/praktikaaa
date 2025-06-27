#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int age;
    char choice;

    do {
        cout << "Введите возраст: ";
        cin >> age;

        int lastDigit = age % 10;
        int lastTwoDigits = age % 100;

        cout << "Вам " << age << " ";

        if (lastTwoDigits >= 11 && lastTwoDigits <= 14) {
            cout << "лет";
        }
        else {
            switch (lastDigit) {
                case 1:
                    cout << "год";
                    break;
                case 2:
                case 3:
                case 4:
                    cout << "года";
                    break;
                default:
                    cout << "лет";
            }
        }

        cout << "." << endl;

        cout << "Хотите ввести другой возраст? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
