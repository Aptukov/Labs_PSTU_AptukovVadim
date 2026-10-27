#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    cout << fixed;

    double a = 0.1;
    double b = 0.8;
    int k = 10;
    int n_max = 10;
    double E = 0.0001; 
    double h = (b - a) / k; // Шаг изменения x

    cout << "Вычисление функции" << "\n";
    for (double x = a; x <= b + h/2; x += h) // Внешний цикл: изменение параметра x
    /* Прибавление h/2.0 к b нужно, чтобы из-за
    погрешностей double не пропустить последнее значение x=0.8 */
    {
        // Первый цикл для нахождения суммы ряда для заданного n (SN)
        double sn = 0.0;
        double curr_n = x * x / 2; // Первый член ряда при n=1
        sn += curr_n;

        for (int n = 2; n <= n_max; n++)
        {
            double R = -x * x * (n-1) * (2*n-3) / (n * (2*n-1));
            curr_n *= R;
            sn += curr_n;
        }

        // Второй цикл для нахождения суммы ряда для заданной точности E (SE)
        double se = 0.0;
        double curr_e = x * x / 2; // Первый член ряда при i=1
        se += curr_e;
        int i = 2;

        while (abs(curr_e) >= E)
        {
            double R = -x * x * (i-1) * (2*i-3) / (i*(2*i-1));
            curr_e *= R;
            se += curr_e;
            i++;
        }
        // Точное аналитическое значение функции (Y)
        double y = x * atan(x) - log(sqrt(1 + x * x));
        // Вывод строки результатов
        cout << "X=" << x << "    SN=" << sn << "    SE=" << se << "    Y=" << y << "\n";
    }
    return 0;
}
