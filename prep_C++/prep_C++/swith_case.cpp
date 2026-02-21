////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////#include <stdlib.h>
////#include <iostream>
////
////using namespace std;
////
////
////int main() {
////	system("chcp 1251");
////	int x = 0;
////	cout << "введите число от одного до пяти" << endl;
////	cin >> x;
////
////	switch (x)
////	{
////	case 1:
////		cout << "Вы ввели число один" << endl;
////		break;
////
////	case 2:
////		cout << "Вы ввели число два" << endl;
////		break;
////
////	case 3:
////		cout << "Вы ввели число три" << endl;
////		break;
////
////	case 4:
////		cout << "Вы ввели число четыре" << endl;
////		break;
////
////	case 5:
////		cout << "Вы ввели число пять" << endl;
////		break;
////	default:
////		cout << "ты пиздец тупой";
////		break;
////	}
////
////	return 0;
////}
////
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//
//
//using namespace std;
//
//int main() {
//	system("chcp 1251");
//	int a = 0;
//	int b = 0;
//	char op;
//
//	cout << "введите число" << endl;
//	cin >> a;
//
//	cout << "введите второе число" << endl;
//	cin >> b;
//
//	cout << "введите операцию (+, -)" << endl;
//	cin >> op;
//
//	switch (op) {
//
//	case '+':
//		cout << "результат:" << a + b << endl;
//		break;
//
//	case '-':
//		cout << "результат:" << a - b << endl;
//		break;
//
//	default:
//		cout << "ты даже не смог опперацию ввести, бездарь!" << endl;
//		break;
//
//		return 0;
//	}
//}


#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

/*
* изменить размер массива
* добавить элемент в массив
* удалить элемент массива
*/

void FillArray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void ShowArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void push_back(int*& arr, int& size, const int value)
{
	int* newArray = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	newArray[size] = value;

	size++;

	delete[] arr;

	arr = newArray;

}

void pop_back(int*& arr, int& size)
{
	size--;
	int* newArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	delete[] arr;

	arr = newArray;

}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size = 5;

	int* arr = new int[size];

	char tmp1[] = {9, 1};
	char tmap2[] = {12, 3};
	int fin = memcmp(tmp1, tmap2, 2);
	int fin2 = memcmp(tmp1, tmap2, 2);

	const char* p = strchr("foobar", 'b');
	if (p)
		printf("b найден в позиции %ld\n", p - "foobar");
	// выведет "b найден в позиции 3" (нумерация с нуля)


	FillArray(arr, size);

	ShowArray(arr, size);

	push_back(arr, size, 111);

	ShowArray(arr, size);

	pop_back(arr, size);

	ShowArray(arr, size);



	delete[] arr;

	return 0;
}