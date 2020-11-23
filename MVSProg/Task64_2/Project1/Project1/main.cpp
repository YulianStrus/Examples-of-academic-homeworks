#include <iostream>
using namespace std;

class Circle
{
protected:
	int radius;
public:
	Circle() { radius = 5; }
	Circle(int radius) { this->radius = radius; }
	void SetCircle(int radius) { this->radius = radius; }
	int GetCircle() { return radius; }
};

class Square
{
protected:
	int side;
public:
	Square() { side = 10; }
	Square(int side) { this->side = side; }
	void SetSquare(int side) { this->side = side; }
	int GetSquare() { return side; }
};

class CirInSquare : public Circle, public Square
{
public:
	CirInSquare(){}
	void Show() 
	{ 
		if (GetCircle()*2==GetSquare()) 
			cout << "This circle is inscribed in a square" << endl; 
		else 
			cout << "This is not a circle inscribed in a square!" << endl;
	}
};

int main()
{
	double Pi = 3.14;
	CirInSquare Figure;
	Figure.Show();
	int SqSq=Figure.GetSquare()*Figure.GetSquare();
	cout << "Square square = " << SqSq << endl;
	double SqCr = Pi*(Figure.GetCircle()*Figure.GetCircle());
	cout << "Square circle = " << SqCr << endl;
	system("pause");
	return 0;
}