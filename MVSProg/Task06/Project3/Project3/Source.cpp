#include "iostream"
using namespace std;
void main()
{
	double a, b, c, V; //���������� ������
	cout << "Enter length ";
	cin >> a;
	cout << "Enter width ";
	cin >> b;
	cout << "Enter height ";
	cin >> c; //���������� �������� ������ � ������
	V = a * b * c; //ϳ�������� ��'��� �������������
	cout << "Volume of parallelepiped = " << V << endl; //��������� ���������� �� �������
	system("pause");
}
