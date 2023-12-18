#include <cmath>
#include <iostream>

using namespace std;

// Структура, яка представляє точку у двовимірному просторі
struct Point {
    int x; // Координата x
    int y; // Координата y
};

// Структура, яка представляє фігуру - коло
struct Figure {
    int color;    // Колір фігури
    Point center; // Центр кола
    int radius;   // Радіус кола
};

// Функція, яка перевіряє, чи знаходиться точка всередині кола
bool isInsideCircle(Point point, Figure figure) {
    return pow(point.x - figure.center.x, 2) + pow(point.y - figure.center.y, 2) <= pow(figure.radius, 2);
}

// Функція, яка обчислює факторіал числа
double factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        double fact = 1;
        for (int i = 2; i <= num; ++i) {
            fact *= i;
        }
        return fact;
    }
}

// Функція для виконання першого завдання
void taskOne() {
    cout << "Ви обрали завдання 1" << endl;

    Point point;
    cout << "Введіть координати точки: ";
    cin >> point.x >> point.y;

    int color;
    cout << "Введіть колір фігури: ";
    cin >> color;

    // Масив фігур, зараз у ньому є лише одна фігура - коло
    Figure figures[] = {
        {12, {5, 5}, 5},
    };

    int i;
    for (i = 0; i < 1; i++) {
        if (figures[i].color == color) {
            break;
        }
    }

    int pointsInside = 0;

    for (int j = 0; j < 5; j++) {
        Point tempPoint;
        cout << "Введіть координати точки " << j + 1 << ": ";
        cin >> tempPoint.x >> tempPoint.y;

        bool isInside = isInsideCircle(tempPoint, figures[i]);
        if (isInside) {
            pointsInside++;
        }
    }

    cout << "Кількість точок, що потрапили у фігуру: " << pointsInside << endl;
}

// Функція для виконання другого завдання
void taskTwo() {
    cout << "Ви обрали завдання 2" << endl;

    double x;
    int n;

    cout << "Введіть дійсне число x: ";
    cin >> x;

    cout << "Введіть натуральне число n: ";
    cin >> n;

    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(-1, i) * pow(-1 + cos(x), i) / i;
    }

    cout << "Значення виразу: " << sum << endl;

    // Друк коефіцієнтів, що обчислюються на кожній ітерації циклу залежно від умови
    if (n % 2 == 0) {
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                cout << "Значення " << i << "-го елемента: " << sum / i << endl;
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (i % 4 == 0) {
                cout << "Значення " << i << "-го елемента: " << sum / i << endl;
            }
        }
    }
}

// Функція для виконання третього завдання
void taskThree() {
    cout << "Ви обрали завдання 3" << endl;

    int n;
    cout << "Введіть n: ";
    cin >> n;

    double s = 0;
    for (int i = 1; i <= n; ++i) {
        s += (3 * i - 2) / factorial(100 * (i + 1) + 2);
    }

    double e = 1e-5;
    double g = 1e5;
    if (abs(s) < e) {
        cout << "Ряд збігається." << endl;
    } else if (abs(s) > g) {
        cout << "Ряд розбігається." << endl;
    } else {
        cout << "Неможливо визначити збіжність низки." << endl;
    }
}

// Основна функція програми
int main() {
    int choice;

    do {
        cout << "Виберіть завдання:" << endl;
        cout << "1. Завдання 1" << endl;
        cout << "2. Завдання 2" << endl;
        cout << "3. Завдання 3" << endl;
        cout << "0. Вийти" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            taskOne();
            break;
        case 2:
            taskTwo();
            break;
        case 3:
            taskThree();
            break;
        case 0:
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}
