#include <iostream>
#include <clocale>
#include <cstdarg>

using namespace std;

// Функция с переменным числом параметров: S = a1*a2 + a3*a4 + a5*a6 + ...
int sum(int count, ...) 
{
    int s = 0;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count - 1; i += 2) 
    {
        int x1 = va_arg(args, int);
        int x2 = va_arg(args, int);
        s += x1 * x2;
    }

    va_end(args);
    return s;
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    // 1. Вызов функции sum с 8 параметрами
    int res8 = sum(8, 2, 3, 4, 5, 1, 6, 7, 2);
    cout << "1) Вызов для 8 параметров (2*3 + 4*5 + 1*6 + 7*2) = " << res8 << "\n";

    // 2. Вызов функции sum с 10 параметрами
    int res10 = sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    cout << "2) Вызов для 10 параметров (1*2 + 3*4 + 5*6 + 7*8 + 9*10) = " << res10 << "\n";

    // 3. Вызов функции sum с 12 параметрами
    int res12 = sum(12, 2, 2, 3, 3, 4, 4, 5, 5, 1, 10, 6, 2);
    cout << "3) Вызов для 12 параметров (2*2 + 3*3 + 4*4 + 5*5 + 1*10 + 6*2) = " << res12 << "\n";

    return 0;
}
