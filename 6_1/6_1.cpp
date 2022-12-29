//Задание 1
//1.  Попросите пользователя ввести число 1, 2 или 3 и выведите его в текстовом виде : "Один", "Два" или "Три" соответственно.
//2.  Если пользователь ввёл другое число, то выбросите исключение, в обработке которого выведите в консоль : "Некорректное значение".
//3.  Попросите пользователя ввести год своего рождения.
//4.  Если пользователь ввёл число меньше 1850, то выбросите исключение и в catch выведите в консоли : "Что-то не верится...".
//5.  Если пользователь ввёл число больше, чем текущий год, то выбросите исключение и в catch выведите в консоли : "Вы ещё не родились".
//6.  Если пользователь ввёл отрицательное число, то выбросите исключение и в catch выведите в консоли : "Вы ввели отрицательное число!".
//7.  Если ввод был корректный(и не было, как следствие, исключений), то выведите в консоль : "Спасибо!".
//8.  Создайте свой класс исключений с перечислением(для кода ошибок) и переработайте задание с годом рождения так, чтобы выбрасывалось уже Ваше исключение.



#include <iostream>

using namespace std;

enum class UserError {
    NOT_CORRECT,
    OLD,
    BIG,
    NEGATIVE
};

class UserException : public std::exception {
private:
    UserError code;
public:
    UserException(UserError code) : code(code) {}

    const char* what() const throw() override {
        if (code == UserError::NOT_CORRECT) return "Некорректное значение";
        else if (code == UserError::OLD) return "Что-то не верится...";
        else if (code == UserError::BIG) return "Вы ещё не родились";
        else if (code == UserError::NEGATIVE) return "Вы ввели отрицательное число!";
    }
};
int main() {
    int a;
    cout << "Введите число 1, 2 или 3\n";
    try {
        cin >> a;
        if (!(a == 1 || a == 2 || a == 3)) throw UserException(UserError::NOT_CORRECT);
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    cout << "Введите год своего рождения: \n";
    int year;
    try {
        cin >> year;
        if (year < 0) throw UserException(UserError::NEGATIVE);
        else if (year < 1850) throw UserException(UserError::OLD);
        else if (year > 2022) throw UserException(UserError::BIG);
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    cout << "Спасибо!\n";

}