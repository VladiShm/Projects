#include <iostream>
#include <ctime>
#include <string>

using namespace std;

string generation()    //генерирует 4-х значное число, которое необходимо угадать игроку
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
    //cout << "число, загаданное компьютером " << comp << endl;
    return comp;
}


bool checkNumber(string num) //проверка корректности числа, введенного игроком
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

string vvod_number()   //Функция, которая отвечает за ввод числа
{
    string number;
    do
    {
        cout << "Введите четырехзначное число с различными цифрами : ";
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
        std::cout << "Ваш номер хода: " << attemp + 1 << endl;
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

        std::cout << "Количество коров : " << cows - bulls << endl;
        std::cout << "Количество быков: " << bulls << endl;
    } while (bulls != 4);

    if (bulls == 4) cout << "Поздравляю! Вы отгадали число, задуманное компьютером за " << attemp;
    if (attemp % 10 == 1) cout << " ход";
    if (attemp % 10 > 1 && attemp % 10 <= 4) cout << " хода";
    if (!(attemp % 10 == 1) && !(attemp % 10 > 1 && attemp % 10 <= 4)) cout << " ходов";
}

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "                                  **Добро пожаловать в игру Быки и Коровы!**" << endl;
    cout << "Правила данной игры просты: " << endl;
    cout << "Копьютер генерирует четырехзначное число с различными цифрами, а ваша задача угадать это число" << endl;
    cout << "При угадывании вам могут встретиться 2 ситуации : быки и коровы" << endl;
    cout << "Бык - это цифра, которая есть в загаданном числе и находится на той же позиции. " << endl;
    cout << "Корова - это цифра, которая так же есть в загаданном числе, но находится не на своём месте." << endl;
    cout << "Начнем!" << endl << "Начинайте угадывать число, задуманное компьютером!" << endl << endl << endl;

    string comp_digit = generation();
    bulls_cows(comp_digit);

}