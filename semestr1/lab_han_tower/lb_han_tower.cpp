#include <iostream>
#include <clocale>

using namespace std;

const int N = 5;        // Количество колец
int towers[3][N];       // Состояние колец на 3 стержнях (индексы 0, 1, 2)
int top[3] = { 0, 0, 0 }; // Количество колец на каждом стержне
int step = 0;           // Счетчик ходов

// Функция наглядного вывода состояния трех стержней в консоль
void print_towers() 
{
    for (int level = N - 1; level >= 0; level--) 
    {
        for (int t = 0; t < 3; t++) 
        {
            if (level < top[t]) 
            {
                cout << "  [" << towers[t][level] << "]  ";
            }
            else 
            {
                cout << "   |   ";
            }
        }
        cout << "\n";
    }
    cout << " =====  =====  =====\n";
    cout << "  Ст.1   Ст.2   Ст.3\n\n";
}

// Функция перемещения одного верхнего кольца со стержня from на стержень to
void move_disk(int from, int to) 
{
    int f = from - 1;
    int t = to - 1;

    // Снимаем верхнее кольцо со стержня from
    top[f]--;
    int disk = towers[f][top[f]];

    // Надеваем кольцо на стержень to
    towers[t][top[t]] = disk;
    top[t]++;

    step++;
    cout << "Ход " << step << ": переложить кольцо " << disk 
         << " со стержня " << from << " на стержень " << to << "\n";
    print_towers();
}

// Рекурсивная функция решения задачи «Ханойская башня»
void hanoi(int count, int from, int to, int aux) 
{
    if (count == 1) 
    {
        move_disk(from, to);
    }
    else 
    {
        hanoi(count - 1, from, aux, to);
        move_disk(from, to);
        hanoi(count - 1, aux, to, from);
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    // Размещаем 5 колец на 1-м стержне (снизу вверх: 5, 4, 3, 2, 1)
    for (int i = 0; i < N; i++) 
    {
        towers[0][i] = N - i;
    }
    top[0] = N;

    cout << "Начальное состояние (5 колец на 1-м стержне):\n";
    print_towers();

    // Запускаем рекурсивный перенос 5 колец со стержня 1 на стержень 3 (вспомогательный - 2)
    hanoi(N, 1, 3, 2);

    cout << "Задача решена, минимальное количество ходов: " << step << "\n";

    return 0;
}
