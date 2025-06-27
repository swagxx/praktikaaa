#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double S(double x, double epsilon) {
    double sum = 0.0;
    double term = x; 
    int n = 1;       

    while (abs(term) >= epsilon) {
        sum += term;
        n++;
        term = pow(-1, n + 1) * x / n;
    }

    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double epsilon;
    cout << "Введите точность эпсилон: ";
    cin >> epsilon;

    cout << "x\tS(x, эпсилон)" << endl;
    cout << fixed << setprecision(6);

    for (double x = -0.5; x <= 0.5; x += 0.1) {
        double result = S(x, epsilon);
        cout << x << "\t" << result << endl;
    }

    return 0;
}