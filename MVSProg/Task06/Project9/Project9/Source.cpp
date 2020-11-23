#include "iostream"
using namespace std;
void main()
{
	double r, h, V; //Оголошення змінної
	cout << "Enter the radius of the cone base ";
	cin >> r;
	cout << "Enter the height of the cone ";
	cin >> h; //Зчитування значення змінної з консолі
	V = r*r*h*(1.0/3.0)* 3.1415926; //Підрахунок результату
	cout << "The volume of the cone = " << V << endl; //Виведення результату на консоль
	system("pause");
}
