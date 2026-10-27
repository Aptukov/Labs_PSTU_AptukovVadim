#include <iostream>

using namespace std;

int main()
{
    int n, m, r;

    // 1) n++ * m
    n = 10; m = 2; // Для примера возьмем значения n=10 и m=2
    r = n++ * m;
    cout << "1) n++ * m = " << r << ", n = " << n << ", m = " << m << "\n";

    // 2) n++ < m
    n = 10; m = 2;
    r = n++ < m;
    cout << "2) n++ < m = " << r << ", n = " << n << ", m = " << m << "\n";

    // 3) m-- > m
    n = 10; m = 2;
    r = m-- > m;
    cout << "3) m-- > m = " << r << ", n = " << n << ", m = " << m << "\n";

    return 0;
}
