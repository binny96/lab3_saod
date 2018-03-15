#include <iostream>
#include <math.h>
#include <iomanip>
#include <conio.h>
#include <clocale>
#include <ctime>
#include <string.h>

using namespace std;

struct train {
    int number;
    char name[50];
    float time;
    train* next;
};

//поиск элемента в однонаправленном списке
bool Find(train* Head, int NumberItem) {
    train *ptr; //вспомогательным указатель
    ptr = Head;
    while (ptr != NULL) {//пока не конец списка
        if (NumberItem == ptr->number) return true;
        else ptr = ptr->next;
    }
    return false;
}



//вставка элемента с заданным номером в однонаправленный список
train* Make(train* Head, int Number) {
    Number--;
    train *NewItem = new(train);
    cout << "Номер поезда: ";
    while (!(cin >> NewItem->number) || Find(Head, NewItem->number) == true)
    {
        cout << "This number is already listed!" << endl;
        cout << "Enter number again: ";
    }

    cout << "Станция назначения: ";
    cin >> NewItem->name;

    cout << "Время отправления: ";
    cin >> NewItem->time;

    NewItem->next = NULL;

    if (Head == NULL) {//список пуст
        Head = NewItem;//создаем первый элемент списка
    }
    else {//список не пуст
        train *Current = Head;
        for (int i = 1; i < Number && Current->next != NULL; i++)
            Current = Current->next;
        if (Number == 0) {
            //вставляем новый элемент на первое место
            NewItem->next = Head;
            Head = NewItem;
        }
        else {//вставляем новый элемент на не первое место
            if (Current->next != NULL)
                NewItem->next = Current->next;
            Current->next = NewItem;
        }
    }
    return Head;
}

//печать однонаправленного списка
void Print(train* Head)
{
    if (Head == NULL)
        cout << "List is empty!";
    else
    {
        while (Head != NULL) {
            cout << "Номер_поезда" << "\t" << "Станция назначения" << "\t" << "Время отправления" << "\t" << endl;
            cout << "\t" << Head->number << "\t\t" << Head->name << "\t\t\t" << std::fixed << setprecision(2) << Head->time << endl;
            Head = Head->next;
            //переход к следующему элементу
        }
    }
}

//вывод элементов
void Show(train* Head)
{
    cout << "Номер_поезда" << "\t" << "Станция назначения" << "\t" << "Время отправления" << "\t" << endl;
    cout << "\t" << Head->number << "\t\t" << Head->name << "\t\t\t" << std::fixed << setprecision(2) << Head->time << endl;
}


//освобождение памяти, выделенной под однонаправленный список
void Delete(train* Head) {
    if (Head != NULL) {
        Delete(Head->next);
        delete Head;
    }
}

//поиск элемента (номера) в однонаправленном списке
void FindNumber(train* Head) {
    train *ptr; //вспомогательным указатель
    ptr = Head;
    int NumberItem = 0;
    cout << "Введите номер поезда: ";
    cin >> NumberItem;
    while (ptr != NULL) {//пока не конец списка
        if (NumberItem == ptr->number)
        {
            Show(ptr);
            return;
        }
        else ptr = ptr->next;
    }
    cout << "Информация о данном поезде отсутствует" << endl;
}

//поиск элемента(имени) в однонаправленном списке
void FindTime(train* Head) {
    train *ptr; //вспомогательным указатель
    ptr = Head;
    char *Name = new char;
    cout << "Введите название станции: ";
    cin >> Name;
    while (ptr != NULL) {//пока не конец списка
        if (strcmp(Name, ptr->name) == 0)
        {
            Show(ptr);
        }
        ptr = ptr->next;
    }
}

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    train *Head = NULL;
    int n = 1;

    char sw;
    do {
        cout << "\n1 - Добавить поезд в базу\n";
        cout << "2 - Вывести список поездов\n";
        cout << "3 - Показать информацию о поезде\n";
        cout << "4 - Показать информацию обо всех поездах, следующих до данной станции\n";
        cout << "5 - Выход\n";
        cout << "Ваш выбор: ";
        cin >> sw;
        cout << endl;
        if (sw == '1') {
            Head = Make(Head, n);
            n++;
        }
        else if (sw == '2')
            Print(Head);
        else if (sw == '3')
            FindNumber(Head);
        else if (sw == '4')
            FindTime(Head);
        else if (sw == '5')
        {
            Delete(Head);
        }
        else
            continue;
    } while (sw != '5');

    getch();
    return 0;
}
