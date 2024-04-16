#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <Windows.h>

using namespace std;

// Функція для видалення елементів з масиву, які зустрічаються більше двох разів
void removeDuplicates(vector<int>& arr) {
    unordered_map<int, int> frequency;
    vector<int> result;

    // Рахуємо кількість зустрічей кожного елемента
    for (int num : arr) {
        frequency[num]++;
    }

    // Заповнюємо результат лише елементами, що зустрічаються не більше двох разів
    for (int num : arr) {
        if (frequency[num] <= 2) {
            result.push_back(num);
        }
    }

    // Переприсвоюємо масив arr результатом
    arr = result;
}

// Функція для сортування масиву методом двійкового вставлення
void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int left = 0, right = i - 1;

        // Використовуємо бінарний пошук для знаходження позиції для вставки
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }

        // Переміщуємо всі елементи більші за key на одну позицію вправо
        for (int j = i - 1; j >= left; --j)
            arr[j + 1] = arr[j];

        // Вставляємо елемент у відповідну позицію
        arr[left] = key;
    }
}

// Функція для зчитування масиву з файлу
vector<int> readArrayFromFile(const string& filename) {
    vector<int> arr;
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return arr; // Повертаємо пустий масив у разі помилки
    }

    int number;
    while (inputFile >> number)
        arr.push_back(number);

    inputFile.close();
    return arr;
}

// Функція для виведення масиву у консоль
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Функція для зчитування матриці з файлу
vector<vector<int>> readMatrixFromFile(const string& filename, int& M, int& N) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу.\n";
        exit(1);
    }

    file >> M >> N;
    vector<vector<int>> matrix(M, vector<int>(N));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close();
    return matrix;
}

// Функція для порівняння двох рядків матриці
bool areSimilar(const vector<int>& row1, const vector<int>& row2) {
    if (row1.size() != row2.size()) return false;

    unordered_set<int> set1(row1.begin(), row1.end());
    unordered_set<int> set2(row2.begin(), row2.end());

    return set1 == set2;
}

int main() {
    int choice;

    do {
        cout << "Меню:" << endl;
        cout << "1. Виконати програму для видалення зайвих елементів з масиву" << endl;
        cout << "2. Виконати програму для порівняння рядків матриці" << endl;
        cout << "3. Виконати програму для сортування масиву методом двійкового вставлення" << endl;
        cout << "4. Вийти з програми" << endl;
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                vector<int> myArray = readArrayFromFile("C:\Users\Users\Desktop\in_17.txt");
                if (myArray.empty()) {
                    cerr << "Array is empty or file could not be read." << endl;
                    break;
                }
                cout << "Unsorted Array: ";
                printArray(myArray);
                removeDuplicates(myArray);
                cout << "Array after removing duplicates: ";
                printArray(myArray);
                break;
            }
            case 2: {
                int M, N;
                vector<vector<int>> matrix;
                matrix = readMatrixFromFile("C:\Users\Users\Desktop\math_in_36.txt", M, N);
                if (M == 0 || N == 0) {
                    cout << "Матриця порожня.\n";
                    break;
                }
                int similarCount = 0;
                for (int i = 1; i < M; ++i) {
                    if (areSimilar(matrix[0], matrix[i])) {
                        similarCount++;
                    }
                }
                cout << "Кількість рядків, схожих на перший рядок: " << similarCount << "\n";
                break;
            }
            case 3: {
                vector<int> myArray = readArrayFromFile("C:\Users\Users\Desktop\in_17.txt");
                if (myArray.empty()) {
                    cerr << "Array is empty or file could not be read." << endl;
                    break;
                }
                cout << "Unsorted Array: ";
                printArray(myArray);
                binaryInsertionSort(myArray);
                cout << "Sorted Array: ";
                printArray(myArray);
                break;
            }
            case 4:
                cout << "До побачення!" << endl;
                break;
            default:
                cout << "Невірний вибір. Будь ласка, виберіть знову." << endl;
        }
    } while (choice != 4);

    return 0;
}
