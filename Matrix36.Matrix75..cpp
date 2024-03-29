#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Глобальна змінна для матриці
vector<vector<int>> matrix;

// Функція для зчитування розміру матриці та її елементів
void readMatrix() {
    int M, N;
    cout << "Введіть розмірність матриці M та N: ";
    cin >> M >> N;

    // Заповнюємо матрицю елементами
    matrix.resize(M, vector<int>(N));
    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Функція, яка знаходить кількість рядків, схожих на перший рядок матриці
int findSimilarRows() {
    int rows = matrix.size();
    int cols = matrix[0].size();
    unordered_set<string> similarRows; // Множина для збереження унікальних рядків

    // Формуємо рядок з елементів першого рядка матриці
    string firstRowString;
    for (int j = 0; j < cols; ++j) {
        firstRowString += to_string(matrix[0][j]) + " ";
    }

    // Додаємо перший рядок в множину схожих рядків
    similarRows.insert(firstRowString);

    // Ідемо по решті рядків і додаємо ті, які схожі на перший рядок у множину
    for (int i = 1; i < rows; ++i) {
        string currentRowString;
        for (int j = 0; j < cols; ++j) {
            currentRowString += to_string(matrix[i][j]) + " ";
        }
        similarRows.insert(currentRowString);
    }

    // Повертаємо кількість унікальних схожих рядків
    return similarRows.size();
}

// Функція для перевірки чи елемент (i, j) є локальним максимумом в матриці
bool isLocalMax(const std::vector<std::vector<int>>& matrix, int i, int j) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Перевіряємо всі сусідні елементи
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            int ni = i + x;
            int nj = j + y;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !(x == 0 && y == 0)) {
                if (matrix[ni][nj] >= matrix[i][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

// Функція для зміни знаку всіх локальних максимумів у матриці
void changeLocalMax(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Перебираємо всі елементи матриці
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isLocalMax(matrix, i, j)) {
                // Якщо (i, j) - локальний максимум, змінюємо його знак
                matrix[i][j] *= -1;
            }
        }
    }
}

// Функція для виведення матриці на екран
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

// Основна функція
int main() {
    int choice;
    bool exit = false;
    
    do {
        cout << "Виберіть завдання:" << endl;
        cout << "1. Знайти кількість рядків, схожих на перший рядок матриці." << endl;
        cout << "2. Змінити знак всіх локальних максимумів у матриці." << endl;
        cout << "3. Завершити програму." << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Зчитуємо матрицю
                readMatrix();

                // Знаходимо кількість рядків, схожих на перший рядок
                int similarRowsCount = findSimilarRows();
                cout << "Кількість рядків, схожих на перший рядок: " << similarRowsCount << endl;
                break;
            }
            case 2: {
                int m, n;
                cout << "Введіть розмір матриці (MxN): ";
                cin >> m >> n;

                // Читаємо елементи матриці з консолі
                vector<vector<int>> matrix(m, vector<int>(n));
                cout << "Введіть елементи матриці:\n";
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        cin >> matrix[i][j];
                    }
                }

                // Викликаємо функцію для зміни знаку локальних максимумів
                changeLocalMax(matrix);

                // Виводимо результати
                cout << "Результат:\n";
                printMatrix(matrix);
                break;
            }
            case 3:
                exit = true;
                break;
            default:
                cout << "Неправильний вибір!" << endl;
        }
    } while (!exit);

    return 0;
}




