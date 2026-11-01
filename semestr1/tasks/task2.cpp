#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    const int n2 = 10;
    int arr[n2];
    
    // Ввод массива пользователем
    for (int i = 0; i < n2; ++i) {
        cin >> arr[i];
    }
    // 10 5 14 17 18 12 -10 1 -45 13
    
    bool F = false; // Флаг нарушения порядка
    int i = 0;
    
    while (i < n2 - 1) {
        if (arr[i] > arr[i + 1]) {
            F = true; 
            break;
        }
        i++;
    }

    if (!F) {
        cout << "Массив упорядочен по возрастанию.\n";
    } else {
        cout << "Массив не упорядочен по возрастанию.\n";
    }
    // Массив не упорядочен по возрастанию.
    return 0;
}
