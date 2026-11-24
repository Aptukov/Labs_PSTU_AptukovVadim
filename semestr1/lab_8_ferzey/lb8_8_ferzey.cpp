#include <iostream>
#include <clocale>

using namespace std;

const int N = 8;
int board[N][N]; // Обычная шахматная доска: 0 - пусто, 1 - стоит ферзь
int solutionsCount = 0;

// Функция для вывода доски на экран
void printBoard() {
    solutionsCount++;
    cout << "Решение " << solutionsCount << ":" << endl;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                cout << " Q";
            } else {
                cout << " .";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Проверка: можно ли поставить ферзя в клетку (row, col)
bool isSafe(int row, int col) {
    // 1. Проверяем этот же столбец выше текущей строки
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // 2. Проверяем левую верхнюю диагональ
    int i = row - 1;
    int j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    // 3. Проверяем правую верхнюю диагональ
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < N) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    return true; // Если никто не бьет, клетка безопасна
}

// Основная рекурсивная функция поиска решений
void solve(int row) {
    // Если дошли до 8-й строки, значит все 8 ферзей успешно расставлены
    if (row == N) {
        printBoard();
        return;
    }

    // Перебираем все столбцы в текущей строке
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1; // Ставим ферзя
            
            solve(row + 1);      // Пробуем поставить следующего на строку ниже
            
            board[row][col] = 0; // Убираем ферзя (откат назад), чтобы проверить другие варианты
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Заполняем доску нулями перед началом работы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    solve(0); // Начинаем поиск с нулевой (самой верхней) строки

    cout << "Всего найдено решений: " << solutionsCount << endl;

    return 0;
}
