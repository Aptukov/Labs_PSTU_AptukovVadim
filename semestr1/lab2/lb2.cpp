#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    int sum = 0; // Переменная для хранения суммы элементов
    // Цикл пробегает по всем целым числам от 21 до 99 с шагом 3
    for (int i = 21; i < 100; i += 3) 
    {
        sum += i;
    }
    cout << "Сумма целых чисел (от 21 до 99, кратных 3) = " << sum << "\n";

    return 0;
}
