//Задание 3
//1.  Создайте пустой вектор с типом float.
//2.  Добавьте 5 элементов в вектор.
//3.  Создайте функцию, которая принимает вектор и выводит его в консоли.
//4.  Вызовите созданную функцию.
//5.  Вставьте ещё один элемент между 3 и 4 элементами(индексы у них 2 и 3 соответственно).
//6.  Проверьте правильность сделанного, выведя вектор в консоль.
//7.  Удалите последний элемент.
//8.  Проверьте правильность сделанного, выведя вектор в консоль.
//9.  Создайте класс Settings(настройки) и добавьте в него поле типа Map.
//10. Добавьте в класс функцию Add, принимающую 2 строки(ключ и значение) и добавляющая их как новую пару в Map.
//11. Добавьте в класс функцию Get, принимающую строку(ключ) и возвращающая соответствующее ей значение в Map.
//12. Добавьте в класс функцию Print, которая будет выводить в консоль содержимое Map.
//13. Создайте экземпляр класса Settings и проверьте работу всех созданных методов.
//14. Сделайте поле Map у класса Settings статическим, а также сделайте статическими все его функции.
//15. Закомментируйте предыдущую проверку класса и проверьте его работу теперь, когда свойства и методы стали статическими.




#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Settings {
public:
    static std::map<int, int> m;

    static void Add(int key, int val);
    static int Get(int key);
    static void Print();
};

map<int, int> Settings::m;

void Settings::Add(int key, int val) { Settings::m[key] = val; }
int Settings::Get(int key) { return Settings::m[key]; }
void Settings::Print() { for (auto& u : Settings::m) cout << u.first << " : " << u.second << " "; cout << endl; }

void print_vector(vector<float>& v) {
    for (auto& u : v) {
        cout << u << " ";
    }
    cout << endl;
}

int main() {
    vector<float> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(i * 1.2);
    }
    print_vector(v);
    v.resize(6);
    for (int i = 5; i >= 4; i--) {
        v[i] = v[i - 1];
    }
    v[3] = 7;
    print_vector(v);
    v.resize(5);
    print_vector(v);

    // Settings set;
    // set.Add(1, 2);
    // set.Add(3, 1);
    // assert(set.Get(1) == 2);
    // assert(set.Get(3) == 1);
    // set.Add(1, 5);
    // assert(set.Get(1) == 5);

    Settings::Add(1, 2);
    Settings::Add(3, 1);
    assert(Settings::Get(1) == 2);
    assert(Settings::Get(3) == 1);
    Settings::Add(1, 5);
    assert(Settings::Get(1) == 5);

}