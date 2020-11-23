#include "iostream"
using namespace std;
void main()
{
	double a, b, L; //Оголошення змінних
	cout << "Map scale ";
	cin >> a;
	cout << "Distance between settlements on the map (cm) ";
	cin >> b; //Зчитування значення змінних з консолі
	L = a * b; //Підрахунок відстані між населеними пунктами
	cout << "Distance between settlements (km) = " << L << endl; //Виведення результату на консоль
	system("pause");
}
