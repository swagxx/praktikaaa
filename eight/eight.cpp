#include <iostream>
using namespace std;


bool isSymmetric(int** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i])
                return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "Введите количество строк и столбцов (n и m): ";
    cin >> n >> m;

    if (n != m) {
        cout << "Матрица не квадратная. Симметрия невозможна." << endl;
        return 0;
    }


    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];


    cout << "Введите элементы матрицы (" << n << " x " << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];


    if (isSymmetric(a, n))
        cout << "Матрица симметрична относительно главной диагонали.\n";
    else
        cout << "Матрица НЕ симметрична.\n";


    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
