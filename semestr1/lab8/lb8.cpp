#include <iostream>
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

// Структура "Человек" с фиксированными размерами массивов
struct Person 
{
    char fio[100];     // Фамилия, имя, отчество
    char address[100]; // Домашний адрес
    char phone[30];    // Номер телефона
    int age;           // Возраст
};

// Функция ввода данных об одном человеке с клавиатуры
Person input_person() 
{
    Person p;
    cout << "  ФИО: ";
    cin.getline(p.fio, 100);
    cout << "  Домашний адрес: ";
    cin.getline(p.address, 100);
    cout << "  Номер телефона: ";
    cin.getline(p.phone, 30);
    cout << "  Возраст: ";
    cin >> p.age;
    cin.ignore(); // Очищаем буфер от символа перехода на новую строку '\n'
    return p;
}

// 1. Функция формирования двоичного файла
void create_file(const char* fname, int count) 
{
    FILE* f = fopen(fname, "wb");
    if (f == NULL) 
    {
        perror("\nОшибка открытия файла для записи");
        exit(1);
    }

    for (int i = 0; i < count; i++) 
    {
        cout << "\nВведите данные для человека №" << i + 1 << ":\n";
        Person p = input_person();
        
        if (fwrite(&p, sizeof(Person), 1, f) != 1) 
        {
            perror("\nОшибка записи в файл");
            fclose(f);
            exit(2);
        }
        fflush(f); // Принудительно записываем данные из буфера на диск
    }

    fclose(f);
    cout << "\nФайл " << fname << " успешно сформирован.\n";
}

// 2. Функция печати содержимого двоичного файла
void print_file(const char* fname) 
{
    FILE* f = fopen(fname, "rb");
    if (f == NULL) 
    {
        perror("\nОшибка открытия файла для чтения");
        exit(3);
    }

    Person p;
    int num = 1;
    cout << "\n--- Содержимое файла " << fname << " ---\n";
    
    while (fread(&p, sizeof(Person), 1, f) == 1) 
    {
        cout << num << ". ФИО: " << p.fio
             << " | Адрес: " << p.address
             << " | Тел.: " << p.phone
             << " | Возраст: " << p.age << "\n";
        num++;
    }

    if (ferror(f)) 
    {
        perror("\nОшибка при чтении файла");
        fclose(f);
        exit(4);
    }

    if (num == 1) 
    {
        cout << "(Файл пуст)\n";
    }
    cout << "--------------------------------------\n";

    fclose(f);
}

// 3. Функция поиска/проверки совпадения возраста для удаления
bool is_target_age(const Person& p, int target_age) 
{
    return p.age == target_age;
}

// 4. Функция удаления всех элементов с заданным возрастом через вспомогательный файл
void delete_by_age(const char* fname, int target_age) 
{
    FILE* fin = fopen(fname, "rb");
    if (fin == NULL) 
    {
        perror("\nОшибка открытия исходного файла");
        exit(5);
    }

    FILE* fout = fopen("temp.dat", "wb");
    if (fout == NULL) 
    {
        perror("\nОшибка создания временного файла");
        fclose(fin);
        exit(6);
    }

    Person p;
    int deleted_count = 0;

    while (fread(&p, sizeof(Person), 1, fin) == 1) 
    {
        if (!is_target_age(p, target_age)) 
        {
            if (fwrite(&p, sizeof(Person), 1, fout) != 1) 
            {
                perror("\nОшибка записи во временный файл");
                fclose(fin);
                fclose(fout);
                exit(7);
            }
        }
        else 
        {
            deleted_count++;
        }
    }

    if (ferror(fin)) 
    {
        perror("\nОшибка чтения исходного файла");
    }

    fflush(fout);
    fclose(fin);
    fclose(fout);

    remove(fname);
    rename("temp.dat", fname);

    cout << "Удалено записей с возрастом " << target_age << ": " << deleted_count << "\n";
}

// 5. Функция добавления элемента после элемента с заданным номером через вспомогательный файл
void insert_after_num(const char* fname, int target_num, const Person& new_p) 
{
    FILE* fin = fopen(fname, "rb");
    if (fin == NULL) 
    {
        perror("\nОшибка открытия исходного файла");
        exit(8);
    }

    FILE* fout = fopen("temp.dat", "wb");
    if (fout == NULL) 
    {
        perror("\nОшибка создания временного файла");
        fclose(fin);
        exit(9);
    }

    Person p;
    int current_num = 1;
    bool inserted = false;

    while (fread(&p, sizeof(Person), 1, fin) == 1) 
    {
        // Переписываем текущий элемент
        if (fwrite(&p, sizeof(Person), 1, fout) != 1) 
        {
            perror("\nОшибка записи во временный файл");
            fclose(fin);
            fclose(fout);
            exit(10);
        }

        // Сразу после элемента с заданным номером записываем новый
        if (current_num == target_num) 
        {
            if (fwrite(&new_p, sizeof(Person), 1, fout) != 1) 
            {
                perror("\nОшибка записи нового элемента");
                fclose(fin);
                fclose(fout);
                exit(11);
            }
            inserted = true;
        }
        current_num++;
    }

    if (ferror(fin)) 
    {
        perror("\nОшибка чтения исходного файла");
    }

    fflush(fout);
    fclose(fin);
    fclose(fout);

    remove(fname);
    rename("temp.dat", fname);

    if (inserted) 
    {
        cout << "Новый элемент успешно добавлен после записи №" << target_num << ".\n";
    }
    else 
    {
        cout << "Запись с номером " << target_num << " не найдена, добавление не выполнено.\n";
    }
}

int main() 
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    const char* filename = "people.dat";
    int n;

    cout << "Введите количество человек для записи в файл (не менее 5): ";
    cin >> n;
    cin.ignore(); // Очистка буфера после ввода числа

    if (n < 5) 
    {
        cout << "Ошибка: по методическим указаниям нужно ввести не менее 5 структур.\n";
    }
    else 
    {
        // Шаг 1: Создание файла и печать его содержимого
        create_file(filename, n);
        print_file(filename);

        // Шаг 2: Удаление всех элементов с заданным возрастом
        int del_age;
        cout << "\nВведите возраст для удаления записей: ";
        cin >> del_age;
        cin.ignore();

        delete_by_age(filename, del_age);
        print_file(filename);

        // Шаг 3: Добавление нового элемента после элемента с заданным номером
        int pos_num;
        cout << "\nВведите номер элемента, после которого нужно добавить новую запись: ";
        cin >> pos_num;
        cin.ignore();

        cout << "Введите данные нового человека:\n";
        Person new_person = input_person();

        insert_after_num(filename, pos_num, new_person);
        print_file(filename);
    }

    return 0;
}