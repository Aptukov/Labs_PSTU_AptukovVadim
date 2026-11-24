#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL,"Russian");
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;
    // 1. Создание исходной матрицы (rows x cols)
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    // 2. Создание транспонированной матрицы (размеры обратные: cols x rows)
    int** transposed = new int*[cols];
    for (int i = 0; i < cols; i++) {
        transposed[i] = new int[rows];
    }
    // 3. Ввод элементов исходной матрицы
    cout << "Введите элементы матрицы " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    // 4. Транспонирование (меняем индексы i и j местами)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    // 5. Вывод результата
    cout << "\nТранспонированная матрица " << cols << "x" << rows << ":\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
    // 6. Освобождение памяти обеих матриц
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < cols; i++) {
        delete[] transposed[i];
    }
    delete[] transposed;
    return 0;
}
