#include "iostream"
#include "math.h"
using namespace std;
void main()
{
	double a, b, s, h, t, S;
	cout << "Enter the length of the distance (m) ";
	cin >> a;
	cout << "Enter the time (minutes seconds) ";
	cin >> b;
	a /= 1000; //����������� ����� � ��������
	int m = b; //�������� ������� ������
	s = m * 60; //����������� ������ � �������
	h = (b - m) * 100; //�������� ������� ������
	t = h + s; //ϳ�������� ���� � ��������
	S = a / (t/3600); //ϳ�������� �������� �����
	S = round(S * 100) / 100; //���������� �� �����
	cout << "You ran at a speed of " << S << "km/h" << endl; //��������� ���������� �� �������
	system("pause");
}
