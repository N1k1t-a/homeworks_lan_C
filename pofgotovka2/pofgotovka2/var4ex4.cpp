#include <iostream>


class Person {
protected:
	std::string name;
	int age;

public:
	Person(std::string name_val, int age_val){
		name = name_val;
		age = age_val;
	}

	void show() {
		std::cout << name << age;
	}
};

class Worker : public Person {
protected:
	int zp;
	int stag;

public:
	Worker(std::string name_val, int age_val, int val_zp, int val_stag) : Person(name_val, age_val) {
		zp = val_zp;
		stag = val_stag;
	}
};