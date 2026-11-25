#include <iostream>
#include <windows.h>
#include <clocale>

using namespace std;

// Прототип функции
void sum(int, int);

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;

    sum(a, b);

    return 0;
}

// Определение функции
void sum(int a, int b) {
    cout << "Результат суммы: " << a + b << endl;
}
