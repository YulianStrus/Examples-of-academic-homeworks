#include "iostream"
using namespace std;
void main()
{
	float r, V, Pi = 3.14159265; //���������� �����
	cout << "Enter the radius of the ball ";
	cin >> r; //���������� �������� ����� � ������
	V = (4.0/3.0)*Pi*(r*r*r); //ϳ�������� ����������
	cout << "The volume of the ball = " << V << endl; //��������� ���������� �� �������
	system("pause");
}
