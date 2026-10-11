#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m, r;

    // 1) n++ * m
    n = 5; m = 3;
    r = n++ * m;
    cout << "1) n++ * m = " << r << ", n = " << n << ", m = " << m << "\n";

    // 2) n++ < m
    n = 5; m = 3;
    r = n++ < m;
    cout << "2) n++ < m = " << r << ", n = " << n << ", m = " << m << "\n";

    // 3) m-- > m
    n = 5; m = 3;
    r = m-- > m;
    cout << "3) m-- > m = " << r << ", n = " << n << ", m = " << m << "\n";

    return 0;
}