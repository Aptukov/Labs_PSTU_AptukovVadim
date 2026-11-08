#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL,"Russian");
    int n;
    cin >> n;

    // Проверка на чётность
    if (n % 2 == 0) {
        std::cout << "n - чётное" << std::endl;
    } 
    else 
    {
        for (int i = 1; i <= n; i += 2) 
        {
            // Выводи пробелы
            for (int j = 0; j < (n - i) / 2; ++j) {
                cout << " ";
            }
            // Выводим звёзды
            for (int k = 0; k < i; ++k) {
                cout << "*";
            }
        cout << endl;
        }
    }

    return 0;
}
