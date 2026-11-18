#include <iostream>
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

// Структура "Человек"
struct Person 
{
    char fio;     // Фамилия, имя, отчество
    char address; // Домашний адрес
    char phone;    // Номер телефона
    int age;           // Возраст
};

// Функция формирования одной структуры с клавиатуры (с помощью gets_s и >>)
Person input_person() 
{
    Person p;
    cout << "  ФИО: ";
    gets_s(p.fio);
    cout << "  Домашний адрес: ";
    gets_s(p.address);
    cout << "  Номер телефона: ";
    gets_s(p.phone);
    cout << "  Возраст: ";
    cin >> p.age;
    cin.ignore(); // Очистка символа '\n' из буфера после операции >>
    return p;
}

// 1. Функция формирования двоичного файла
void create_file(const char* fname, int count) 
{
    FILE* f;
    if ((f = fopen(fname, "wb")) == NULL) 
    {
        perror("\nОшибка при открытии файла для записи");
        exit(1);
    }

    for (int i = 0; i < count; i++) 
    {
        cout << "\nВведите данные для человека №" << i + 1 << ":\n";
        Person p = input_person();
        fwrite(&p, sizeof(Person), 1, f);
        if (ferror(f)) 
        {
            perror("\nОшибка при записи данных в файл");
            fclose(f);
            exit(2);
        }
    }

    fclose(f);
    cout << "\nФайл успешно сформирован.\n";
}

// 2. Функция печати содержимого двоичного файла
void print_file(const char* fname) 
{
    FILE* f;
    if ((f = fopen(fname, "rb")) == NULL) 
    {
        perror("\nОшибка при открытии файла для чтения");
        exit(3);
    }

    Person p;
    int num = 1;
    cout << "\n--- Содержимое двоичного файла ---\n";
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
        perror("\nОшибка при чтении данных из файла");
        fclose(f);
        exit(4);
    }

    if (num == 1) 
    {
        cout << "(Файл пуст)\n";
    }
    cout << "----------------------------------\n";

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
    FILE* fin;
    FILE* fout;

    if ((fin = fopen(fname, "rb")) == NULL) 
    {
        perror("\nОшибка открытия исходного файла при удалении");
        exit(5);
    }

    if ((fout = fopen("temp.dat", "wb")) == NULL) 
    {
        perror("\nОшибка создания вспомогательного файла");
        fclose(fin);
        exit(6);
    }

    Person p;
    int deleted_count = 0;

    while (fread(&p, sizeof(Person), 1, fin) == 1) 
    {
        if (!is_target_age(p, target_age)) 
        {
            fwrite(&p, sizeof(Person), 1, fout);
            if (ferror(fout)) 
            {
                perror("\nОшибка записи во вспомогательный файл");
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
        fclose(fin);
        fclose(fout);
        exit(8);
    }

    fclose(fin);
    fclose(fout);

    remove(fname);
    rename("temp.dat", fname);

    cout << "Удалено записей с возрастом " << target_age << ": " << deleted_count << "\n";
}

// 5. Функция добавления элемента после элемента с заданным номером через вспомогательный файл
void insert_after_num(const char* fname, int target_num, const Person& new_p) 
{
    FILE* fin;
    FILE* fout;

    if ((fin = fopen(fname, "rb")) == NULL) 
    {
        perror("\nОшибка открытия исходного файла при добавлении");
        exit(9);
    }

    if ((fout = fopen("temp.dat", "wb")) == NULL) 
    {
        perror("\nОшибка создания вспомогательного файла");
        fclose(fin);
        exit(10);
    }

    Person p;
    int current_num = 1;
    bool inserted = false;

    while (fread(&p, sizeof(Person), 1, fin) == 1) 
    {
        // Переписываем текущую запись
        fwrite(&p, sizeof(Person), 1, fout);
        if (ferror(fout)) 
        {
            perror("\nОшибка записи во вспомогательный файл");
            fclose(fin);
            fclose(fout);
            exit(11);
        }

        // После записи с заданным номером добавляем новую структуру
        if (current_num == target_num) 
        {
            fwrite(&new_p, sizeof(Person), 1, fout);
            if (ferror(fout)) 
            {
                perror("\nОшибка записи нового элемента");
                fclose(fin);
                fclose(fout);
                exit(12);
            }
            inserted = true;
        }
        current_num++;
    }

    if (ferror(fin)) 
    {
        perror("\nОшибка чтения исходного файла");
        fclose(fin);
        fclose(fout);
        exit(13);
    }

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
        cout << "Ошибка: согласно методическим указаниям, количество структур должно быть не менее 5.\n";
    }
    else 
    {
        // 1. Формирование и печать исходного файла
        create_file(filename, n);
        print_file(filename);

        // 2. Удаление всех элементов с заданным возрастом
        int del_age;
        cout << "\nВведите возраст для удаления записей: ";
        cin >> del_age;
        cin.ignore();

        delete_by_age(filename, del_age);
        print_file(filename);

        // 3. Добавление элемента после элемента с заданным номером
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
