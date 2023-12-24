#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isGeometricProgression(vector<int>& arr) {
    if (arr.size() <= 2) {
        return true;
    }

    int ratio = arr[1] / arr[0];

    for (size_t i = 2; i < arr.size(); ++i) {
        if (arr[i] / arr[i - 1] != ratio) {
            return false;
        }
    }

    return true;
}

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
                int N;
                cout << "Введіть розмір масиву: ";
                cin >> N;

                vector<int> array(N);

                cout << "Введіть елементи масиву: ";
                for (int i = 0; i < N; ++i) {
                    cin >> array[i];
                }

                cout << "Масив у порядку зростання індексів: ";
                for (int i = 0; i < N; ++i) {
                    cout << array[i] << " ";
                }
                cout << endl;

                if (isGeometricProgression(array)) {
                    int ratio = array[1] / array[0];
                    cout << "Елементи утворюють геометричну прогресію. Знаменник прогресії: " << ratio << endl;
                } else {
                    cout << "Елементи не утворюють геометричну прогресію. Знаменник не визначено." << endl;
                }
                break;
            }
            case 2: {
                int n;
                cout << "Введіть розмір масиву: ";
                cin >> n;

                vector<int> arr(n);

                cout << "Введіть елементи масиву:\n";
                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
                }

                cout << "Початковий масив: ";
                for (int i : arr) {
                    cout << i << " ";
                }
                cout << "\n";

                processArray(arr);
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





