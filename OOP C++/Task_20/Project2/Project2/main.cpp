#include "iostream"
using namespace std;

class Figure
{
	int side;
public:
	Figure() { side = 5; }
	Figure(int side) { this->side = side; }
	void SetSide(int side) { this->side = side; }
	int GetSide() { return side; }
	virtual void Square() = 0;
};

class Rectangle : public Figure
{
	int b;
public:
	Rectangle() :Figure() { b = 5; }
	Rectangle(int a, int b) : Figure(a) { this->b = b; }
	void Square() { cout << "Rectangle square: " << GetSide()*b << endl << endl; }
};

class Circle :public Figure
{
public:
	Circle() :Figure() {}
	Circle(int r) :Figure(r) {}
	void Square() { cout << "Circle square: " << 3.14*GetSide()*GetSide() << endl << endl; }
};

class RightTriangle :public Figure
{
	int b;
public:
	RightTriangle() :Figure() { b = 5; }
	RightTriangle(int a, int b) :Figure(a) { this->b = b; }
	void Square() { cout << "Right triangle square: " << 0.5*GetSide()*b << endl << endl; }
};

class Trapeze : public Figure
{
	int b;
	int h;
public:
	Trapeze() :Figure() { b = 5; h = 7; }
	Trapeze(int a, int b, int h) :Figure(a) { this->b = b; this->h = h; }
	void Square() { cout << "Trapeze square: " << 0.5*(GetSide() + b)*h << endl << endl; }
};

int main()
{
	Figure *p;
	Rectangle rec(5, 6);
	Circle cir(5);
	RightTriangle rtr(5, 6);
	Trapeze tr(5, 6, 7);
	p = &rec;
	p->Square();
	p = &cir;
	p->Square();
	p = &rtr;
	p->Square();
	p = &tr;
	p->Square();
	system("pause");
	return 0;
}