#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int mx_rows = 10;
const int mx_cols = 10;

// Функция заполнения массива случайными числами
void fillarr(int arr[][mx_cols], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            arr[i][j] = rand() % 99 + 1; // Числа от 1 до 99
        }
    }
}

// Функция вывода массива на экран (с нумерацией строк от 1)
void printarr(const int arr[][mx_cols], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        cout << "Строка " << setw(2) << i + 1 << ": ";
        for (int j = 0; j < cols; j++) 
        {
            cout << setw(4) << arr[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

// Функция удаления одной строки по индексу rowdel с заменой освободившейся строки на 0
void delrow(int arr[][mx_cols], int rows, int cols, int rowdel) 
{
    if (rowdel >= 0 && rowdel < rows) 
    {
        // Сдвиг всех строк, находящихся ниже удаляемой, на одну позицию вверх
        for (int i = rowdel; i < rows - 1; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                arr[i][j] = arr[i + 1][j];
            }
        }

        // Заполнение освободившейся последней строки нулями
        for (int j = 0; j < cols; j++) 
        {
            arr[rows - 1][j] = 0;
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int arr[mx_rows][mx_cols];
    int rows, cols;

    cout << "Введите количество строк (от 1 до " << mx_rows << "): ";
    cin >> rows;
    cout << "Введите количество столбцов (от 1 до " << mx_cols << "): ";
    cin >> cols;

if (rows <= 0 || rows > mx_rows || cols <= 0 || cols > mx_cols) 
    {
        cout << "Ошибка: некорректные размеры массива.\n";
    }
    else 
    {
        fillarr(arr, rows, cols);

        cout << "\nИсходный массив:\n";
        printarr(arr, rows, cols);

        int A, B;
        cout << "Введите начальный номер удаляемой строки A (от 1 до " << rows << "): ";
        cin >> A;
        cout << "Введите конечный номер удаляемой строки B (от 1 до " << rows << "): ";
        cin >> B;

        if (A < 1 || B > rows || A > B) 
        {
            cout << "Ошибка: номера строк должны быть от 1 до " << rows << ", при этом A <= B.\n";
        }
        else 
        {
            // Удаляем (B - A + 1) строк, передавая индекс (A - 1)
            int cntdel = B - A + 1;
            for (int k = 0; k < cntdel; k++) 
            {
                delrow(arr, rows, cols, A - 1);
            }

            cout << "\nМассив после удаления строк с " << A << " по " << B << ":\n";
            printarr(arr, rows, cols);
        }
    }

    return 0;
}