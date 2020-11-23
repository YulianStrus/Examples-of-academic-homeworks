#include "iostream"
using namespace std;
void main()
{
	float a; //Оголошення змінної
	cout << "Enter the distance in kilometers "; 
	cin >> a; //Зчитування значення змінної з консолі
	a *= 1066.8; //Підрахунок результату
	cout << "Distance in verst = " << a << endl; //Виведення результату на консоль
	system("pause");
}
