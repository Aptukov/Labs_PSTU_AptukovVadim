#include <iostream>
#include <string>
#include <clocale>
#include <windows.h> // Для корректного ввода русских символов с клавиатуры

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);       // Кодировка для ввода (cin)
    SetConsoleOutputCP(1251); // Кодировка для вывода (cout)

    string word;
    cout << "Введите слово: ";
    cin >> word;

    // Проверяем, длиннее ли слово 5 символов
    if (word.length() > 5) {
        word[0] = 'X'; // Заменяем первую букву (индекс 0)
    } else {
        word[word.length() - 1] = 'X'; // Заменяем последнюю букву
    }

    // Выводим слово справа налево
    cout << "Результат: ";
    for (int i = word.length() - 1; i >= 0; i--) {
        cout << word[i];
    }
    cout << endl;

    return 0;
}
