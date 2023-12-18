#include <cmath>
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

struct Figure {
    int color;
    Point center;
    int radius;
};

bool isInsideCircle(Point point, Figure figure) {
    return pow(point.x - figure.center.x, 2) + pow(point.y - figure.center.y, 2) <= pow(figure.radius, 2);
}

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

void taskOne() {
    cout << "Вы выбрали задание 1" << endl;

    Point point;
    cout << "Введите координаты точки: ";
    cin >> point.x >> point.y;

    int color;
    cout << "Введите цвет фигуры: ";
    cin >> color;

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
        cout << "Введите координаты точки " << j + 1 << ": ";
        cin >> tempPoint.x >> tempPoint.y;

        bool isInside = isInsideCircle(tempPoint, figures[i]);
        if (isInside) {
            pointsInside++;
        }
    }

    cout << "Количество точек, попавших в фигуру: " << pointsInside << endl;
}

void taskTwo() {
    cout << "Вы выбрали задание 2" << endl;

    double x;
    int n;

    cout << "Введите действительное число x: ";
    cin >> x;

    cout << "Введите натуральное число n: ";
    cin >> n;

    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(-1, i) * pow(-1 + cos(x), i) / i;
    }

    cout << "Значение выражения: " << sum << endl;

    if (n % 2 == 0) {
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                cout << "Значение " << i << "-го элемента: " << sum / i << endl;
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (i % 4 == 0) {
                cout << "Значение " << i << "-го элемента: " << sum / i << endl;
            }
        }
    }
}

void taskThree() {
    cout << "Вы выбрали задание 3" << endl;

    int n;
    cout << "Введите n: ";
    cin >> n;

    double s = 0;
    for (int i = 1; i <= n; ++i) {
        s += (3 * i - 2) / factorial(100 * (i + 1) + 2);
    }

    double e = 1e-5;
    double g = 1e5;
    if (abs(s) < e) {
        cout << "Ряд совпадает." << endl;
    } else if (abs(s) > g) {
        cout << "Ряд разбегается." << endl;
    } else {
        cout << "Невозможно определить сходимость ряда." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "Выберите задачу:" << endl;
        cout << "1. Задание 1" << endl;
        cout << "2. Задание 2" << endl;
        cout << "3. Задание 3" << endl;
        cout << "0. Выйти" << endl;
        cout << "Ваш выбор: ";
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
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}
