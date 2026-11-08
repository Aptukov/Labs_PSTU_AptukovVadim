#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cin >> n;

    if (n == 1) {
        cout << "*" << endl;
    } 
    else 
    {
        // Выводим начальную строчку из n звезд
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;

        // Выводим посередине n-2 строчек
        for (int i = 0; i < n - 2; i++) {
            cout << "*"; // Первая звезда в строке
            for (int j = 0; j < n - 2; j++) {
                cout << " "; // Пробелы между звездами
            }
            cout << "*" << endl; // Последняя звезда в строке
        }

        // Выводим конечную строчку из n звезд
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
