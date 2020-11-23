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
	a /= 1000; //Переведення метри в кілометри
	int m = b; //Виділення кількості хвилин
	s = m * 60; //Переведення хвилин в секунди
	h = (b - m) * 100; //Виділення кількості секунд
	t = h + s; //Підрахунок часу в секундах
	S = a / (t/3600); //Підрахунок швидкості бігуна
	S = round(S * 100) / 100; //Скорочення до сотих
	cout << "You ran at a speed of " << S << "km/h" << endl; //Виведення результату на консоль
	system("pause");
}
