//Задание 2
//1.  Сделайте класс оружия абстрактным, объявив чисто виртуальную функцию Attack.
//2.  В классе магического оружия реализуйте эту функцию, выведя в консоль : "Атакуем магическим оружием".
//3.  Убедитесь, что компилятор не даёт создать экземпляр абстрактного класса.
//4.  Создайте экземпляр магического оружия(если он не создан) и вызовите метод Attack у него.
//5.  Создайте ещё один дочерний класс от оружия, который будет отвечать за одноразовое оружие.
//6.  Добавьте поле - флаг, которое будет содержать true, если оружие уже было использовано и false, если ещё не было.
//7.  В функции Attack, если оружие уже было использовано, то выведите в консоль : "Оружие уже было использовано".Если же оружие ещё не было использовано, то вывести : "Атакуем одноразовым оружием" и установить флаг использования оружия в значение true.
//8.  Создайте экземпляр класса одноразового оружия и дважды вызовите метод Attack.Убедитесь, что всё работает правильно.
//9.  Создайте шаблон класса(с двумя параметрами), отвечающий за хранение оружие в левой руке и в правой.Типы оружия как раз и должны быть шаблонами.
//10. Сделайте конструктор для данного класса, а также GET и SET методы для обоих переменных.
//11. Проверьте работу шаблона(конструктора и методов), передав и тип оружия, и просто целый тип данных(например, это могут быть id оружия из какой - нибудь базы данных).



#include "5_2_1.h"

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
bool Weapon::operator>(Weapon weapon) { return this->get_damage() > weapon.get_damage(); }
bool Weapon::operator<(Weapon weapon) { return this->get_damage() < weapon.get_damage(); }

Player::Player(int id, std::string login, std::string password) : id(id), login(login), password(password) {}
void Player::print_info() {
    cout << "id: " << id << endl;
    cout << "login: " << login << endl;
    cout << "password: " << password << endl;
}

MagicWeapon::MagicWeapon(std::string name, double damage, double weight, WeaponType weaponType, double magic_damage) : Weapon(name, damage, weight, weaponType), magic_damage(magic_damage) {}
MagicWeapon::MagicWeapon() : Weapon(), magic_damage(0) {}
double MagicWeapon::get_magic_damage() { return magic_damage; }
double MagicWeapon::get_damage() { return damage + magic_damage; }
void MagicWeapon::Attack() { cout << "Атакуем магическим оружием" << endl; }

DisposableWeapon::DisposableWeapon(std::string name, double damage, double weight, WeaponType weaponType) : Weapon(name, damage, weight, weaponType) {}
DisposableWeapon::DisposableWeapon() : Weapon() {}
bool DisposableWeapon::is_used() { return used; }
void DisposableWeapon::Attack() { cout << (used ? "Оружие уже было использовано" : "Атакуем одноразовым оружием") << endl; used = true; }

template <typename A, typename B>
inline WeaponArms<A, B>::WeaponArms(A* weapon1, B* weapon2) : weapon1(weapon1), weapon2(weapon2) {}

template <typename A, typename B>
A* WeaponArms<A, B>::get_weapon1() { return weapon1; }

template <typename A, typename B>
B* WeaponArms<A, B>::get_weapon2() { return weapon2; }

template <typename A, typename B>
void WeaponArms<A, B>::set_weapon1(A* weapon1) { this->weapon1 = weapon1; }

template <typename A, typename B>
void WeaponArms<A, B>::set_weapon2(B* weapon2) { this->weapon2 = weapon2; }

int main() {
    DisposableWeapon dw;

    dw.Attack();
    dw.Attack();

    Weapon w1("sword", 10., 5., WeaponType::ONEHANDED);
    Weapon w2("sword2", 12., 7., WeaponType::ONEHANDED);

    WeaponArms<Weapon, Weapon> wa(&w1, &w2);

    cout << "Урон первого оружия: " << wa.get_weapon1()->get_damage() << endl;
    cout << "Урон второго оружия: " << wa.get_weapon2()->get_damage() << endl;

    int a = 2, b = 5;
    WeaponArms<int, int> wa2(&a, &b);

    cout << "Значение первого оружия Int: " << *wa2.get_weapon1() << endl;
    cout << "Значение второго оружия Int: " << *wa2.get_weapon2() << endl;

}