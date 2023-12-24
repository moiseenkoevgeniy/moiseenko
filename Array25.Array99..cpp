#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Функція для перевірки чи є послідовність геометричною прогресією
bool isGeometricProgression(vector<int>& arr) {
    if (arr.size() <= 2) {
        return true; // Якщо масив має менше або рівно 2 елементів, то це геометрична прогресія
    }

    int ratio = arr[1] / arr[0]; // Визначення знаменника прогресії

    for (size_t i = 2; i < arr.size(); ++i) {
        if (arr[i] / arr[i - 1] != ratio) {
            return false; // Перевірка чи кожний наступний елемент утворює геометричну прогресію
        }
    }

    return true;
}

// Функція для обробки масиву
void processArray(vector<int>& arr) {
    // Видалення елементів, що зустрічаються більше двох разів
    unordered_map<int, int> countMap;
    for (int i : arr) {
        countMap[i]++;
    }

    for (auto it = arr.begin(); it != arr.end(); ) {
        if (countMap[*it] > 2) {
            it = arr.erase(it);
        } else {
            ++it;
        }
    }

    // Створення нового countMap для нового масиву
    countMap.clear();
    for (int i : arr) {
        countMap[i]++;
    }

    // Видалення елементів, що зустрічаються більше одного разу
    for (auto it = arr.begin(); it != arr.end(); ) {
        if (countMap[*it] > 1) {
            it = arr.erase(it);
        } else {
            ++it;
        }
    }

    // Вивід зміненого масиву після другого видалення
    cout << "Змінений масив: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    int choice;
    do {
        cout << "Виберіть завдання:\n";
        cout << "1. Перевірка геометричної прогресії\n";
        cout << "2. Обробка масиву\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Код для перевірки геометричної прогресії у користувацького введення
                break;
            }
            case 2: {
                // Код для обробки масиву у користувацького введення
                break;
            }
            case 0:
                cout << "Дякуємо за використання програми. До побачення!\n";
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}

