#include <iostream>
#include <vector>

using namespace std;

int findHeatingSeasonStart(const vector<int>& dayTemps, const vector<int>& nightTemps) {
    int n = dayTemps.size();
    for (int i = 0; i <= n - 3; ++i) {
        bool threeColdDays = true;
        for (int j = i; j < i + 3; ++j) {
            double avg = (dayTemps[j] + nightTemps[j]) / 2.0;
            if (avg >= 8.0) {
                threeColdDays = false;
                break;
            }
        }
        if (threeColdDays) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> dayTemps = { 10, 9, 7, 6, 5, 7, 8, 6, 4, 3 };
    vector<int> nightTemps = { 6, 5, 4, 3, 2, 6, 7, 3, 2, 1 };

    int startDay = findHeatingSeasonStart(dayTemps, nightTemps);

    if (startDay != -1) {
        cout << "Отопительный сезон начался " << startDay << " числа." << endl;
    }
    else {
        cout << "Отопительный сезон не начался в этом месяце." << endl;
    }

    return 0;
}
