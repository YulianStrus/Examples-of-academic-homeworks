#include "iostream"
using namespace std;
void main()
{
	double a, b, c, V; //Оголошення змінних
	cout << "Enter length ";
	cin >> a;
	cout << "Enter width ";
	cin >> b;
	cout << "Enter height ";
	cin >> c; //Зчитування значення змінних з консолі
	V = a * b * c; //Підрахунок об'єму паралелепіпеда
	cout << "Volume of parallelepiped = " << V << endl; //Виведення результату на консоль
	system("pause");
}
