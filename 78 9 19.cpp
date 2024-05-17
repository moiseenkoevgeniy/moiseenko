#include <iostream>
#include <cmath>

using namespace std;

// Модуль операцій з часом
struct TTime {
    int hours;
    int minutes;
    int seconds;
};

bool isValidTime(const TTime& T) {
    return (T.hours >= 0 && T.hours < 24) &&
           (T.minutes >= 0 && T.minutes < 60) &&
           (T.seconds >= 0 && T.seconds < 60);
}

void NextHour(TTime& T) {
    if (isValidTime(T)) {
        T.hours = (T.hours + 1) % 24; // додаємо одну годину та використовуємо модуль для переходу через 24 години
    }
}

void printTime(const TTime& T) {
    cout << (T.hours < 10 ? "0" : "") << T.hours << ":"
         << (T.minutes < 10 ? "0" : "") << T.minutes << ":"
         << (T.seconds < 10 ? "0" : "") << T.seconds << endl;
}

void inputTime(TTime& T) {
    cout << "Введіть час (години хвилини секунди): ";
    cin >> T.hours >> T.minutes >> T.seconds;
    while (!isValidTime(T)) {
        cout << "Некоректний час. Будь ласка, введіть ще раз (години хвилини секунди): ";
        cin >> T.hours >> T.minutes >> T.seconds;
    }
}

// Модуль середнього геометричного
struct Data {
    double a; // Перше число
    double b; // Друге число
    double geometric_mean; // Середнє геометричне
    bool hasOppositePair; // Додали поле для перевірки взаємно протилежних чисел
};

bool fillData(Data& data, double a, double b) {
    if (a < 0 || b < 0) {
        cerr << "Числа повинні бути невід'ємними!" << endl;
        return false;
    }
    data.a = a;
    data.b = b;
    return true;
}

void calculateGeometricMean(Data& data) {
    data.geometric_mean = sqrt(data.a * data.b);
}

// Модуль перевірки взаємно протилежних пар
bool checkOppositePair(int a, int b, int c) {
    return (a == -b) || (a == -c) || (b == -c);
}

void fillData(Data &data, int a, int b, int c) {
    data.a = a;
    data.b = b;
    data.hasOppositePair = checkOppositePair(a, b, c);
}

int main() {
    // Завдання 1: Операції з часом
    TTime times[5];

    cout << "Будь ласка, введіть 5 моментів часу:" << endl;
    for (int i = 0; i < 5; ++i) {
        inputTime(times[i]);
    }

    cout << "\nПочатковий час:" << endl;
    for (int i = 0; i < 5; ++i) {
        printTime(times[i]);
    }

    for (int i = 0; i < 5; ++i) {
        NextHour(times[i]);
    }

    cout << "\nЧас після додавання однієї години:" << endl;
    for (int i = 0; i < 5; ++i) {
        printTime(times[i]);
    }

    // Завдання 2: Середнє геометричне
    Data data;

    double a, b;
    cout << "\nВведіть два невід'ємні числа a і b: ";
    cin >> a >> b;

    if (fillData(data, a, b)) {
        calculateGeometricMean(data);
        cout << "Середнє геометричне чисел " << data.a << " і " << data.b << " дорівнює " << data.geometric_mean << endl;
    }

    // Завдання 3: Взаємно протилежні пари
    int x, y, z;
    cout << "\nВведіть три цілі числа: ";
    cin >> x >> y >> z;

    fillData(data, x, y, z);

    cout << "Серед даних чисел ";
    if (data.hasOppositePair) {
        cout << "є хоча б одна пара взаємно протилежних чисел." << endl;
    } else {
        cout << "немає пари взаємно протилежних чисел." << endl;
    }

    return 0;
}




