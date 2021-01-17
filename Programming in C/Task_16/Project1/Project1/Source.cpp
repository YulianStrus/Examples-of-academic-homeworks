#include "Header.h"
int Kyb (int a)
{
	return a * a * a;
}
double Kyb(double a)
{
	return a * a * a;
}

int Sum(int a, int b)
{
	return a + b;
}
double Sum(double a, double b)
{
	return a + b;
}
int Sum(int a, int b, int c)
{
	return a + b + c;
}
double Sum(double a, double b, double c)
{
	return a + b + c;
}

int Prod(int a, int b)
{
	return a * b;
}
double Prod(double a, double b)
{
	return a * b;
}
int Prod(int a, int b, int c)
{
	return a * b * c;
}
double Prod(double a, double b, double c)
{
	return a * b * c;
}

int Min(int a, int b)
{
	if (a < b) return a;
	else return b;
}
double Min(double a, double b)
{
	if (a < b) return a;
	else return b;
}
int Min(int a, int b, int c)
{
	if ((a < b)&(a < c)) return a;
	if ((b < a)&(b < c)) return b;
	if ((c < a)&(c < b)) return c;
}
double Min(double a, double b, double c)
{
	if ((a < b)&(a < c)) return a;
	if ((b < a)&(b < c)) return b;
	if ((c < a)&(c < b)) return c;
}

int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
double Max(double a, double b)
{
	if (a > b) return a;
	else return b;
}
int Max(int a, int b, int c)
{
	if ((a > b)&(a > c)) return a;
	if ((b > a)&(b > c)) return b;
	if ((c > a)&(c > b)) return c;
}
double Max(double a, double b, double c)
{
	if ((a > b)&(a > c)) return a;
	if ((b > a)&(b > c)) return b;
	if ((c > a)&(c > b)) return c;
}