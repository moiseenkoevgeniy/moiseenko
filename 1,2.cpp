#include <iostream>
#include <cmath>

using namespace std;

// Прототипи функцій
void task_if1();  // Прототип функції для першого завдання
void task_geom1();  // Прототип функції для другого завдання

int main() {
    int menu;
    cout << "Task number:";
    cin >> menu;
    switch (menu) {
        case 1:
            task_if1();  // Виклик функції для першого завдання
            break;
        case 2:
            task_geom1();  // Виклик функції для другого завдання
            break;
        default:
            cout << "Wrong task! (Only 1, 2)" << endl;  // Помилкове введення номера завдання
            break;
    }

    return 0; // Повернення значення з main()
}

void task_if1() {
    double A, B;

    // Зчитування значень змінних A і B
    cout << "Введіть значення для A: ";
    cin >> A;
    cout << "Введіть значення для B: ";
    cin >> B;

    if (B > A) {
        // Якщо B вже більше за A, виводимо їх без змін
        cout << "A: " << A << endl;
        cout << "B: " << B << endl;
    } else {
        // Інакше міняємо значення A та B місцями
        double temp = A;
        A = B;
        B = temp;

        cout << "Після перерозподілу:" << endl;
        cout << "A: " << A << endl;
        cout << "B: " << B << endl;
    }
}

struct Point {
    int x;
    int y;
};

struct Figure {
    int color;
    Point center;
    int radius;
};

// Перевірка чи точка знаходиться всередині кола фігури
bool isInsideCircle(Point point, Figure figure) {
    return pow(point.x - figure.center.x, 2) + pow(point.y - figure.center.y, 2) <= pow(figure.radius, 2);
}

void task_geom1() {
    // Введення даних про точку і колір фігури
    Point point;
    cout << "Введіть координати точки: ";
    cin >> point.x >> point.y;
    int color;
    cout << "Введіть колір фігури: ";
    cin >> color;

    // Створення масиву фігур (у цьому випадку масив має лише один елемент)
    Figure figures[] = {
        {12, {5, 5}, 5}  // Фігура з певним коліром, центром та радіусом
    };

    // Пошук фігури з введеним коліром
    int i;
    for (i = 0; i < 1; i++) {  // Пошук фігури в масиві (в даному випадку одна фігура)
        if (figures[i].color == color) {
            break;  // Якщо знайдено фігуру з введеним коліром, вийти з циклу
        }
    }

    // Визначення, чи точка потрапила всередину фігури
    bool isInside = isInsideCircle(point, figures[i]);

    // Виведення результату
    if (isInside) {
        cout << "Точка потрапила в фігуру." << endl;
    } else {
        cout << "Точка не потрапила в фігуру." << endl;
    }

    // Розрахунок периметру та площі фігури
    double perimeter = 2 * M_PI * figures[i].radius; // Обчислення периметру кола
    double area = M_PI * figures[i].radius * figures[i].radius; // Обчислення площі кола

    // Виведення результату
    cout << "Периметр фігури: " << perimeter << endl;
    cout << "Площа фігури: " << area << endl;
}
