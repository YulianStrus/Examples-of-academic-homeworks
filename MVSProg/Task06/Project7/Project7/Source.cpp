#include "iostream"
using namespace std;
void main()
{
	double a, c;
	cout << "Enter number ";
	cin >> a; //���������� �������� ������ � ������
	int b = a; //�������� ���� ������� - ���
	c = (a - b) * 100; //�������� ������� ������� - ������
	cout << a << " UAH. - this is "<< b <<" UAH " << c <<" kopecks" << endl; //��������� ���������� �� �������
	system("pause");
}
