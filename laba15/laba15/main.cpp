#include "Farm.h"

int main() {
    setlocale(LC_ALL, "Ru");
    Farm farm;

    farm.addAnimal(std::make_shared<Goose>(1, "����", 2, "������", "�����", "�����"));
    farm.addAnimal(std::make_shared<Penguin>(2, "�������", 3, "�����"));
    farm.addAnimal(std::make_shared<Ostrich>(3, "������", 5, "����������", "������"));
    farm.addAnimal(std::make_shared<Cow>(4, "������", 4, "����������", "�����"));

    std::cout << " ��������� ��������:\n";
    farm.displayAllAnimals();


    farm.paintAllAnimals();
    std::cout << "\n����������� ��������:\n";
    farm.displayAllAnimals();


    farm.removeAnimal(2);
    std::cout << "\n������ ������� ����������:\n";
    farm.displayAllAnimals();

        
    farm.givePrices();

    double eggsSold, milkSold, fuelUsed, feedCost;
    std::cout << "������� ���������� ��������� ���: ";    std::cin >> eggsSold;
    std::cout << "������� ����� ���������� ������: ";     std::cin >> milkSold;
    std::cout << "������� ����� ������������ �������: "; std::cin >> fuelUsed;
    std::cout << "������� ������� �� ����: ";             std::cin >> feedCost;

    farm.setSales(eggsSold, milkSold);
    farm.setExpenses(fuelUsed, feedCost);

    farm.displayFinancials();

    return 0;
}


//3. ������.
//
//��������:
//����
//������ : �����, ������, �������, ���� ���, ���� �������, ���� ��������.
//�������� : ���������(��������� ��� ����� ����	������� �������).
//�������
//������ : �����, ������, �������, ���� ��������.
//�������� : ���������(��������� ��� ����� ���� ������).
//������
//������ : �����, ������, �������, ���� ���, ���� �������.
//�������� : ���������(��������� ���� � ���� �������).
//
//����� Farm : �������� ��������, ��������� ���� ��������, ������� ��������, �������� ���� ��������.
// ��� ����� �����
// �������� ������
// ������� �����
// ���� ������� ���
// � ������
// 
// ���� ������� 
//���� ������ ������� � �������
// ���-�� ��� � ����� � ���-�� ������������ ������� ���� ���� ���������
