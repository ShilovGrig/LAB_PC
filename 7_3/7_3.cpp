//Задание 3
//1.  Попросите пользователя ввести радиус окружности.
//2.  Выведите в консоль длину окружности(длина окружности считается по формуле : S = 2 * π * r).
//3.  Округлите полученный результат до 3 - х знаков после запятой и выведите его в консоль.
//4.  Попросите пользователя ввести произвольную строку.
//5.  Запишите полученную строку в конец текстового файла(то есть не стирая предыдущего содержимого) и запросите у пользователя снова строку(достигается это за счёт бесконечного цикла).
//6.  Если пользователь вводит read, то в консоль должно быть выведено всё содержимое текстового файла.При этом сама строка "read" в файл не должна попасть.
//7.  Если пользователь вводит erase, то необходимо очистить файл.При этом сама строка "erase" в файл не должна попасть.
//8.  Если пользователь вводит exit, то необходимо завершить программу(например, с помощью break из бесконечного цикла).При этом сама строка "exit" в файл не должна попасть.




#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    cout << "Введите радуис окружности\n";
    double r; cin >> r;
    double res = 2 * M_PI * r;

    cout << fixed << setprecision(3) << res << endl;


    std::ifstream myfile; myfile.open("a.txt");
    std::string mystring;
    if (myfile.is_open()) {
        char mychar;
        while (myfile) {
            mychar = myfile.get();
            std::cout << mychar;
        }
    }

    while (true) {
        cout << "Введите слова или команду read, erase или exit:\n";
        string s; cin >> s;
        if (s == "read") {
            std::ifstream myfile; myfile.open("a.txt");
            std::string mystring;
            if (myfile.is_open()) {
                char mychar;
                while (myfile) {
                    mychar = myfile.get();
                    std::cout << mychar;
                }
            }
        }
        else if (s == "erase") {
            std::ofstream ofs("a.txt", std::ios::out | std::ios::trunc);
            ofs.close();
        }
        else if (s == "exit") {
            break;
        }
        else {
            std::ofstream ofs("a.txt", std::ios::out | std::ios::app);
            ofs << s << std::endl;
            ofs.close();
        }
    }
}