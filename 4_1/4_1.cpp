//Задание 1
//1.  Создайте класс оружия со следующими полями : название оружия, наносимый урон и его вес.
//2.  Создайте конструктор, принимающий 3 параметра и использующий их для инициализации переменных класса.
//3.  Создайте конструктор без параметров, который будет вызывать конструктор из предыдущего пункта, передавая туда какие - то значения по умолчанию.
//4.  Создайте 2 объекта, используя конструктор с параметрами и без.
//5.  Выведите значения всех переменных обоих экземпляров в консоль.



#include <iostream>


class Weapon {
public:
    std::string name;
    double damage;
    double weight;

    Weapon(std::string name, double damage, double weight) : name(name), damage(damage), weight(weight) {}
    Weapon() : name("default"), damage(0), weight(0) {}
};

int main() {
    Weapon a("sword", 10.0, 5.0), b;

    std::cout << "Значения объекта a: \n";
    std::cout << "name: " << a.name << "\n";
    std::cout << "damage: " << a.damage << "\n";
    std::cout << "weight: " << a.weight << "\n";
    std::cout << "Значения объекта b: \n";
    std::cout << "name: " << b.name << "\n";
    std::cout << "damage: " << b.damage << "\n";
    std::cout << "weight: " << b.weight << "\n";
}