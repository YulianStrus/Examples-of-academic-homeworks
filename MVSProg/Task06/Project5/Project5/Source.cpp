#include "iostream"
using namespace std;
void main()
{
	double a, b, L; //���������� ������
	cout << "Map scale ";
	cin >> a;
	cout << "Distance between settlements on the map (cm) ";
	cin >> b; //���������� �������� ������ � ������
	L = a * b; //ϳ�������� ������ �� ���������� ��������
	cout << "Distance between settlements (km) = " << L << endl; //��������� ���������� �� �������
	system("pause");
}
