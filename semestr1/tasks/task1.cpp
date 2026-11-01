#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    const int n1 = 10;
    int arr[n1];
    
    // Ввод массива пользователем
    for (int i = 0; i < n1; ++i) {
        cin >> arr[i];
    }
    // 10 5 14 17 18 12 -10 1 -45 13
    
    int min_val = arr[0], max_val = arr[0];
    int min_idx = 0, max_idx = 0;
    int min_count = 1, max_count = 1;

    for (int i = 1; i < n1; ++i) {
        // Поиск и подсчет минимума
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_idx = i;
            min_count = 1; 
        } else if (arr[i] == min_val) {
            min_count++;
        }

        // Поиск и подсчет максимума
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_idx = i;
            max_count = 1; 
        } else if (arr[i] == max_val) {
            max_count++;
        }
    }

    cout << "Результат:\n";
    cout << "Min: " << min_val << " (Индекс: " << min_idx << ", Порядковый номер: " << min_idx + 1 << ", Кол-во: " << min_count << ")\n";
    cout << "Max: " << max_val << " (Индекс: " << max_idx << ", Порядковый номер: " << max_idx + 1 << ", Кол-во: " << max_count << ")\n";

    /*
    Результат:
    Min: -45 (Индекс: 8, Порядковый номер: 9, Кол-во: 1)
    Max: 18 (Индекс: 4, Порядковый номер: 5, Кол-во: 1)
    */

    return 0;
}
