﻿// Задание 1
//1.    Выведите строку “First string” в консоль
//2.    Выведите сразу две строки «Первая строка» и «Вторая строка» в консоль, используя \n
//3.    Исправьте проблему с кодировкой(если вы этого еще не сделали)
//4.    Выведите строку «Спецсимволы “\”.Разумееется, кавычки и обратный слеш потребуется экранировать
//5.    Прокомментируйте каждую строку кода(включая #include и закрывающую фигурную скобку у main)






#include <iostream> // Подкючение библиотеки input-output stream для вывода и ввода в консоль

using namespace std; //Объявление пространства имён std

int main() { // Главная функция

	cout << "First string";  // Вывод строки
	cout << "Первая строка" << "\n" << "Вторая строка" << "\n";  // Вывод строки
	cout << "\"<<Спецсимволы “” " << endl;  // Вывод строки

} // Закрывающая скобка функции main