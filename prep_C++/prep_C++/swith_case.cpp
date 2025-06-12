//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//
//using namespace std;
//
//
//int main() {
//	system("chcp 1251");
//	int x = 0;
//	cout << "введите число от одного до пяти" << endl;
//	cin >> x;
//
//	switch (x)
//	{
//	case 1:
//		cout << "Вы ввели число один" << endl;
//		break;
//
//	case 2:
//		cout << "Вы ввели число два" << endl;
//		break;
//
//	case 3:
//		cout << "Вы ввели число три" << endl;
//		break;
//
//	case 4:
//		cout << "Вы ввели число четыре" << endl;
//		break;
//
//	case 5:
//		cout << "Вы ввели число пять" << endl;
//		break;
//	default:
//		cout << "ты пиздец тупой";
//		break;
//	}
//
//	return 0;
//}
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int main() {
	system("chcp 1251");
	int a = 0;
	int b = 0;
	char op;

	cout << "введите число" << endl;
	cin >> a;

	cout << "введите второе число" << endl;
	cin >> b;

	cout << "введите операцию (+, -)" << endl;
	cin >> op;

	switch (op) {

	case '+':
		cout << "результат:" << a + b << endl;
		break;

	case '-':
		cout << "результат:" << a - b << endl;
		break;

	default:
		cout << "ты даже не смог опперацию ввести, бездарь!" << endl;
		break;

		return 0;
	}
}
