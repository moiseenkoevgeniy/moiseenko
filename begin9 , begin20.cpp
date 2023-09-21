 #include <iostream>

int main() {
    //begin 9;
    // Вхідні числа
    double num1, num2;
    // Результати операцій
    double sum, difference, product, quotient;
    std::cout << "______Begin9______" << std::endl;
    // Введення
    std::cout << "Введіть перше число: ";
    std::cin >> num1;
    std::cout << "Введіть друге число: ";
    std::cin >> num2;
    // Обчислення суми
    sum = num1 * num1 + num2 * num2;
    // Обчислення різниці
    difference = num1 * num1 - num2 * num2;
    // Обчислення добутку
    product = num1 * num1 * num2 * num2;
    // Обчислення частки
    if (num2 != 0) {
        quotient = (num1 * num1) / (num2 * num2);
        // Виведення результатів
        std::cout << "Сума квадратів: " << sum << std::endl;
        std::cout << "Різниця квадратів: " << difference << std::endl;
        std::cout << "Добуток квадратів: " << product << std::endl;
        std::cout << "Частка квадратів: " << quotient << std::endl;
    } else {
        std::cout << "Друге число не може бути рівним нулю для обчислення частки." << std::endl;
    }



    //begin 20
    // Вхідне число
    double A;
    // Оголошення змінної
    double A2, A3, A5, A10, A15; 
    std::cout << "______Begin 20______" << std::endl;
     //Введення
    std::cout << "Введіть невідому: ";
    std::cin >> A;
    // Обчислення
    A2 = A * A;
    // Вивід 
    std::cout << "A^2 = " << A2 << std::endl;
    // Обчислення 
    A3 = A2 * A;
    // Вивід 
    std::cout << "A^3 = " << A3 << std::endl;
    // Обчислення
    A5 = A2 * A3;
    // Вивід 
    std::cout << "A^5 = " << A5 << std::endl;
    // Обчислення 
    A10 = A5 * A5;
    // Вивід 
    std::cout << "A^10 = " << A10 << std::endl;
    // Обчислення 
    A15 = A10 * A5;
    // Вивід
    std::cout << "A^15 = " << A15 << std::endl;

    return 0;
    }


 
