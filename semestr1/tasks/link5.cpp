#include <iostream>
using namespace std;

int main() {
    int a = 2, b = 5, c = 8;
    int* p = &a;     // p -> a
    int& r = a;      // r ссылается на a
    int copy = *p;   // copy = 2

    *p = b;          // a = b  ->  a = 5
    p = &c;          // p -> c
    r = *p;          // a = c  ->  a = 8
    *p = b + copy;   // c = 5 + 2  ->  c = 7
    p = &b;          // p -> b
    *p = r - copy;   // b = 8 - 2  ->  b = 6
    r++;             // a++  ->  a = 9

    cout << a << " " << b << " " << c << " " << copy << endl;
    // Результат работы: 9 6 7 2
    /*
    Ответы на вопросы:
    - В конце программы указатель p указывает на переменную b.
    - r обозначает ссылку на переменную a.
    */
    return 0;
}
