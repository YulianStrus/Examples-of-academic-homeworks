#include "Header.h"
void LuckyNum(int a)
{
	int b, c, d, x, y, z, S1, S2;
	b = a % 1000;
	c = b % 100;
	d = c % 10;
	c = c / 10;
	b = b / 100;
	S1 = b + c + d;

	x = a /1000;
	y = x % 100;
	z = y % 10;
	y = y / 10;
	x = x / 100;
	S2 = x + y + z;

	if (S1 == S2) cout << "Yes! This is a lucky number";
	else cout << "No! This number is unlucky";
}