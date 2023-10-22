#include <iostream>
// Підключення бібліотеки математичних функцій
#include <cmath>
using namespace std;
int main() {
    //Integer12
    cout << "______Integer12______" << endl;
    int number;
    cout << "Введіть тризначне число: ";
    cin >> number;

    // Розділяємо число на цифри
    int digit1 = number % 10;
    int digit2 = (number / 10) % 10;
    int digit3 = number / 100;

    // Виводимо число, отримане при прочитанні вихідного числа справа наліво
    int reversedNumber = digit1 * 100 + digit2 * 10 + digit3;
    cout << "Число, отримане при прочитанні справа наліво: " << reversedNumber << endl;






    // Boolean19
    cout << "______Boolean19______" << endl;
    int A, B, C;
    cout << "Введіть три цілих числа через пробіл: ";
    cin >> A >> B >> C;

    // Перевіряємо, чи є хоча б одна пара взаємно протилежних чисел
    bool hasOppositePair = (A * B < 0) || (A * C < 0) || (B * C < 0);

    // Виводимо результат перевірки
    cout << boolalpha << "Серед трьох даних цілих чисел є хоча б одна пара взаємно протилежних: " << hasOppositePair << endl;





    // y = ... (tab.3 N9)
    cout << "______ Math.9.______" << endl;
    // Оголошуємо змінну x та запитуємо користувача ввести її значення
    double x;
    cout << "Введіть значення x: ";
    cin >> x;

    // Розраховуємо чисельник за формулою із використанням функцій pow, sin, fabs та sqrt
    double numerator = pow(0.5, x) * pow(sin(x), 2) * sqrt(fabs(sin(x + 64) * log(fabs(x))));

    // Розраховуємо знаменник за формулою із використанням функцій tan та pow
    double denominator = tan(x) * pow(sin(x * x * x), 2);

    // Розраховуємо значення Y, діляючи чисельник на знаменник
    double y = numerator / denominator;

    // Виводимо результат
    cout << "Значення Y для введеного x: " << y << endl;

    return 0;
}


  
