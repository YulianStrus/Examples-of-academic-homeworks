#include "iostream"
using namespace std;
void main()
{
	double a, b, x, k; //Оголошення змінних
	cout << "Price of the notebook (UAH) ";
	cin >> a;
	cout << "Cover price (UAH) ";
	cin >> b;
	cout << "Number of sets (pcs.) ";
	cin >> x; //Зчитування значення змінних з консолі
	k = (a * x) + (b * x); //Підрахунок суми покупки
	cout << "Purchase price: = " << k << endl; //Виведення результату на консоль
	system("pause");
}
