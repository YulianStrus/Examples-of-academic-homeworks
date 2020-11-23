#include "iostream"
using namespace std;
void main()
{
	float r, V, Pi = 3.14159265; //Оголошення змінної
	cout << "Enter the radius of the ball ";
	cin >> r; //Зчитування значення змінної з консолі
	V = (4.0/3.0)*Pi*(r*r*r); //Підрахунок результату
	cout << "The volume of the ball = " << V << endl; //Виведення результату на консоль
	system("pause");
}
