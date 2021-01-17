#include <iostream>
#include <conio.h>
using namespace std;

class Vector
{
private:
	int x;
	int y;
	friend Vector operator+ (Vector &, int a);
	friend Vector operator+ (Vector &, Vector &d2);
	friend Vector operator+= (Vector &, int a);
	friend Vector operator+= (Vector &, Vector &d2);
public:
	Vector() : x(0), y(0)
	{}
	Vector(int vx, int vy) : x(vx), y(vy)
	{}
	void showVector()
	{
		cout << x << ":" << y << "";
	}
	//++++++++++++++++++++++++++++++

	
	

	//------------------------------
	Vector operator-(int a) 
	{
		int vx = x - a;
		int vy = y - a;
		return Vector(vx, vy);
	};
	Vector operator-= (int a) 
	{
		int vx = x - a;
		int vy = y - a;
		return Vector(vx, vy);
	};
	Vector operator-= (Vector d2)
	{
		int vx = x - d2.x;
		int vy = y - d2.y;
		return Vector(vx, vy);
	};
	//*******************************
	Vector operator*(int a) 
	{
		int vx = x * a;
		int vy = y * a;
		return Vector(vx, vy);
	};
	Vector operator*(Vector d2)
	{
		int vx = x * d2.x;
		int vy = y * d2.y;
		return Vector(vx, vy);
	};
	Vector operator*= (int a) 
	{
		int vx = x * a;
		int vy = y * a;
		return Vector(vx, vy);
	};
	Vector operator*= (Vector d2) 
	{
		int vx = x * d2.x;
		int vy = y * d2.y;
		return Vector(vx, vy);
	};
	/////////////////////////////////
	Vector operator/(int a) 
	{
		int vx = x / a;
		int vy = y / a;
		return Vector(vx, vy);
	};
	Vector operator/= (int a) 
	{
		int	vx = x, vy = y;
		vx /= a;
		vy /= a;
		return Vector(vx, vy);
	};
};

Vector operator+ (Vector &obj, int a)
{
	int vx = obj.x + a;
	int vy = obj.y + a;
	return Vector(vx, vy);
};
Vector operator+(Vector &obj, Vector &d2)
{
	int vx = obj.x + d2.x;
	int vy = obj.y + d2.y;
	return Vector(vx, vy);
};
Vector operator+= (Vector &obj, int a)
{
	int vx = obj.x + a;
	int vy = obj.y + a;
	return Vector(vx, vy);
};
Vector operator+= (Vector &obj, Vector &d2)
{
	int vx = obj.x + d2.x;
	int vy = obj.y + d2.y;
	return Vector(vx, vy);
};

int main()
{
	int x, y, z, i, j, k, a = 1;
	Vector A1, A2, A3;
	cout << "Enter the coordinates of the vector a(x:y) : " << endl;
	cin >> x >> y;
	cout << "Enter the coordinates of the vector b(x:y) : " << endl;
	cin >> i >> j;
	A1 = Vector(x, y);
	A2 = Vector(i, j);

	A3 = A1 + a;
	cout << "A1("; A1.showVector(); cout << ")\t + \t" << a; cout << "\t = "; A3.showVector(); cout << endl;
	A3 = A1 - a;
	cout << "A1("; A1.showVector(); cout << ")\t - \t" << a; cout << "\t = "; A3.showVector(); cout << endl;
	A3 = A1 * a;
	cout << "A1("; A1.showVector(); cout << ")\t * \t" << a; cout << "\t = "; A3.showVector(); cout << endl;
	A3 = A1 / a;
	cout << "A1("; A1.showVector(); cout << ")\t / \t" << a; cout << "\t = "; A3.showVector(); cout << endl;
	A3 = A1 += a;
	cout << "A1("; A1.showVector(); cout << ")\t += \t" << a; cout << "\t = ";  A3.showVector(); cout << endl;
	A3 = A1 -= a;
	cout << "A1("; A1.showVector(); cout << ")\t -= \t" << a; cout << "\t = ";  A3.showVector(); cout << endl;
	A3 = A1 *= a;
	cout << "A1("; A1.showVector(); cout << ")\t *= \t" << a; cout << "\t = ";  A3.showVector(); cout << endl;
	A3 = A1 /= a;
	cout << "A1("; A1.showVector(); cout << ")\t /= \t" << a; cout << "\t = ";  A3.showVector(); cout << endl;
	A3 = A1 + A2;
	cout << "A1("; A1.showVector(); cout << ")\t + \tA2("; A2.showVector(); cout << ")\t = "; A3.showVector(); cout << endl;
	A3 = A1 * A2;
	cout << "A1("; A1.showVector(); cout << ")\t * \tA2("; A2.showVector(); cout << ")\t = "; A3.showVector(); cout << endl;
	A3 = A1 += A2;
	cout << "A1("; A1.showVector(); cout << ")\t += \tA2("; A2.showVector(); cout << ")\t = "; A3.showVector(); cout << endl;
	A3 = A1 -= A2;
	cout << "A1("; A1.showVector(); cout << ")\t -= \tA2("; A2.showVector(); cout << ")\t = "; A3.showVector(); cout << endl;
	A3 = A1 *= A2;
	cout << "A1("; A1.showVector(); cout << ")\t *= \tA2("; A2.showVector(); cout << ")\t = "; A3.showVector(); cout << endl;
	cin.get();
	cin.get();
	return 0;
}