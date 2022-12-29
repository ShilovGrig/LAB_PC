//Задание 2
//1.  Попросите пользователя ввести своё имя и запишите его в переменную.
//2.  Сделайте регулярное выражение для проверки корректности имени(имя должно быть от 2 символов до 32 и содержать только буквы, причём первая обязательно должна быть заглавной).
//3.  Создайте строковую переменную, куда запишите произвольный текст, но в котором должно быть несколько e - mail адресов.
//4.  С помощью регулярного выражения вытащите из неё все e - mail адреса и выведите их в консоль.




#include <iostream>
#include <regex>

using namespace std;

bool is_valid_name(string name) {
    regex reg("^[A-Z]{1}[a-zA-Z]{1,31}$");
    return regex_search(name, reg);
}



int main() {
    cout << "Введите имя: \n";
    string name; cin >> name;
    if (is_valid_name(name)) {
        cout << "Ваше имя корректно" << endl;
    }
    else {
        cout << "Ваше имя не корректно" << endl;
    }
    string email_string = " name@mail.ru name name sec@mail.com";
    smatch matches;
    regex reg("\\w*@\\w*[.]\\w{2,5}");
    while (regex_search(email_string, matches, reg)) {
        cout << matches[0] << endl;
        email_string = matches.suffix().str();
    };
}