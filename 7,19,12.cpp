#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Функція для обертання цифр у числі
void InvDigits(int &K) {
    int reversed = 0;
    while (K > 0) {
        int digit = K % 10;
        reversed = reversed * 10 + digit;
        K /= 10;
    }
    K = reversed;
}

// Функція для перевірки, чи рядок представляє ціле число
bool isInteger(const std::string& s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) {
        return false;
    }
    char* p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

// Функція для перевірки коректності введення користувача як цілого числа
bool checkInput(int& num) {
    string input;
    cin >> input;
    if (!isInteger(input)) {
        cout << "Помилка. Будь ласка, введіть ціле число." << endl;
        return false;
    }
    num = stoi(input);
    return true;
}

// Функція для перевірки, чи число складається з трьох цифр
bool validateInput(int number) {
    return number >= 100 && number <= 999;
}

// Функція для отримання введеного користувачем трьохзначного числа
int getInput() {
    int inputNumber;
    cout << "Введіть тризначне число: ";
    cin >> inputNumber;

    if (!validateInput(inputNumber)) {
        cout << "Некоректне введення! Введіть тризначне число." << endl;
        return -1;
    }

    return inputNumber;
}

// Функція для обертання числа
int reverseNumber(int number) {
    int reversed = 0;
    while (number > 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }
    return reversed;
}

// Функція для відображення результату
void displayResult(int result) {
    cout << "Число, отримане при прочитанні справа наліво: " << result << endl;
}

// Функція для відображення меню та обробки вибору опцій
void showMenu() {
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Завдання 1 - Обертання цифр у числі\n";
        cout << "2. Завдання 2 - Перевірка наявності взаємно протилежних чисел\n";
        cout << "3. Завдання 3 - Обертання тризначного числа\n";
        cout << "0. Вийти\n";
        cout << "Виберіть опцію: ";

        while (!(cin >> choice) || choice < 0 || choice > 3) {
            cout << "Некоректний вибір. Будь ласка, спробуйте ще раз: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: {
                int numbers[5];

                cout << "Введіть п’ять натуральних чисел: " << endl;
                for (int i = 0; i < 5; ++i) {
                    cout << "Число " << i + 1 << ": ";
                    cin >> numbers[i];

                    while (numbers[i] <= 0) {
                        cout << "Будь ласка, введіть натуральне ціле число для числа " << i + 1 << ": ";
                        cin >> numbers[i];
                    }
                }

                for (int i = 0; i < 5; ++i) {
                    InvDigits(numbers[i]);
                    cout << "Обернене число " << i + 1 << ": " << numbers[i] << endl;
                }
                break;
            }
            case 2: {
                int num1, num2, num3;

                cout << "Введіть перше ціле число: ";
                while (!checkInput(num1)) {}

                cout << "Введіть друге ціле число: ";
                while (!checkInput(num2)) {}

                cout << "Введіть третє ціле число: ";
                while (!checkInput(num3)) {}

                if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0) ||
                    (num1 < 0 && num3 > 0) || (num1 > 0 && num3 < 0) ||
                    (num2 < 0 && num3 > 0) || (num2 > 0 && num3 < 0)) {
                    cout << "Є хоча б одна пара взаємно протилежних чисел." << endl;
                } else {
                    cout << "Немає пари взаємно протилежних чисел." << endl;
                }
                break;
            }
            case 3: {
                int input = getInput();

                if (input != -1) {
                    int reversed = reverseNumber(input);
                    displayResult(reversed);
                }
                break;
            }
            case 0:
                cout << "Програма завершує роботу.\n";
                break;
            default:
                cout << "Некоректний вибір. Будь ласка, спробуйте ще раз.\n";
                break;
        }
    } while (choice != 0);
}

// Головна функція програми
int main() {
    showMenu();
    return 0;
}



