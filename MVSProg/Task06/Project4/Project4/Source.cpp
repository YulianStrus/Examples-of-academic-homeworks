#include "iostream"
using namespace std;
void main()
{
	double a, b, x, k; //���������� ������
	cout << "Price of the notebook (UAH) ";
	cin >> a;
	cout << "Cover price (UAH) ";
	cin >> b;
	cout << "Number of sets (pcs.) ";
	cin >> x; //���������� �������� ������ � ������
	k = (a * x) + (b * x); //ϳ�������� ���� �������
	cout << "Purchase price: = " << k << endl; //��������� ���������� �� �������
	system("pause");
}
