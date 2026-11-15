#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция заполнения динамического массива случайными числами от 1 до 99
void fillarr(int* arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 99 + 1;
    }
}

// Функция вывода динамического массива на экран
void printarr(const int* arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Функция создания нового массива без элемента с индексом del_idx
int* del_elem(const int* arr, int size, int del_idx) 
{
    int* new_arr = new int[size - 1];
    int j = 0;
    for (int i = 0; i < size; i++) 
    {
        if (i != del_idx) 
        {
            new_arr[j] = arr[i];
            j++;
        }
    }
    return new_arr;
}

// Функция создания нового массива с добавлением k элементов начиная с индекса ins_idx
int* ins_elems(const int* arr, int size, int ins_idx, int k) 
{
    int* new_arr = new int[size + k];

    // 1. Копируем элементы до позиции вставки
    for (int i = 0; i < ins_idx; i++) 
    {
        new_arr[i] = arr[i];
    }

    // 2. Добавляем k новых случайных элементов от 1 до 99
    for (int i = 0; i < k; i++) 
    {
        new_arr[ins_idx + i] = rand() % 99 + 1;
    }

    // 3. Копируем оставшиеся элементы исходного массива
    for (int i = ins_idx; i < size; i++) 
    {
        new_arr[i + k] = arr[i];
    }

    return new_arr;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int n;
    cout << "Введите размер массива n: ";
    cin >> n;

    if (n <= 0) 
    {
        cout << "Ошибка: размер массива должен быть положительным числом.\n";
    }
    else 
    {
        // Формирование и заполнение исходного динамического массива
        int* arr = new int[n];
        fillarr(arr, n);

        cout << "\nИсходный массив (размер = " << n << "):\n";
        printarr(arr, n);

        // Ввод заданного номера pos
        int pos;
        cout << "\nВведите заданный номер элемента (от 1 до " << n << "): ";
        cin >> pos;

        if (pos < 1 || pos > n) 
        {
            cout << "Ошибка: номер элемента должен быть от 1 до " << n << ".\n";
            delete[] arr;
        }
        else 
        {
            // Этап 1: Удаление элемента с номером pos
            int* arr_del = del_elem(arr, n, pos - 1);
            delete[] arr; // Освобождаем память старого массива
            arr = arr_del;
            n--;

            cout << "Массив после удаления элемента №" << pos << " (размер = " << n << "):\n";
            printarr(arr, n);

            // Этап 2: Добавление K элементов начиная с этого же номера pos
            int K;
            cout << "\nВведите количество добавляемых элементов K: ";
            cin >> K;

            if (K <= 0) 
            {
                cout << "Ошибка: количество добавляемых элементов K должно быть больше 0.\n";
                delete[] arr;
            }
            else 
            {
                int* arr_ins = ins_elems(arr, n, pos - 1, K);
                delete[] arr; // Освобождаем память промежуточного массива
                arr = arr_ins;
                n += K;

                cout << "Итоговый массив после добавления " << K << " элементов начиная с №" << pos << " (размер = " << n << "):\n";
                printarr(arr, n);

                delete[] arr; // Освобождаем память итогового массива
            }
        }
    }

    return 0;
}
