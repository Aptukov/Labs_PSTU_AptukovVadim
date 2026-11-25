#include <iostream>
#include <clocale>

using namespace std;

// ==================== 1. ОДНОНАПРАВЛЕННЫЙ СПИСОК ====================

struct point 
{
    int key;
    point* next;
};

// Добавление в конец однонаправленного списка
point* push_back_1(point* first, int val) 
{
    point* p = new point;
    p->key = val;
    p->next = NULL;
    if (first == NULL) return p;

    point* cur = first;
    while (cur->next != NULL) 
    {
        cur = cur->next;
    }
    cur->next = p;
    return first;
}

// Формирование однонаправленного списка с клавиатуры
point* make_point(int n) 
{
    point* first = NULL;
    for (int i = 0; i < n; i++) 
    {
        int val;
        cout << "Введите элемент [" << i << "]: ";
        cin >> val;
        first = push_back_1(first, val);
    }
    return first;
}

// Печать однонаправленного списка
void print_point(point* first) 
{
    if (first == NULL) 
    {
        cout << "(список пуст)\n";
        return;
    }
    point* p = first;
    while (p != NULL) 
    {
        cout << p->key << " ";
        p = p->next;
    }
    cout << "\n";
}

// Добавление в начало однонаправленного списка
point* push_front_1(point* first, int val) 
{
    point* p = new point;
    p->key = val;
    p->next = first;
    return p;
}

// Добавление по заданному индексу (нумерация с 0)
point* insert_index_1(point* first, int idx, int val) 
{
    if (idx <= 0 || first == NULL) 
    {
        return push_front_1(first, val);
    }
    point* cur = first;
    for (int i = 0; i < idx - 1 && cur->next != NULL; i++) 
    {
        cur = cur->next;
    }
    point* p = new point;
    p->key = val;
    p->next = cur->next;
    cur->next = p;
    return first;
}

// Добавление перед заданным элементом
point* insert_before_1(point* first, int target, int val) 
{
    if (first == NULL) return NULL;
    if (first->key == target) 
    {
        return push_front_1(first, val);
    }
    point* cur = first;
    while (cur->next != NULL && cur->next->key != target) 
    {
        cur = cur->next;
    }
    if (cur->next != NULL) 
    {
        point* p = new point;
        p->key = val;
        p->next = cur->next;
        cur->next = p;
    }
    else 
    {
        cout << "Элемент " << target << " не найден.\n";
    }
    return first;
}

// Добавление после заданного элемента
point* insert_after_1(point* first, int target, int val) 
{
    point* cur = first;
    while (cur != NULL && cur->key != target) 
    {
        cur = cur->next;
    }
    if (cur != NULL) 
    {
        point* p = new point;
        p->key = val;
        p->next = cur->next;
        cur->next = p;
    }
    else 
    {
        cout << "Элемент " << target << " не найден.\n";
    }
    return first;
}

// Удаление k элементов начиная с индекса idx
point* delete_k_1(point* first, int idx, int k) 
{
    if (first == NULL || k <= 0 || idx < 0) return first;

    if (idx == 0) 
    {
        for (int i = 0; i < k && first != NULL; i++) 
        {
            point* temp = first;
            first = first->next;
            delete temp;
        }
        return first;
    }

    point* cur = first;
    for (int i = 0; i < idx - 1 && cur != NULL; i++) 
    {
        cur = cur->next;
    }
    if (cur == NULL) return first;

    for (int i = 0; i < k && cur->next != NULL; i++) 
    {
        point* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }
    return first;
}

// Добавление k вводимых элементов начиная с индекса idx
point* insert_k_1(point* first, int idx, int k) 
{
    for (int i = 0; i < k; i++) 
    {
        int val;
        cout << "Введите значение нового элемента " << i + 1 << ": ";
        cin >> val;
        first = insert_index_1(first, idx + i, val);
    }
    return first;
}

// Сортировка по возрастанию методом вставки
point* sort_asc_1(point* first) 
{
    point* sorted = NULL;
    point* cur = first;
    while (cur != NULL) 
    {
        point* next_node = cur->next;
        if (sorted == NULL || sorted->key >= cur->key) 
        {
            cur->next = sorted;
            sorted = cur;
        }
        else 
        {
            point* s = sorted;
            while (s->next != NULL && s->next->key < cur->key) 
            {
                s = s->next;
            }
            cur->next = s->next;
            s->next = cur;
        }
        cur = next_node;
    }
    return sorted;
}

// Сортировка по убыванию методом вставки
point* sort_desc_1(point* first) 
{
    point* sorted = NULL;
    point* cur = first;
    while (cur != NULL) 
    {
        point* next_node = cur->next;
        if (sorted == NULL || sorted->key <= cur->key) 
        {
            cur->next = sorted;
            sorted = cur;
        }
        else 
        {
            point* s = sorted;
            while (s->next != NULL && s->next->key > cur->key) 
            {
                s = s->next;
            }
            cur->next = s->next;
            s->next = cur;
        }
        cur = next_node;
    }
    return sorted;
}

// Удвоение однонаправленного списка целиком (1 2 3 -> 1 2 3 1 2 3)
point* double_list_1(point* first) 
{
    if (first == NULL) return NULL;

    int count = 0;
    point* cur = first;
    while (cur != NULL) 
    {
        count++;
        cur = cur->next;
    }

    cur = first;
    for (int i = 0; i < count; i++) 
    {
        first = push_back_1(first, cur->key);
        cur = cur->next;
    }
    return first;
}

// Освобождение памяти однонаправленного списка
void clear_1(point* first) 
{
    while (first != NULL) 
    {
        point* temp = first;
        first = first->next;
        delete temp;
    }
}

// ==================== 2. ДВУНАПРАВЛЕННЫЙ СПИСОК ====================

struct dpoint 
{
    int key;
    dpoint* next;
    dpoint* prev;
};

// Добавление в конец двунаправленного списка
dpoint* push_back_2(dpoint* first, int val) 
{
    dpoint* p = new dpoint;
    p->key = val;
    p->next = NULL;
    if (first == NULL) 
    {
        p->prev = NULL;
        return p;
    }
    dpoint* cur = first;
    while (cur->next != NULL) 
    {
        cur = cur->next;
    }
    cur->next = p;
    p->prev = cur;
    return first;
}

// Формирование двунаправленного списка с клавиатуры
dpoint* make_dpoint(int n) 
{
    dpoint* first = NULL;
    for (int i = 0; i < n; i++) 
    {
        int val;
        cout << "Введите элемент [" << i << "]: ";
        cin >> val;
        first = push_back_2(first, val);
    }
    return first;
}

// Печать двунаправленного списка
void print_dpoint(dpoint* first) 
{
    if (first == NULL) 
    {
        cout << "(список пуст)\n";
        return;
    }
    dpoint* p = first;
    while (p != NULL) 
    {
        cout << p->key << " ";
        p = p->next;
    }
    cout << "\n";
}

// Добавление в начало двунаправленного списка
dpoint* push_front_2(dpoint* first, int val) 
{
    dpoint* p = new dpoint;
    p->key = val;
    p->prev = NULL;
    p->next = first;
    if (first != NULL) 
    {
        first->prev = p;
    }
    return p;
}

// Добавление по заданному индексу
dpoint* insert_index_2(dpoint* first, int idx, int val) 
{
    if (idx <= 0 || first == NULL) 
    {
        return push_front_2(first, val);
    }
    dpoint* cur = first;
    for (int i = 0; i < idx - 1 && cur->next != NULL; i++) 
    {
        cur = cur->next;
    }
    dpoint* p = new dpoint;
    p->key = val;
    p->next = cur->next;
    p->prev = cur;
    if (cur->next != NULL) 
    {
        cur->next->prev = p;
    }
    cur->next = p;
    return first;
}

// Добавление перед заданным элементом
dpoint* insert_before_2(dpoint* first, int target, int val) 
{
    if (first == NULL) return NULL;
    if (first->key == target) 
    {
        return push_front_2(first, val);
    }
    dpoint* cur = first;
    while (cur != NULL && cur->key != target) 
    {
        cur = cur->next;
    }
    if (cur != NULL) 
    {
        dpoint* p = new dpoint;
        p->key = val;
        p->next = cur;
        p->prev = cur->prev;
        cur->prev->next = p;
        cur->prev = p;
    }
    else 
    {
        cout << "Элемент " << target << " не найден.\n";
    }
    return first;
}

// Добавление после заданного элемента
dpoint* insert_after_2(dpoint* first, int target, int val) 
{
    dpoint* cur = first;
    while (cur != NULL && cur->key != target) 
    {
        cur = cur->next;
    }
    if (cur != NULL) 
    {
        dpoint* p = new dpoint;
        p->key = val;
        p->next = cur->next;
        p->prev = cur;
        if (cur->next != NULL) 
        {
            cur->next->prev = p;
        }
        cur->next = p;
    }
    else 
    {
        cout << "Элемент " << target << " не найден.\n";
    }
    return first;
}

// Удаление k элементов начиная с индекса idx
dpoint* delete_k_2(dpoint* first, int idx, int k) 
{
    if (first == NULL || k <= 0 || idx < 0) return first;

    dpoint* cur = first;
    for (int i = 0; i < idx && cur != NULL; i++) 
    {
        cur = cur->next;
    }

    for (int i = 0; i < k && cur != NULL; i++) 
    {
        dpoint* temp = cur;
        cur = cur->next;

        if (temp->prev != NULL) 
            temp->prev->next = temp->next;
        else 
            first = temp->next;

        if (temp->next != NULL) 
            temp->next->prev = temp->prev;

        delete temp;
    }
    return first;
}

// Добавление k вводимых элементов начиная с индекса idx
dpoint* insert_k_2(dpoint* first, int idx, int k) 
{
    for (int i = 0; i < k; i++) 
    {
        int val;
        cout << "Введите значение нового элемента " << i + 1 << ": ";
        cin >> val;
        first = insert_index_2(first, idx + i, val);
    }
    return first;
}

// Сортировка по возрастанию методом вставки
dpoint* sort_asc_2(dpoint* first) 
{
    dpoint* sorted = NULL;
    dpoint* cur = first;
    while (cur != NULL) 
    {
        dpoint* next_node = cur->next;
        cur->prev = NULL;
        cur->next = NULL;

        if (sorted == NULL || sorted->key >= cur->key) 
{
cur->next = sorted;
if (sorted != NULL) sorted->prev = cur;
sorted = cur;
}
else
{
dpoint* s = sorted;
while (s->next != NULL && s->next->key < cur->key)
{
s = s->next;
}
cur->next = s->next;
if (s->next != NULL) s->next->prev = cur;
s->next = cur;
cur->prev = s;
}
cur = next_node;
}
return sorted;
}
// Сортировка по убыванию методом вставки
dpoint* sort_desc_2(dpoint* first)
{
    dpoint* sorted = NULL;
    dpoint* cur = first;
    while (cur != NULL)
    {
        dpoint* next_node = cur->next;
        cur->prev = NULL;
        cur->next = NULL;
        if (sorted == NULL || sorted->key <= cur->key)
        {
            cur->next = sorted;
            if (sorted != NULL) sorted->prev = cur;
            sorted = cur;
        }
        else
        {
            dpoint* s = sorted;
            while (s->next != NULL && s->next->key > cur->key)
            {
                s = s->next;
            }
            cur->next = s->next;
            if (s->next != NULL) s->next->prev = cur;
            s->next = cur;
            cur->prev = s;
        }
        cur = next_node;
    }
    return sorted;
}
// Удвоение двунаправленного списка целиком (1 2 3 -> 1 2 3 1 2 3)
dpoint* double_list_2(dpoint* first)
{
    if (first == NULL) return NULL;
    int count = 0;
    dpoint* cur = first;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    cur = first;
    for (int i = 0; i < count; i++)
    {
        first = push_back_2(first, cur->key);
        cur = cur->next;
    }
    return first;
}
// Освобождение памяти двунаправленного списка
void clear_2(dpoint* first)
{
    while (first != NULL)
    {
        dpoint* temp = first;
        first = first->next;
        delete temp;
    }
}
// ==================== ГЛАВНАЯ ФУНКЦИЯ ====================
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, val, idx, target, k;
    cout << "ЧАСТЬ 1. ОДНОНАПРАВЛЕННЫЙ СПИСОК\n";
    cout << "Введите количество элементов исходного списка: ";
    cin >> n;
    point* list1 = make_point(n);
    cout << "Исходный список: ";
    print_point(list1);
    cout << "\nВведите элемент для добавления в начало: ";
    cin >> val;
    list1 = push_front_1(list1, val);
    cout << "После добавления в начало: ";
    print_point(list1);
    cout << "\nВведите элемент для добавления в конец: ";
    cin >> val;
    list1 = push_back_1(list1, val);
    cout << "После добавления в конец: ";
    print_point(list1);
    cout << "\nВведите индекс для вставки и значение элемента: ";
    cin >> idx >> val;
    list1 = insert_index_1(list1, idx, val);
    cout << "После добавления по индексу: ";
    print_point(list1);
    cout << "\nВведите элемент, ПЕРЕД которым вставить, и новое значение: ";
    cin >> target >> val;
    list1 = insert_before_1(list1, target, val);
    cout << "После добавления перед заданным элементом: ";
    print_point(list1);
    cout << "\nВведите элемент, ПОСЛЕ которого вставить, и новое значение: ";
    cin >> target >> val;
    list1 = insert_after_1(list1, target, val);
    cout << "После добавления после заданного элемента: ";
    print_point(list1);
    cout << "\nВведите индекс начала удаления и количество элементов k: ";
    cin >> idx >> k;
    list1 = delete_k_1(list1, idx, k);
    cout << "После удаления k элементов: ";
    print_point(list1);
    cout << "\nВведите индекс начала вставки и количество элементов k: ";
    cin >> idx >> k;
    list1 = insert_k_1(list1, idx, k);
    cout << "После добавления k элементов: ";
    print_point(list1);
    list1 = sort_asc_1(list1);
    cout << "\nСортировка по возрастанию методом вставки: ";
    print_point(list1);
    list1 = sort_desc_1(list1);
    cout << "Сортировка по убыванию методом вставки: ";
    print_point(list1);
    list1 = double_list_1(list1);
    cout << "Удвоение списка целиком: ";
    print_point(list1);
    clear_1(list1);
    cout << "ЧАСТЬ 2. ДВУНАПРАВЛЕННЫЙ СПИСОК\n";
    cout << "Введите количество элементов исходного списка: ";
    cin >> n;
    dpoint* list2 = make_dpoint(n);
    cout << "Исходный список: ";
    print_dpoint(list2);
    cout << "\nВведите элемент для добавления в начало: ";
    cin >> val;
    list2 = push_front_2(list2, val);
    cout << "После добавления в начало: ";
    print_dpoint(list2);
    cout << "\nВведите элемент для добавления в конец: ";
    cin >> val;
    list2 = push_back_2(list2, val);
    cout << "После добавления в конец: ";
    print_dpoint(list2);
    cout << "\nВведите индекс для вставки и значение элемента: ";
    cin >> idx >> val;
    list2 = insert_index_2(list2, idx, val);
    cout << "После добавления по индексу: ";
    print_dpoint(list2);
    cout << "\nВведите элемент, ПЕРЕД которым вставить, и новое значение: ";
    cin >> target >> val;
    list2 = insert_before_2(list2, target, val);
    cout << "После добавления перед заданным элементом: ";
    print_dpoint(list2);
    cout << "\nВведите элемент, ПОСЛЕ которого вставить, и новое значение: ";
    cin >> target >> val;
    list2 = insert_after_2(list2, target, val);
    cout << "После добавления после заданного элемента: ";
    print_dpoint(list2);
    cout << "\nВведите индекс начала удаления и количество элементов k: ";
    cin >> idx >> k;
    list2 = delete_k_2(list2, idx, k);
    cout << "После удаления k элементов: ";
    print_dpoint(list2);
    cout << "\nВведите индекс начала вставки и количество элементов k: ";
    cin >> idx >> k;
    list2 = insert_k_2(list2, idx, k);
    cout << "После добавления k элементов: ";
    print_dpoint(list2);
    list2 = sort_asc_2(list2);
    cout << "\nСортировка по возрастанию методом вставки: ";
    print_dpoint(list2);
    list2 = sort_desc_2(list2);
    cout << "Сортировка по убыванию методом вставки: ";
    print_dpoint(list2);
    list2 = double_list_2(list2);
    cout << "Удвоение списка целиком: ";
    print_dpoint(list2);
    clear_2(list2);
    return 0;
}