#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << fixed;

    // РЕШЕНИЕ 1: float
    cout << "Решение 1: float" << endl;

    float a_f = 1000.0f, b_f = 0.0001f;
    float ab_f = a_f + b_f;

    float ab3_f  = ab_f * ab_f * ab_f;              // (a + b)^3
    float a3_f   = a_f * a_f * a_f;                 // a^3
    float numer_f = ab3_f - a3_f;                   // числитель

    float ab2_f  = 3.0f * a_f * b_f * b_f;          // 3 * a * b^2
    float b3_f   = b_f * b_f * b_f;                 // b^3
    float a2b_f  = 3.0f * a_f * a_f * b_f;          // 3 * a^2 * b
    float denom_f = ab2_f + b3_f + a2b_f;           // знаменатель

    float result_f = numer_f / denom_f;

    cout << "(a+b)^3             = " << ab3_f    << "\n";
    cout << "a^3                 = " << a3_f     << "\n";
    cout << "числитель           = " << numer_f  << "\n";
    cout << "знаменатель         = " << denom_f  << "\n";
    cout << "результат (float)   = " << result_f << "\n\n";

    // РЕШЕНИЕ 2: double
    cout << "Решение 2: double" << endl;

    double a_d = 1000.0f, b_d = 0.0001f;
    double ab_d = a_d + b_d;

    double ab3_d  = ab_d * ab_d * ab_d;             // (a + b)^3
    double a3_d   = a_d * a_d * a_d;                // a^3
    double numer_d = ab3_d - a3_d;                  // числитель

    double ab2_d  = 3.0 * a_d * b_d * b_d;          // 3 * a * b^2
    double b3_d   = b_d * b_d * b_d;                // b^3
    double a2b_d  = 3.0 * a_d * a_d * b_d;          // 3 * a^2 * b
    double denom_d = ab2_d + b3_d + a2b_d;          // знаменатель

    double result_d = numer_d / denom_d;

    cout << "(a+b)^3             = " << ab3_d    << endl;
    cout << "a^3                 = " << a3_d     << endl;
    cout << "числитель           = " << numer_d  << endl;
    cout << "знаменатель         = " << denom_d  << endl;
    cout << "результат (double)  = " << result_d << endl;

    return 0;
}
