#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void PrintHello3(int a) //� - �������� ����� ��� ���������� ��������
{
	for (int i=1; i<=a;++i)
	cout << "Hello!" << endl;
}
void main()
{
	//������ 1
	PrintHello3(5);
	cout << endl << endl;

	//������ 2
	int a = 7;
	PrintHello3(a); //� - ��������� ����� ��� ��������� ��������
	cout << endl << endl;

	//������ 3
	cin >> a;
	PrintHello3(a);

	system("pause");
}
