#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string text;
    char symbol;

    cout << "Введите строку: ";
    getline(cin, text); 

    cout << "Введите символ для поиска: ";
    cin >> symbol; 

    size_t first_pos = text.find(symbol);
    size_t last_pos = text.rfind(symbol);

    if (first_pos != string::npos) {
        cout << "Первое вхождение символа '" << symbol << "' на позиции: "
            << first_pos + 1 << endl; 
        cout << "Последнее вхождение символа '" << symbol << "' на позиции: "
            << last_pos + 1 << endl;
    }
    else {
        cout << "Символ '" << symbol << "' не найден в строке." << endl;
    }

    return 0;
}
