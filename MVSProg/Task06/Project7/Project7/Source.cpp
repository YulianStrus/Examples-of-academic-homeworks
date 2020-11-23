#include "iostream"
using namespace std;
void main()
{
	double a, c;
	cout << "Enter number ";
	cin >> a; //Зчитування значення змінних з консолі
	int b = a; //Виділення цілої частини - грн
	c = (a - b) * 100; //Виділення дробової частини - копійок
	cout << a << " UAH. - this is "<< b <<" UAH " << c <<" kopecks" << endl; //Виведення результату на консоль
	system("pause");
}
