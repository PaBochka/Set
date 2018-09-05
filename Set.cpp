#include "TSet.h" 
#include <iostream>
#include <locale.h>
#include <conio.h>
// инициализация, потоковый ввод/вывод, добавление и удаление элементов, пересечение, объединение, дополнение, сравнение, присваивание
int main(void)
{
	int n;
	cout << "Enter size of set A" << endl;
	cin >> n;
	TSet A(n), B(5), C(4), D(5);
	cout << "We creat 4 sets: A= " << A << ", B= " << B << ", C=" << C << ", D=" << D << "." << endl;
	cout << "Let's include in the set B 3 elements." << endl;
	B.InsElem(1);
	B.InsElem(2);
	B.InsElem(3);
	B.DelElem(5);
	cout << "B= " << B << endl;
	cout << "Enter the set A" << endl;
	cin >> A;
	cout << "A= " << A << endl;
	cout << "Now we intersect the sets A and B" << endl;
	D = A * B;
	cout << "D= " << D << endl;
	cout << "Then we unite set A and set B" << endl;
	D = B + A;
	cout << "D= " << D << endl;
	cout << "Let's do negative this set" << endl;
	D = ~D;
	cout << "D= " << D << endl;
	cout << "Finally we'll assign the set A to D and compare the set A and set D:" << endl;
	A = D;
	cout << A << endl;
	cout << D << endl;
	if (A == D)
		cout << "This sets are equal!" << endl;
	else
		cout << "This sets aren't equal!" << endl;
	cout << "To verify the comparison of unequal sets, we compare the set A and the empty set C:" << endl;
	if (A == C)
		cout << "This sets are equal!" << endl;
	else
		cout << "This sets aren't equal!" << endl;
	_getch(); return 0;
}

