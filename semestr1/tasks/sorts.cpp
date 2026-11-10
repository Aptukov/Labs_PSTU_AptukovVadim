#include <iostream>
#include <clocale>

using namespace std;

const int n = 7;

// 1. Сортировка Обменом (Пузырьковая)
void bubbleSort(int A[n]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int y = A[j];
                A[j] = A[j + 1];
                A[j + 1] = y;
            }
        }
    }
}

// 2. Сортировка Выбором
void selectionSort(int A[n]) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        int y = A[i];
        A[i] = A[min_idx];
        A[min_idx] = y;
    }
}

// 3. Сортировка Вставками
void insertionSort(int A[n]) {
    for (int i = 1; i < n; i++) {
        int y = A[i];
        int j = i - 1;
        bool f = j >= 0 && A[j] > y;
        while (f) {
            A[j + 1] = A[j];
            j--;
            f = j >= 0 && A[j] > y;
        }
        A[j + 1] = y;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Сортировка обменом
    int arr1[n] = {4, -1, 10, 160, 2, 7, -400};
    bubbleSort(arr1);
    cout << "Сортировка Обменом: ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << "\n";

    // Сортировка выбором
    int arr2[n] = {4, -1, 10, 160, 2, 7, -400};
    selectionSort(arr2);
    cout << "Сортировка Выбором: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << "\n";

    // Сортировка вставками
    int arr3[n] = {4, -1, 10, 160, 2, 7, -400};
    insertionSort(arr3);
    cout << "Сортировка Вставками: ";
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";
    cout << "\n";

    /*
    Сортировка Обменом: -400 -1 2 4 7 10 160 
    Сортировка Выбором: -400 -1 2 4 7 10 160 
    Сортировка Вставками: -400 -1 2 4 7 10 160 
    */

    return 0;
}
