//Задание 1
//1.       Создайте перечисление со следующими типами оружия : ONEHANDED(одноручное), TWOHANDED(двуручное), BOW(лук), CROSSBOW(арбалет).
//2.       Добавьте в класс оружия ещё одну private - переменную с типом перечисления.Безусловно, поменяйте и конструкторы, а также добавьте GET - метод.
//3.       В функции main, используя if, выведите текстовое представление типа оружия у объекта.Например, если оно равно ONEHANDED, то в консоли должно быть написано : "Одноручное оружие".
//4.       Создайте структуру игрока со следующими переменными : id(уникальный идентификатор), логин и пароль.
//5.       Добавьте функцию в структуру, которая выводит все данные в консоль.
//6.       Протестируйте созданную структуру, присвоив значения всем полям и вызвав созданную функцию.
//7.       Создайте дочерний класс от класса оружия, который будет отвечать за магическое оружие.
//8.       Добавьте в созданный класс private - поле, отвечающее за дополнительный урон.
//9.       Объявите 2 конструктора у созданного класса : с параметрами и без.
//10.   Создайте GET - метод для созданного поля.
//11.   Протестируйте созданный класс, его конструкторы и методы(в том числе, и те, что пришли из родительского класса).
//



#include "5_1.h"

using namespace std;

Weapon::Weapon(std::string name, double damage, double weight, WeaponType weapon_type) : name(name), damage(damage), weight(weight), weapon_type(weapon_type) {}
Weapon::Weapon() : name("default"), damage(0), weight(0), weapon_type(WeaponType::ONEHANDED) {}
Weapon::~Weapon() { std::cout << "Удаление объекта" << std::endl; }
bool Weapon::is_max_weight(double max_weight) { return max_weight < weight; }
double Weapon::sum_weight(Weapon* weapon) { return sum_weight(weapon->weight); }
double Weapon::sum_weight(double weight) { return this->weight + weight; }
std::string Weapon::get_name() { return name; }
double Weapon::get_damage() { return damage; }
double Weapon::get_weight() { return weight; }
void Weapon::set_damage(double damage) { this->damage = damage; }
WeaponType Weapon::get_weapon_type() { return weapon_type; }

Player::Player(int id, std::string login, std::string password) : id(id), login(login), password(password) {}
void Player::print_info() {
    cout << "id: " << id << endl;
    cout << "login: " << login << endl;
    cout << "password: " << password << endl;
}

MagicWeapon::MagicWeapon(std::string name, double damage, double weight, WeaponType weaponType, double magic_damage) : Weapon(name, damage, weight, weaponType), magic_damage(magic_damage) {}
MagicWeapon::MagicWeapon() : Weapon(), magic_damage(0) {}
double MagicWeapon::get_magic_damage() { return magic_damage; }


int main() {
    Weapon w("sword", 10.0, 5.0, WeaponType::ONEHANDED);

    if (w.get_weapon_type() == WeaponType::ONEHANDED) {
        cout << "одноручное оружие" << endl;
    }
    if (w.get_weapon_type() == WeaponType::TWOHANDED) {
        cout << "двуручное оружие" << endl;
    }
    if (w.get_weapon_type() == WeaponType::BOW) {
        cout << "лук" << endl;
    }
    if (w.get_weapon_type() == WeaponType::CROSSBOW) {
        cout << "арбалет" << endl;
    }

    Player p(1, "login", "password");
    p.print_info();
    assert(p.id == 1);
    assert(p.login == "login");
    assert(p.password == "password");

    MagicWeapon mw("sword", 10.0, 5.0, WeaponType::ONEHANDED, 10.0), mw_2;
    // Тестирование конструктора с параметрами
    assert(mw.get_magic_damage() == 10.0);
    assert(mw.get_damage() == 10.0);
    assert(mw.get_weight() == 5.0);
    assert(mw.get_name() == "sword");
    assert(mw.get_weapon_type() == WeaponType::ONEHANDED);
    // Тестирование конструктора без параметров
    assert(mw_2.get_magic_damage() == 0.0);
    assert(mw_2.get_damage() == 0.0);
    assert(mw_2.get_weight() == 0.0);
    assert(mw_2.get_name() == "default");
    assert(mw_2.get_weapon_type() == WeaponType::ONEHANDED);

}