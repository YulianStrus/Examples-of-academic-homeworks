#include "iostream"
using namespace std;
void main()
{
	float a; //���������� �����
	cout << "Enter the distance in kilometers "; 
	cin >> a; //���������� �������� ����� � ������
	a *= 1066.8; //ϳ�������� ����������
	cout << "Distance in verst = " << a << endl; //��������� ���������� �� �������
	system("pause");
}
