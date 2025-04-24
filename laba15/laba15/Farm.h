#ifndef FARM_H
#define FARM_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>


class Animal {
protected:
    int number;
    std::string name;
    int age;

public:
    Animal(int num, const std::string& nm, int ag) : number(num), name(nm), age(ag) {}
    virtual ~Animal() {}

    virtual void paint() = 0;
    virtual void display() const = 0;
    int getNumber() const { return number; }
};

class Goose : public Animal {
private:
    std::string legColor;
    std::string wingColor;
    std::string bodyColor;

public:
    Goose(int num, const std::string& nm, int ag, const std::string& legClr, const std::string& wingClr, const std::string& bodyClr);
    void paint() override;
    void display() const override;
};

class Penguin : public Animal {
private:
    std::string bodyColor;

public:
    Penguin(int num, const std::string& nm, int ag, const std::string& bodyClr);
    void paint() override;
    void display() const override;
};

class Ostrich : public Animal {
private:
    std::string legColor;
    std::string wingColor;

public:
    Ostrich(int num, const std::string& nm, int ag, const std::string& legClr, const std::string& wingClr);
    void paint() override;
    void display() const override;
};


class Cow : public Animal {
private:
    std::string bodyColor;
    std::string spotColor;

public:
    Cow(int num, const std::string& nm, int ag,
        const std::string& bodyClr,
        const std::string& spotClr);
    void paint() override;
    void display() const override;
};



class Farm {
private:
    std::vector<std::shared_ptr<Animal>> animals;

    double eggsSold = 0;
    double milkSold = 0;
    double fuelUsed = 0;
    double feedCost = 0;

    double eggPrice = 12;
    double milkPrice = 65;
    double fuelPrice = 57;

public:
    void addAnimal(const std::shared_ptr<Animal>& animal);
    void paintAllAnimals();
    void removeAnimal(int number);
    void displayAllAnimals() const;
    void givePrices();
    void setSales(double eggs, double milk);
    void setExpenses(double fuel, double feed);
    double calculateIncome()   const;
    double calculateExpenses() const;
    void   displayFinancials() const;
};

#endif 
