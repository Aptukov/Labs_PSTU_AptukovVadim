#include <iostream>
#include <clocale>
using namespace std;
#include <iomanip>
int main()
{
    cout << setprecision(15);
    setlocale(LC_ALL, "Russian");
    cout << fixed; /*   Числа перестают выводиться в научном формате вида  13238934y89234 + 67839678367834
                        1.23456e+06 и отображаются в обычном виде (1234560.0) */
    // Вычисления с типом данных float
    float a_f = 1000.0f, b_f = 0.0001f;
    float ab_f = a_f + b_f;
    float ab3_f  = ab_f * ab_f * ab_f;
    float a3_f   = a_f * a_f * a_f;
    float num1_f = ab3_f - a3_f;
    float ab2_f  = 3.0f * a_f * b_f * b_f;
    float b3_f   = b_f * b_f * b_f;
    float a2b_f  = 3.0f * a_f * a_f * b_f;
    float num2_f = ab2_f + b3_f + a2b_f;
    float ans_f = num1_f / num2_f;
    cout << "Результаты для float:" << "\n";
    cout << "(a+b)^3            = " << ab3_f   << "\n";
    cout << "a^3                = " << a3_f    << "\n";
    cout << "числитель          = " << num1_f  << "\n";
    cout << "знаменатель        = " << num2_f  << "\n";
    cout << "результат (float)   = " << ans_f   << "\n\n";

    // Вычисления с типом данных double
    double a_d = 1000.0, b_d = 0.0001;
    double ab_d = a_d + b_d;
    double ab3_d  = ab_d * ab_d * ab_d;
    double a3_d   = a_d * a_d * a_d;
    double num1_d = ab3_d - a3_d;
    double ab2_d  = 3.0 * a_d * b_d * b_d;
    double b3_d   = b_d * b_d * b_d;
    double a2b_d  = 3.0 * a_d * a_d * b_d;
    double num2_d = ab2_d + b3_d + a2b_d;
    double ans_d = num1_d / num2_d;
    cout << "Результаты для double:" << "\n";
    cout << "(a+b)^3            = " << ab3_d   << "\n";
    cout << "a^3                = " << a3_d    << "\n";
    cout << "числитель          = " << num1_d  << "\n";
    cout << "знаменатель        = " << num2_d  << "\n";
    cout << "результат (double) = " << ans_d   << "\n";

    return 0;
}
