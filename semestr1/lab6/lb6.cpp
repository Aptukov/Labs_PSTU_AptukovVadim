#include <iostream>
#include <clocale>
#include <cstdio>
#include <windows.h>

using namespace std;

const int mx_len = 256;

// Функция поиска и вывода слов, содержащих ровно одну цифру
void print_with_digit(const char s[]) 
{
    char word[mx_len];
    int w_idx = 0;        // Индекс текущего символа в буфере слова
    int digits_count = 0; // Счетчик цифр в текущем слове
    int found_count = 0;  // Счетчик найденных слов

    cout << "\nСлова, содержащие ровно одну цифру:\n";

    int i = 0;
    // Проходим по строке до точки или до конца строки
    while (s[i] != '\0' && s[i] != '.') 
    {
        if (s[i] != ' ') 
        {
            word[w_idx] = s[i];
            w_idx++;
            if (s[i] >= '0' && s[i] <= '9') 
            {
                digits_count++;
            }
        }
        else 
        {
            // Встретили пробел: если слово было накоплено, проверяем его
            if (w_idx > 0) 
            {
                word[w_idx] = '\0';
                if (digits_count == 1) 
                {
                    cout << word << "\n";
                    found_count++;
                }
                w_idx = 0;
                digits_count = 0;
            }
        }
        i++;
    }

    // Проверка последнего слова, стоящего непосредственно перед точкой
    if (w_idx > 0) 
    {
        word[w_idx] = '\0';
        if (digits_count == 1) 
        {
            cout << word << "\n";
            found_count++;
        }
    }

    if (found_count == 0) 
    {
        cout << "Слова с одной цифрой в тексте не найдены.\n";
    }
}

int main() 
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    char s[mx_len];

    cout << "Введите строку (до 255 символов, в конце поставьте точку):\n";
    gets(s);

    print_with_digit(s);

    return 0;
}
