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

//����� �������� � ���������������� ������
bool Find(train* Head, int NumberItem) {
    train *ptr; //��������������� ���������
    ptr = Head;
    while (ptr != NULL) {//���� �� ����� ������
        if (NumberItem == ptr->number) return true;
        else ptr = ptr->next;
    }
    return false;
}



//������� �������� � �������� ������� � ���������������� ������
train* Make(train* Head, int Number) {
    Number--;
    train *NewItem = new(train);
    cout << "����� ������: ";
    while (!(cin >> NewItem->number) || Find(Head, NewItem->number) == true)
    {
        cout << "This number is already listed!" << endl;
        cout << "Enter number again: ";
    }

    cout << "������� ����������: ";
    cin >> NewItem->name;

    cout << "����� �����������: ";
    cin >> NewItem->time;

    NewItem->next = NULL;

    if (Head == NULL) {//������ ����
        Head = NewItem;//������� ������ ������� ������
    }
    else {//������ �� ����
        train *Current = Head;
        for (int i = 1; i < Number && Current->next != NULL; i++)
            Current = Current->next;
        if (Number == 0) {
            //��������� ����� ������� �� ������ �����
            NewItem->next = Head;
            Head = NewItem;
        }
        else {//��������� ����� ������� �� �� ������ �����
            if (Current->next != NULL)
                NewItem->next = Current->next;
            Current->next = NewItem;
        }
    }
    return Head;
}

//������ ����������������� ������
void Print(train* Head)
{
    if (Head == NULL)
        cout << "List is empty!";
    else
    {
        while (Head != NULL) {
            cout << "�����_������" << "\t" << "������� ����������" << "\t" << "����� �����������" << "\t" << endl;
            cout << "\t" << Head->number << "\t\t" << Head->name << "\t\t\t" << std::fixed << setprecision(2) << Head->time << endl;
            Head = Head->next;
            //������� � ���������� ��������
        }
    }
}

//����� ���������
void Show(train* Head)
{
    cout << "�����_������" << "\t" << "������� ����������" << "\t" << "����� �����������" << "\t" << endl;
    cout << "\t" << Head->number << "\t\t" << Head->name << "\t\t\t" << std::fixed << setprecision(2) << Head->time << endl;
}


//������������ ������, ���������� ��� ���������������� ������
void Delete(train* Head) {
    if (Head != NULL) {
        Delete(Head->next);
        delete Head;
    }
}

//����� �������� (������) � ���������������� ������
void FindNumber(train* Head) {
    train *ptr; //��������������� ���������
    ptr = Head;
    int NumberItem = 0;
    cout << "������� ����� ������: ";
    cin >> NumberItem;
    while (ptr != NULL) {//���� �� ����� ������
        if (NumberItem == ptr->number)
        {
            Show(ptr);
            return;
        }
        else ptr = ptr->next;
    }
    cout << "���������� � ������ ������ �����������" << endl;
}

//����� ��������(�����) � ���������������� ������
void FindTime(train* Head) {
    train *ptr; //��������������� ���������
    ptr = Head;
    char *Name = new char;
    cout << "������� �������� �������: ";
    cin >> Name;
    while (ptr != NULL) {//���� �� ����� ������
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
        cout << "\n1 - �������� ����� � ����\n";
        cout << "2 - ������� ������ �������\n";
        cout << "3 - �������� ���������� � ������\n";
        cout << "4 - �������� ���������� ��� ���� �������, ��������� �� ������ �������\n";
        cout << "5 - �����\n";
        cout << "��� �����: ";
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
