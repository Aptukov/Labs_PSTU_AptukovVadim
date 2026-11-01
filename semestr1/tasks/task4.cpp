#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    const int M = 3;
    const int N = 3;
    int matrix[M][N];

    // Ввод матрицы пользователем
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
    // 10 5 14 17 18 12 -10 1 -45

    int max_val = matrix[0][0];
    int max_row = 0;
    int max_col = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    cout << "Максимальный элемент: " << max_val << " (Индексы: Строка: " << max_row << ", Столбец: " << max_col << ")\n";
    // Максимальный элемент: 18 (Индексы: Строка: 1, Столбец: 1)
    return 0;
}
