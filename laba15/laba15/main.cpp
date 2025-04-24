#include "Farm.h"

int main() {
    setlocale(LC_ALL, "Ru");
    Farm farm;

    farm.addAnimal(std::make_shared<Goose>(1, "Гусь", 2, "Желтый", "Белый", "Серый"));
    farm.addAnimal(std::make_shared<Penguin>(2, "Пингвин", 3, "Белый"));
    farm.addAnimal(std::make_shared<Ostrich>(3, "Страус", 5, "Коричневый", "Черный"));
    farm.addAnimal(std::make_shared<Cow>(4, "Корова", 4, "Коричневый", "Белый"));

    std::cout << " Начальные животные:\n";
    farm.displayAllAnimals();


    farm.paintAllAnimals();
    std::cout << "\nПокрашенные животные:\n";
    farm.displayAllAnimals();


    farm.removeAnimal(2);
    std::cout << "\nСбежал пингвин несчастный:\n";
    farm.displayAllAnimals();

        
    farm.givePrices();

    double eggsSold, milkSold, fuelUsed, feedCost;
    std::cout << "Введите количество проданных яиц: ";    std::cin >> eggsSold;
    std::cout << "Введите литры проданного молока: ";     std::cin >> milkSold;
    std::cout << "Введите литры потраченного топлива: "; std::cin >> fuelUsed;
    std::cout << "Введите расходы на корм: ";             std::cin >> feedCost;

    farm.setSales(eggsSold, milkSold);
    farm.setExpenses(fuelUsed, feedCost);

    farm.displayFinancials();

    return 0;
}


//3. Фермер.
//
//Сущности:
//Гусь
//данные : номер, кличка, возраст, цвет лап, цвет крыльев, цвет туловища.
//действия : покрасить(покрасить все части тела	разными цветами).
//Пингвин
//данные : номер, кличка, возраст, цвет туловища.
//действия : покрасить(покрасить все части тела черным).
//Страус
//данные : номер, кличка, возраст, цвет лап, цвет крыльев.
//действия : покрасить(покрасить лапы в цвет крыльев).
//
//Класс Farm : добавить животное, покрасить всех животных, удалить животное, показать всех животных.
// над клвсс ферма
// добавить корову
// прибыль фермы
// типо продажа яиц
// и молока
// 
// есть прибыль 
//есть расход топлива и хавчика
// кол-во яиц я ввожу и кол-во потраченного топлива тоже надо вписывать
