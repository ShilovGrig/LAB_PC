﻿//Задание 1
//1.       Попросите пользователя ввести строку и запишите её в переменную.
//2.       Выведите в консоли подстроку из строки от пользователя от 2 - го символа до 4 - го символа включительно.
//3.       Выведите индекс первого вхождения строки "a" в строку пользователя, а если вхождения нет, то выведите в консоль : "Символа a не найдено".
//



#include <iostream>

using namespace std;

int main() {
    cout << "Введите строку: \n";
    string s; cin >> s;
    cout << s.substr(1, 3) << endl;
    size_t f = s.find('a');
    if (f >= s.size()) {
        cout << "Символа a не найдено" << endl;
    }
    else {
        cout << "Интекс первого вождения символа а: " << f << endl;
    }
}