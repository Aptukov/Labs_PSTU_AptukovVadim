#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    const int ROWS = 2;
    const int COLS = 3;
    
    int matrix[ROWS][COLS] = { {59, -200, 777}, {52, 67, 42} };
    
    // Математически находим максимальную длину числа в матрице
    int max_width = 1;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int current_val = matrix[i][j];
            int width = 0;
            
            // Обработка нуля и отрицательных чисел (если они появятся)
            if (current_val <= 0) {
                width = 1; 
            }
            
            // Считаем количество цифр делением на 10
            int temp = current_val;
            if (temp < 0) temp = -temp; // Работаем с модулем числа
            while (temp > 0) {
                width++;
                temp /= 10;
            }
            
            if (width > max_width) {
                max_width = width;
            }
        }
    }
    
    // Выводим матрицу и считаем суммы строк
    for (int i = 0; i < ROWS; ++i) {
        int row_sum = 0;
        for (int j = 0; j < COLS; ++j) {
            row_sum += matrix[i][j];
            
            // Математически считаем длину текущего числа
            int current_val = matrix[i][j];
            int current_width = 0;
            if (current_val <= 0) current_width = 1;
            
            int temp = current_val;
            if (temp < 0) temp = -temp;
            while (temp > 0) {
                current_width++;
                temp /= 10;
            }
            
            // Ручное выравнивание столбцов: добавляем недостающие пробелы перед числом
            int spaces_needed = (max_width + 1) - current_width;
            for (int s = 0; s < spaces_needed; ++s) {
                cout << " ";
            }
            cout << matrix[i][j];
        }
        cout << " | Сумма: " << row_sum << endl;
    }
    
    return 0;
}
