
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <conio.h>

using namespace std;

double getScalingValue(double num, double scale) {
    if (num > 70)
        return (40 * scale + 30 * scale / 2 + (num - 70) * scale / 4) / 100;
    else if (num > 40)
        return (40 * scale + (num - 40) * scale / 2) / 100;
    else
        return (num * scale) / 100;
}

class Weapon {
private:
    string name;
    double damage;
    double strScaling;
    double dexScaling;
    double intScaling;
    double upgradeType;
    double strReq;
    double dexReq;
    double intReq;
    double weight;
    string weaponClass;
    double range;
    double poison;
    double bleed;
    double slow;
    double scaledDamage;
    double weaponClassID;
    double crit;
public:
    Weapon(string a, double b, double c, double d, double e, double f, double g, double h, double i, double j, string k, double l, double m, double n, double o, double p) {
        name = a;
        damage = b;
        strScaling = c;
        dexScaling = d;
        intScaling = e;
        upgradeType = f;
        strReq = g;
        dexReq = h;
        intReq = i;
        weight = j;
        weaponClass = k;
        range = l;
        poison = m;
        bleed = n;
        slow = o;
        crit = p;
    }
    string getName() const {
        return name;
    }
    double getDamage() const {
        return damage;
    }
    double getStrScaling() const {
        return strScaling;
    }
    double getDexScaling() const {
        return dexScaling;
    }
    double getIntScaling() const {
        return intScaling;
    }
    double getStrReq() const {
        return strReq;
    }
    double getDexReq() const {
        return dexReq;
    }
    double getIntReq() const {
        return intReq;
    }
    double getWeight() const {
        return weight;
    }
    string getClass() const {
        return weaponClass;
    }
    double getClassID() const {
        return weaponClassID;
    }
    void setClass(string weaponClass) {
        if (weaponClass == "Very Light")
            weaponClassID = 0;
        else if (weaponClass == "Light")
            weaponClassID = 1;
        else if (weaponClass == "Medium")
            weaponClassID = 2;
        else if (weaponClass == "Heavy")
            weaponClassID = 3;
        else if (weaponClass == "Very Heavy")
            weaponClassID = 4;
        else if (weaponClass == "Very Heavy+")
            weaponClassID = 5;
    }
    double getRange() const {
        return range;
    }
    double getPoison() const {
        return poison;
    }
    double getBleed() const {
        return bleed;
    }
    double getSlow() const {
        return slow;
    }
    double getCrit() const {
        return crit;
    }
    double getUpgradeType() const {
        return upgradeType;
    }
    void setScaledDamage(double wlv, double str, double dex, double intl) {
        double dmg = damage * (1 + wlv * (2 - upgradeType) * 0.1);
        dmg = dmg * (1 + getScalingValue(str, strScaling) * (wlv / 10) + getScalingValue(dex, dexScaling) * (wlv / 10) + getScalingValue(intl, intScaling) * (wlv / 10));
        scaledDamage = roundf(dmg * 100) / 100;
    }
    double getScaledDamage() const {
        return scaledDamage;
    }
};

bool scaledDamageComparison(Weapon* a, Weapon* b)
{
    return a->getScaledDamage() < b->getScaledDamage();
}
bool weightComparison(Weapon* a, Weapon* b)
{
    return a->getWeight() < b->getWeight();
}
bool nameComparison(Weapon* a, Weapon* b)
{
    return a->getName() < b->getName();
}
bool classComparison(Weapon* a, Weapon* b)
{
    return a->getClassID() < b->getClassID();
}
bool rangeComparison(Weapon* a, Weapon* b)
{
    return a->getRange() < b->getRange();
}
bool poisonComparison(Weapon* a, Weapon* b)
{
    return a->getPoison() < b->getPoison();
}
bool bleedComparison(Weapon* a, Weapon* b)
{
    return a->getBleed() < b->getBleed();
}
bool slowComparison(Weapon* a, Weapon* b)
{
    return a->getSlow() < b->getSlow();
}
bool critComparison(Weapon* a, Weapon* b)
{
    return a->getCrit() < b->getCrit();
}
bool upgradeTypeComparison(Weapon* a, Weapon* b)
{
    return a->getUpgradeType() < b->getUpgradeType();
}

int main() {
    string line;

    double damage = 0, strScaling = 0, dexScaling = 0, intScaling = 0, upgradeType = 0, strReq = 0, dexReq = 0, intReq = 0, weight = 0, range = 0, poison = 0, bleed = 0, slow = 0, crit = 0, input = 0;
    string name = "", weaponClass = "", temp = "";
    vector<Weapon*> list;
    double str = 0, dex = 0, intl = 0, wepl = 0;

    do {
        list.clear();
        system("cls");
        ifstream myfile("items.txt");
        if (myfile.is_open())
        {


            cout << "Enter STR: ";
            while (true) {
                cin >> str;
                while (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "STR must be an integer between 1-99.\nEnter STR: ";
                    std::cin >> str;
                }
                if (str <= 0 || str > 99)
                {
                    std::cout << "STR must be an integer between 1-99.\nEnter STR: ";
                }
                else
                    break;
            }
            str = (int)str;
            cout << "Enter DEX: ";
            while (true) {
                cin >> dex;
                while (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "DEX must be an integer between 1-99.\nEnter DEX: ";
                    std::cin >> dex;
                }
                if (dex <= 0 || dex > 99)
                {
                    std::cout << "DEX must be an integer between 1-99.\nEnter DEX: ";
                }
                else
                    break;
            }
            dex = (int)dex;
            cout << "Enter INT: ";
            while (true) {
                cin >> intl;
                while (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "INT must be an integer between 1-99.\nEnter INT: ";
                    std::cin >> intl;
                }
                if (intl <= 0 || intl > 99)
                {
                    std::cout << "INT must be an integer between 1-99.\nEnter INT: ";
                }
                else
                    break;
            }
            intl = (int)intl;
            cout << "Enter weapon level: ";
            while (true) {
                cin >> wepl;
                while (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Weapon level must be an integer between 0-10.\nEnter weapon level: ";
                    std::cin >> wepl;
                }
                if (wepl < 0 || wepl > 10)
                {
                    std::cout << "Weapon level must be an integer between 0-10.\nEnter weapon level: ";
                }
                else
                    break;
            }
            wepl = (int)wepl;

            while (getline(myfile, line))
            {
                if (line.find("item.name") != string::npos) {

                    damage = 0, strScaling = 0, dexScaling = 0, intScaling = 0, upgradeType = 0, strReq = 0, dexReq = 0, intReq = 0, weight = 0, range = 0, poison = 0, bleed = 0, slow = 0, crit = 1;
                    name = "", weaponClass = "";

                    name = line.substr(line.find("&6") + 2);
                    name = name.substr(0, name.length() - 1);
                }
                else if (line.find("item.clas") != string::npos) {
                    weaponClass = line.substr(line.find("to ") + 4);
                    weaponClass = weaponClass.substr(0, weaponClass.length() - 1);
                }
                else if (line.find("item.phys") != string::npos || line.find("item.fire") != string::npos || line.find("item.eart") != string::npos || line.find("item.wind") != string::npos || line.find("item.wate") != string::npos) {
                    temp = line.substr(line.find("to ") + 3);
                    damage += stoi(temp);
                }
                else if (line.find("item.sscl") != string::npos) {
                    temp = line.substr(line.find("to ") + 4);
                    temp = temp.substr(0, 1);
                    if (temp == "S") {
                        strScaling = 6;
                    }
                    else if (temp == "A") {
                        strScaling = 5;
                    }
                    else if (temp == "B") {
                        strScaling = 4;
                    }
                    else if (temp == "C") {
                        strScaling = 3;
                    }
                    else if (temp == "D") {
                        strScaling = 2;
                    }
                    else if (temp == "E") {
                        strScaling = 1;
                    }
                }
                else if (line.find("item.dscl") != string::npos) {
                    temp = line.substr(line.find("to ") + 4);
                    temp = temp.substr(0, 1);
                    if (temp == "S") {
                        dexScaling = 6;
                    }
                    else if (temp == "A") {
                        dexScaling = 5;
                    }
                    else if (temp == "B") {
                        dexScaling = 4;
                    }
                    else if (temp == "C") {
                        dexScaling = 3;
                    }
                    else if (temp == "D") {
                        dexScaling = 2;
                    }
                    else if (temp == "E") {
                        dexScaling = 1;
                    }
                }
                else if (line.find("item.iscl") != string::npos) {
                    temp = line.substr(line.find("to ") + 4);
                    temp = temp.substr(0, 1);
                    if (temp == "S") {
                        intScaling = 6;
                    }
                    else if (temp == "A") {
                        intScaling = 5;
                    }
                    else if (temp == "B") {
                        intScaling = 4;
                    }
                    else if (temp == "C") {
                        intScaling = 3;
                    }
                    else if (temp == "D") {
                        intScaling = 2;
                    }
                    else if (temp == "E") {
                        intScaling = 1;
                    }
                }
                else if (line.find("item.strr") != string::npos) {
                    temp = line.substr(line.find("to ") + 3);
                    strReq = stoi(temp);
                }
                else if (line.find("item.dexr") != string::npos) {
                    temp = line.substr(line.find("to ") + 3);
                    dexReq = stoi(temp);
                }
                else if (line.find("item.intr") != string::npos) {
                    temp = line.substr(line.find("to ") + 3);
                    intReq = stoi(temp);
                }
                else if (line.find("item.weig") != string::npos) {
                    temp = line.substr(line.find("to ") + 3);
                    weight = stoi(temp);
                }
                else if (line.find("item.pois") != string::npos) {
                    temp = line.substr(line.find("to ") + 3);
                    poison = stoi(temp);
                }
                else if (line.find("item.blee") != string::npos) {
                    temp = line.substr(line.find("to ") + 3);
                    bleed = stoi(temp);
                }
                else if (line.find("item.slow") != string::npos) {
                    temp = line.substr(line.find("to ") + 3);
                    slow = stoi(temp);
                }
                else if (line.find("item.rang") != string::npos) {
                    temp = line.substr(line.find("to ") + 3);
                    range = stoi(temp);
                }
                else if (line.find("item.crit") != string::npos) {
                    temp = line.substr(line.find("to ") + 3);
                    crit = stod(temp);
                }
                else if (line.find("item.matr") != string::npos) {
                    upgradeType = 1;
                }
                else if (line.find("item.lvup") != string::npos) {
                    upgradeType = 2;
                }
                else if (line.find("set {id.") != string::npos) {
                    Weapon* weapon = new Weapon(name, damage, strScaling, dexScaling, intScaling, upgradeType, strReq, dexReq, intReq, weight, weaponClass, range, poison, bleed, slow, crit);
                    weapon->setScaledDamage(wepl, str, dex, intl);
                    weapon->setClass(weaponClass);
                    list.push_back(weapon);
                }
            }
            myfile.close();

            do {
                system("cls");
                cout << "MENU\n[====================]\n1 - Display\n2 - Sort by Damage\n3 - Sort by Weight\n4 - Sort by Class\n5 - Sort by Name\n6 - Sort by Range\n7 - Sort by Poison Inflict\n8 - Sort by Bleed Inflict\n9 - Sort by Slow Inflict\n10 - Sort by Crit Bonus\n11 - Sort by Materials Required\n12 - Enter New Stats\n13 - End\nEnter Command: ";
                cin >> input;
                if (input == 1) {
                    for (int i = 0; i < list.size(); i++)
                    {
                        if (str >= list[i]->getStrReq() && dex >= list[i]->getDexReq() && intl >= list[i]->getIntReq())
                        {
                            temp = "\t";
                            input = list[i]->getCrit();
                            if (input == 1 || input == 2 || input == 3)
                                temp = "\t\t";
                            cout << "Name: " << list[i]->getName() << "\nDamage: " << list[i]->getScaledDamage() << "\tWeight: " << list[i]->getWeight() << "\tRange: " << list[i]->getRange() << "\tClass: " << list[i]->getClass() << "\nCrit Bonus: " << input << "x" << temp << "Poison: " << list[i]->getPoison() << "\tBleed: " << list[i]->getBleed() << "\tSlow: " << list[i]->getSlow() << "\n\n";
                        }
                    }
                    cout << "Display complete. Press any key to continue...";
                    _getch();
                }
                else if (input == 2) {
                    std::sort(list.begin(), list.end(), scaledDamageComparison);
                    cout << "Sorted by damage. Press any key to continue...";
                    _getch();
                }
                else if (input == 3) {
                    std::sort(list.begin(), list.end(), weightComparison);
                    cout << "Sorted by weight. Press any key to continue...";
                    _getch();
                }
                else if (input == 4) {
                    std::sort(list.begin(), list.end(), classComparison);
                    cout << "Sorted by class. Press any key to continue...";
                    _getch();
                }
                else if (input == 5) {
                    std::sort(list.begin(), list.end(), nameComparison);
                    cout << "Sorted by name. Press any key to continue...";
                    _getch();
                }
                else if (input == 6) {
                    std::sort(list.begin(), list.end(), rangeComparison);
                    cout << "Sorted by range. Press any key to continue...";
                    _getch();
                }
                else if (input == 7) {
                    std::sort(list.begin(), list.end(), poisonComparison);
                    cout << "Sorted by poison inflict. Press any key to continue...";
                    _getch();
                }
                else if (input == 8) {
                    std::sort(list.begin(), list.end(), bleedComparison);
                    cout << "Sorted by bleed inflict. Press any key to continue...";
                    _getch();
                }
                else if (input == 9) {
                    std::sort(list.begin(), list.end(), slowComparison);
                    cout << "Sorted by slow inflict. Press any key to continue...";
                    _getch();
                }
                else if (input == 10) {
                    std::sort(list.begin(), list.end(), critComparison);
                    cout << "Sorted by crit bonus. Press any key to continue...";
                    _getch();
                }
                else if (input == 11) {
                    std::sort(list.begin(), list.end(), upgradeTypeComparison);
                    cout << "Sorted by materials required. Press any key to continue...";
                    _getch();
                }
            } while (input != 12 && input != 13);
        }
        else {
            cout << "Unable to open file";
            break;
        }
    } while (input != 13);

    return 0;
}