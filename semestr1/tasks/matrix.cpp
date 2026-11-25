#include <iostream>
#include <windows.h>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 5; // Размер квадратной матрицы
    int matrix[N][N];

    // Заполнение матрицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Строго выше главной (i < j) И строго выше побочной (i + j < N - 1)
            if (i < j && i + j < N - 1) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = 1;
            }
        }
    }

    // Вывод матрицы на экран
    cout << "Полученная матрица:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
