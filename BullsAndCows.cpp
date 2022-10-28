#include <iostream>
#include <ctime>
#include <string>

using namespace std;

string generation()    //���������� 4-� ������� �����, ������� ���������� ������� ������
{
    srand(time(0));
    const int size = 4;
    int random[size];
    string comp = "";
    bool flag;
    for (int i = 0; i < size;)
    {
        flag = false;
        int newRandom = rand() % 10;
        for (int j = 0; j < i; j++)
        {
            if (random[j] == newRandom)
            {
                flag = true;
            }
        }
        if (!flag)
        {
            random[i] = newRandom;
            i++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        comp += to_string(random[i]);
    }
    //cout << "�����, ���������� ����������� " << comp << endl;
    return comp;
}


bool checkNumber(string num) //�������� ������������ �����, ���������� �������
{
    bool flag = true;
    if ((num.length() == 4))
    {
        for (int i = 0; i < num.length(); i++)
        {
            if (not(isdigit(num[i])))
            {
                flag = false;
            }
            for (int j = 0; j < num.length() - 1; j++)
            {
                if (num[j] == num[j + 1]) flag = false;
            }
        }
    }
    else flag = false;
    return flag;
}

string vvod_number()   //�������, ������� �������� �� ���� �����
{
    string number;
    do
    {
        cout << "������� �������������� ����� � ���������� ������� : ";
        cin >> number;
        checkNumber(number);
    } while (checkNumber(number) == false);
    return number;
}

void bulls_cows(string digit_comp)
{
    int bulls = 0, cows = 0, attemp = 0;
    do {
        bulls = cows = 0;
        std::cout << "��� ����� ����: " << attemp + 1 << endl;
        string digit_player = vvod_number();
        attemp++;
        for (int i = 0; i < 4; i++)
        {
            if (digit_comp[i] == digit_player[i])
            {
                bulls++;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (digit_player[i] == digit_comp[j]) cows++;
            }
        }

        std::cout << "���������� ����� : " << cows - bulls << endl;
        std::cout << "���������� �����: " << bulls << endl;
    } while (bulls != 4);

    if (bulls == 4) cout << "����������! �� �������� �����, ���������� ����������� �� " << attemp;
    if (attemp % 10 == 1) cout << " ���";
    if (attemp % 10 > 1 && attemp % 10 <= 4) cout << " ����";
    if (!(attemp % 10 == 1) && !(attemp % 10 > 1 && attemp % 10 <= 4)) cout << " �����";
}

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "                                  **����� ���������� � ���� ���� � ������!**" << endl;
    cout << "������� ������ ���� ������: " << endl;
    cout << "�������� ���������� �������������� ����� � ���������� �������, � ���� ������ ������� ��� �����" << endl;
    cout << "��� ���������� ��� ����� ����������� 2 �������� : ���� � ������" << endl;
    cout << "��� - ��� �����, ������� ���� � ���������� ����� � ��������� �� ��� �� �������. " << endl;
    cout << "������ - ��� �����, ������� ��� �� ���� � ���������� �����, �� ��������� �� �� ���� �����." << endl;
    cout << "������!" << endl << "��������� ��������� �����, ���������� �����������!" << endl << endl << endl;

    string comp_digit = generation();
    bulls_cows(comp_digit);

}