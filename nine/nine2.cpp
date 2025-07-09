#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

string normalizeWord(const string& word) {
    string result;
    for (char c : word) {
        if (isalpha(c)) {
            result += tolower(c);
        }
    }
    return result;
}

bool isWordInText(const string& word, const string& text) {
    istringstream iss(text);
    string currentWord;
    string target = normalizeWord(word);

    while (iss >> currentWord) {
        if (normalizeWord(currentWord) == target) {
            return true;
        }
    }
    return false;
}

string removeWordFromText(const string& word, const string& text) {
    istringstream iss(text);
    ostringstream oss;
    string currentWord;
    string target = normalizeWord(word);
    bool firstWord = true;

    while (iss >> currentWord) {
        if (normalizeWord(currentWord) != target) {
            if (!firstWord) oss << " ";
            oss << currentWord;
            firstWord = false;
        }
    }
    return oss.str();
}

int main() {
    setlocale(LC_ALL, "Russian");
    string inputFilename = "nine/F1.txt";
    string outputFilename = "nine/F2.txt";

    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла " << inputFilename << endl;
        return 1;
    }

    ostringstream buffer;
    buffer << inputFile.rdbuf();
    string fullText = buffer.str();
    inputFile.close();

    string targetWord;
    cout << "Введите слово для поиска: ";
    cin >> targetWord;

    if (isWordInText(targetWord, fullText)) {
        cout << "Слово найдено в тексте." << endl;

        string newText = removeWordFromText(targetWord, fullText);

        ofstream outputFile(outputFilename);
        if (!outputFile.is_open()) {
            cerr << "Ошибка открытия файла " << outputFilename << endl;
            return 1;
        }

        outputFile << newText;
        outputFile.close();

        cout << "Текст без слова '" << targetWord << "' записан в файл " << outputFilename << endl;
    }
    else {
        cout << "Слово не найдено в тексте." << endl;
    }

    return 0;
}
