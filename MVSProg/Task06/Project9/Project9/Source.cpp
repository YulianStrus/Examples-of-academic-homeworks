#include "iostream"
using namespace std;
void main()
{
	double r, h, V; //���������� �����
	cout << "Enter the radius of the cone base ";
	cin >> r;
	cout << "Enter the height of the cone ";
	cin >> h; //���������� �������� ����� � ������
	V = r*r*h*(1.0/3.0)* 3.1415926; //ϳ�������� ����������
	cout << "The volume of the cone = " << V << endl; //��������� ���������� �� �������
	system("pause");
}
