#include <iostream>
#include <clocale>

using namespace std;

// Структура для представления комплексного числа
struct Complex 
{
    double re; // Действительная часть
    double im; // Мнимая часть
};

// 1-я перегруженная функция: вычитание целых чисел
int sub(int a, int b) 
{
    return a - b;
}

// 2-я перегруженная функция: вычитание комплексных чисел
Complex sub(Complex z1, Complex z2) 
{
    Complex res;
    res.re = z1.re - z2.re;
    res.im = z1.im - z2.im;
    return res;
}

// Перегруженная функция для вывода целого числа
void print_num(int x) 
{
    cout << x << "\n";
}

// Перегруженная функция для вывода комплексного числа
void print_num(Complex z) 
{
    if (z.im >= 0) 
    {
        cout << z.re << " + " << z.im << "i\n";
    }
    else 
    {
        cout << z.re << " - " << -z.im << "i\n";
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    // Вычитание целых чисел
    int a, b;
    cout << "Введите первое целое число: ";
    cin >> a;
    cout << "Введите второе целое число: ";
    cin >> b;

    int res_int = sub(a, b);
    cout << "Результат вычитания (" << a << " - " << b << ") = ";
    print_num(res_int);

    // Вычитание комплексных чисел
    Complex z1, z2;
    cout << "\nВычитание комплексных чисел\n";
    cout << "Введите действительную и мнимую части 1-го числа (через пробел): ";
    cin >> z1.re >> z1.im;
    cout << "Введите действительную и мнимую части 2-го числа (через пробел): ";
    cin >> z2.re >> z2.im;

    Complex res_comp = sub(z1, z2);
    cout << "Результат вычитания комплексных чисел = ";
    print_num(res_comp);

    return 0;
}