#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double initial_amount;
    const double interest_rate = 0.06;
    const double inflation_rate = 0.035;

    cout << "Введите начальную сумму вклада (в рублях): ";
    cin >> initial_amount;

    double current_amount = initial_amount;

    cout << fixed << setprecision(2);
    cout << "\nГод\tСумма на счете\tРеальная стоимость\n";

    for (int year = 1; year <= 10; year++) {
        current_amount *= (1 + interest_rate);
        double real_value = current_amount / pow(1 + inflation_rate, year);

        cout << year << "\t" << current_amount << "\t\t" << real_value << endl;
    }

    return 0;
}
