#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

// Прототипи функцій
size_t rfind(const char* str, char c, size_t pos = -1);
string getResultString(size_t pos, size_t pos_custom);
void processString(string& str, size_t pos, size_t len);
bool checkString(const string& str);

// Реалізація функції rfind
size_t rfind(const char* str, char c, size_t pos /* = -1 */) {
    size_t len = 0;
    while (str[len] != '\0') // Знаходження довжини рядка
        len++;
    
    if (pos == -1 || pos > len) // Якщо позиція перевищує довжину рядка, змінити на кінець рядка
        pos = len;

    if (pos == 0) // Якщо позиція рівна нулю, почати пошук з кінця рядка
        pos = len;

    for (size_t i = pos - 1; i < len; i--) { // Прохід по рядку з кінця до позиції
        if (str[i] == c)
            return i;
    }
    return -1; // Якщо символ не знайдено, повернути -1
}

// Функція для отримання результату у вигляді std::string
string getResultString(size_t pos, size_t pos_custom) {
    ostringstream oss;
    oss << "Позиція символу за використанням string: " << pos << endl;
    oss << "Позиція символу за власною реалізацією: " << pos_custom << endl;
    return oss.str();
}

// Функція обробки рядка
void processString(string& str, size_t pos, size_t len) {
    str.erase(pos, len);
}

// Функція перевірки рядка
bool checkString(const string& str) {
    // Реалізуйте перевірку умов для рядка
    // Повертає true, якщо рядок відповідає умовам, інакше - false
}

int main() {
    const int MAX_SIZE = 100;
    char str[MAX_SIZE];
    string str_std;

    cout << "Введіть рядок: ";
    cin.getline(str, MAX_SIZE); // Зчитати рядок з консолі

    str_std = str; // Конвертувати масив символів в рядок типу string

    char search_char;
    cout << "Введіть символ для пошуку: ";
    cin >> search_char; // Зчитати символ для пошуку

    size_t pos = str_std.rfind(search_char); // Виклик методу rfind для об'єкту типу string
    size_t pos_custom = rfind(str, search_char); // Виклик власної реалізацією функції

    // Вивести результат у вигляді рядка
    string result = getResultString(pos, pos_custom);
    cout << result;

    ifstream inputFile("C:\\Users\\Жека\\Desktop\\input.txt");
    ofstream outputFile("C:\\Users\\Жека\\Desktop\\output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Помилка відкриття файлів!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        // Обробка рядка
        size_t pos, len;
        // Введення позиції та довжини видалення з консолі
        cout << "Введіть позицію та довжину видалення для рядка: ";
        cin >> pos >> len;
        processString(line, pos, len);

        // Перевірка рядка
        if (checkString(line)) {
            // Запис обробленого рядка у вихідний файл
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
