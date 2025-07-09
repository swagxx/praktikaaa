#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;


struct Product {
    string name;
    double totalQuantity = 0;
    double totalRevenue = 0;
    double averagePrice = 0;
};

int main() {
    setlocale(LC_ALL, "Russian");
    const string filename = "ten/sales.txt";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return 1;
    }

    map<string, Product> products;
    string productName;
    double quantity, price;

    while (inputFile >> productName >> quantity >> price) {
        Product& p = products[productName];
        p.name = productName;
        p.totalQuantity += quantity;
        p.totalRevenue += quantity * price;
    }
    inputFile.close();


    for (map<string, Product>::iterator it = products.begin(); it != products.end(); ++it) {
        if (it->second.totalQuantity > 0)
            it->second.averagePrice = it->second.totalRevenue / it->second.totalQuantity;
    }

    vector<Product> productList;
    for (map<string, Product>::const_iterator it = products.begin(); it != products.end(); ++it) {
        productList.push_back(it->second);
    }

    sort(productList.begin(), productList.end(),
        [](const Product& a, const Product& b) {
            return a.totalQuantity > b.totalQuantity;
        });


    if (!productList.empty()) {
        cout << "=== Результаты по популярности ===" << endl;
        cout << "Наиболее популярный товар: " << productList.front().name
            << " (" << productList.front().totalQuantity << " ед.)" << endl;
        cout << "Наименее популярный товар: " << productList.back().name
            << " (" << productList.back().totalQuantity << " ед.)" << endl;
    }

    sort(productList.begin(), productList.end(),
        [](const Product& a, const Product& b) {
            return a.totalRevenue > b.totalRevenue;
        });

    if (!productList.empty()) {
        cout << "\n=== Результаты по прибыльности ===" << endl;
        cout << "Самый прибыльный товар: " << productList.front().name
            << " (" << fixed << setprecision(2) << productList.front().totalRevenue << " руб.)" << endl;
        cout << "Наименее прибыльный товар: " << productList.back().name
            << " (" << fixed << setprecision(2) << productList.back().totalRevenue << " руб.)" << endl;
    }

    cout << "\n=== Подробная статистика ===" << endl;
    cout << left << setw(15) << "Товар"
        << setw(15) << "Количество"
        << setw(15) << "Средняя цена"
        << setw(15) << "Выручка" << endl;

    for (size_t i = 0; i < productList.size(); ++i) {
        const Product& product = productList[i];
        cout << left << setw(15) << product.name
            << setw(15) << fixed << setprecision(2) << product.totalQuantity
            << setw(15) << product.averagePrice
            << setw(15) << product.totalRevenue << endl;
    }

    return 0;
}
