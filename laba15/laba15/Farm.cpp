#include "Farm.h"

Goose::Goose(int num, const std::string& nm, int ag, const std::string& legClr, const std::string& wingClr, const std::string& bodyClr)
    : Animal(num, nm, ag), legColor(legClr), wingColor(wingClr), bodyColor(bodyClr) {}

void Goose::paint() {
    legColor = "Красный";
    wingColor = "Зеленый";
    bodyColor = "Голубой ";
}

void Goose::display() const {
    std::cout << "Гусь [Номер: " << number << ", Имя: " << name << ", Лет: " << age
        << ", цвет ног: " << legColor << ", Цвет крыльев: " << wingColor
        << ", цвет тела: " << bodyColor << "]\n";
}

Penguin::Penguin(int num, const std::string& nm, int ag, const std::string& bodyClr)
    : Animal(num, nm, ag), bodyColor(bodyClr) {}

void Penguin::paint() {
    bodyColor = "Черный";
}

void Penguin::display() const {
    std::cout << "Пингвин [Номер: " << number << ", Имя: " << name << ", Лет: " << age
        << ", Цвет тела: " << bodyColor << "]\n";
}


Ostrich::Ostrich(int num, const std::string& nm, int ag, const std::string& legClr, const std::string& wingClr)
    : Animal(num, nm, ag), legColor(legClr), wingColor(wingClr) {}

void Ostrich::paint() {
    legColor = wingColor;
}

void Ostrich::display() const {
    std::cout << "Страус [Номер: " << number << ", Имя: " << name << ", Лет: " << age
        << ", Цвет ног: " << legColor << ", Цвет крыльев: " << wingColor << "]\n";
}



Cow::Cow(int num, const std::string& nm, int ag,
    const std::string& bodyClr,
    const std::string& spotClr)
    : Animal(num, nm, ag),
    bodyColor(bodyClr),
    spotColor(spotClr) {}

void Cow::paint() {
    bodyColor = "Черный";
    spotColor = "Белый";
}

void Cow::display() const {
    std::cout << "Корова [Номер: " << number
        << ", Имя: " << name
        << ", Лет: " << age
        << ", основной цвет: " << bodyColor
        << ", цвет пятен: " << spotColor
        << "]\n";
}



void Farm::addAnimal(const std::shared_ptr<Animal>& animal) {
    animals.push_back(animal);
}

void Farm::paintAllAnimals() {
    for (const auto& animal : animals) {
        animal->paint();
    }
}

void Farm::removeAnimal(int number) {
    animals.erase(std::remove_if(animals.begin(), animals.end(),
        [number](const std::shared_ptr<Animal>& animal) {
            return animal->getNumber() == number;
        }),
        animals.end());
}

void Farm::displayAllAnimals() const {
    for (const auto& animal : animals) {
        animal->display();
    }
}

void Farm::givePrices() {
    std::cout << "цена за литр молока: " << milkPrice << std::endl
        << "цена за одно страусиное яйцо: " << eggPrice << std::endl
        << "цена за литр топлива: " << fuelPrice << std::endl;
}


void Farm::setSales(double eggs, double milk) {
    eggsSold = eggs;
    milkSold = milk;
}

void Farm::setExpenses(double fuel, double feed) {
    fuelUsed = fuel;
    feedCost = feed;
}

double Farm::calculateIncome() const {
    return eggsSold * eggPrice + milkSold * milkPrice;
}

double Farm::calculateExpenses() const {
    return fuelUsed * fuelPrice + feedCost;
}

void Farm::displayFinancials() const {
    std::cout << "\n=== Финансовый отчёт ===\n"
        << "Доход от яиц:  " << eggsSold << " * " << eggPrice << " = "
        << (eggsSold * eggPrice) << "\n"
        << "Доход от молока: " << milkSold << " * " << milkPrice << " = "
        << (milkSold * milkPrice) << "\n"
        << "Расходы на топливо: " << fuelUsed << " * " << fuelPrice << " = "
        << (fuelUsed * fuelPrice) << "\n"
        << "Расходы на корм:   " << feedCost << "\n"
        << "--------------------------\n"
        << "Итоговая прибыль:  "
        << (calculateIncome() - calculateExpenses()) << "\n";
}

