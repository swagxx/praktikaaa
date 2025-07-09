#include <iostream>
#include <vector>
#include <limits>

struct Baggage {
    int itemCount;
    double totalWeight;
};


void inputBaggage(std::vector<Baggage>& baggages, int count) {
    for (int i = 0; i < count; ++i) {
        Baggage b;
        std::cout << "Пассажир #" << i + 1 << ":\n";
        std::cout << "  Количество вещей: ";
        std::cin >> b.itemCount;
        std::cout << "  Общий вес: ";
        std::cin >> b.totalWeight;
        baggages.push_back(b);
    }
}


void printBaggage(const std::vector<Baggage>& baggages) {
    std::cout << "\nИнформация о багаже:\n";
    for (size_t i = 0; i < baggages.size(); ++i) {
        std::cout << "Пассажир #" << i + 1 << ": "
            << baggages[i].itemCount << " вещей, "
            << baggages[i].totalWeight << " кг\n";
    }
}


bool hasHeavySingleItem(const std::vector<Baggage>& baggages) {
    for (const auto& b : baggages) {
        if (b.itemCount == 1 && b.totalWeight >= 30.0) {
            return true;
        }
    }
    return false;
}


void printMaxItemsMinWeight(const std::vector<Baggage>& baggages) {
    int maxItems = 0;
    for (const auto& b : baggages) {
        if (b.itemCount > maxItems) {
            maxItems = b.itemCount;
        }
    }

    double minWeight = std::numeric_limits<double>::max();
    int index = -1;

    for (size_t i = 0; i < baggages.size(); ++i) {
        if (baggages[i].itemCount == maxItems && baggages[i].totalWeight < minWeight) {
            minWeight = baggages[i].totalWeight;
            index = i;
        }
    }

    if (index != -1) {
        std::cout << "\nБагаж с максимальным числом вещей и минимальным весом среди них:\n";
        std::cout << "Пассажир #" << index + 1 << ": "
            << baggages[index].itemCount << " вещей, "
            << baggages[index].totalWeight << " кг\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Baggage> baggages;
    int n;

    std::cout << "Введите количество пассажиров: ";
    std::cin >> n;

    inputBaggage(baggages, n);
    printBaggage(baggages);

    if (hasHeavySingleItem(baggages)) {
        std::cout << "\nЕсть пассажир с одной вещью весом не менее 30 кг.\n";
    }
    else {
        std::cout << "\nНет пассажира с одной вещью весом не менее 30 кг.\n";
    }

    printMaxItemsMinWeight(baggages);

    return 0;
}
