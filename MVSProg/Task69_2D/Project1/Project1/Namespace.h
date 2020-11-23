#pragma once;
#include "iostream"
using namespace std;

namespace fraction
{
	class Fraction
	{
	private:
		int Num;
		int Denom;
	public:
		Fraction(int a, int b) { Num = a; Denom = b; }
		void SetNum(int a) { Num = a; }
		void SetDem(int b) { Denom = b; }
		int GetNum() { return Num; }
		int GetDem() { return Denom; }
		int SumNum(int a1, int b1, int a2, int b2)
		{
			int Num, Denom;
			Num = a1 * b2 + a2 * b1;
			if (Num < 0) Num = -Num;
			Denom = b1 * b2;
			if (Denom < 0) Denom = -Denom;
			for (int i = 2; i <= Num; ++i)
			{
				if (Num % i == 0)
				{
					if (Denom % i == 0)
					{
						Num /= i;
						Denom /= i;
						i = 1;
					}
				}
			}
			if ((a1 * b2 + a2 * b1) < 0) return -Num;
			else return Num;
		}
		int SumDem(int a1, int b1, int a2, int b2)
		{
			int Num, Denom;
			Num = a1 * b2 + a2 * b1;
			if (Num < 0) Num = -Num;
			Denom = b1 * b2;
			if (Denom < 0) Denom = -Denom;
			for (int i = 2; i <= Num; ++i)
			{
				if (Num % i == 0)
				{
					if (Denom % i == 0)
					{
						Num /= i;
						Denom /= i;
						i = 1;
					}
				}
			}
			if (b1 * b2 < 0) return -Denom;
			else return Denom;
		}
		int SubNum(int a1, int b1, int a2, int b2)
		{
			int Num, Denom;
			Num = a1 * b2 - a2 * b1;
			if (Num < 0) Num = -Num;
			Denom = b1 * b2;
			if (Denom < 0) Denom = -Denom;
			for (int i = 2; i <= Num; ++i)
			{
				if (Num % i == 0)
				{
					if (Denom % i == 0)
					{
						Num /= i;
						Denom /= i;
						i = 1;
					}
				}
			}
			if ((a1 * b2 - a2 * b1) < 0) return -Num;
			else return Num;
		}
		int SubDem(int a1, int b1, int a2, int b2)
		{
			int Num, Denom;
			Num = a1 * b2 - a2 * b1;
			if (Num < 0) Num = -Num;
			Denom = b1 * b2;
			if (Denom < 0) Denom = -Denom;
			for (int i = 2; i <= Num; ++i)
			{
				if (Num % i == 0)
				{
					if (Denom % i == 0)
					{
						Num /= i;
						Denom /= i;
						i = 1;
					}
				}
			}
			if (b1 * b2 < 0) return -Denom;
			return Denom;
		}
		int MultiNum(int a1, int b1, int a2, int b2)
		{
			int Num, Denom;
			Num = a1 * a2;
			if (Num < 0) Num = -Num;
			Denom = b1 * b2;
			if (Denom < 0) Denom = -Denom;
			for (int i = 2; i <= Num; ++i)
			{
				if (Num % i == 0)
				{
					if (Denom % i == 0)
					{
						Num /= i;
						Denom /= i;
						i = 1;
					}
				}
			}
			if ((a1 * a2) < 0) return -Num;
			return Num;
		}
		int MultiDem(int a1, int b1, int a2, int b2)
		{
			int Num, Denom;
			Num = a1 * a2;
			if (Num < 0) Num = -Num;
			Denom = b1 * b2;
			if (Denom < 0) Denom = -Denom;
			for (int i = 2; i <= Num; ++i)
			{
				if (Num % i == 0)
				{
					if (Denom % i == 0)
					{
						Num /= i;
						Denom /= i;
						i = 1;
					}
				}
			}
			if (b1 * b2 < 0) return -Denom;
			else return Denom;
		}
		int DivNum(int a1, int b1, int a2, int b2)
		{
			int Num, Denom;
			Num = a1 * b2;
			if (Num < 0) Num = -Num;
			Denom = b1 * a2;
			if (Denom < 0) Denom = -Denom;
			for (int i = 2; i <= Num; ++i)
			{
				if (Num % i == 0)
				{
					if (Denom % i == 0)
					{
						Num /= i;
						Denom /= i;
						i = 1;
					}
				}
			}
			if (a1*b2 < 0) return -Num;
			else return Num;
		}
		int DivDem(int a1, int b1, int a2, int b2)
		{
			int Num, Denom;
			Num = a1 * b2;
			if (Num < 0) Num = -Num;
			Denom = b1 * a2;
			if (Denom < 0) Denom = -Denom;
			for (int i = 2; i <= Num; ++i)
			{
				if (Num % i == 0)
				{
					if (Denom % i == 0)
					{
						Num /= i;
						Denom /= i;
						i = 1;
					}
				}
			}
			if (b1 * a2 < 0) return -Denom;
			else return Denom;
		}
	};

//----------------------------------------------
inline namespace vector2d
{
	class Vector2d
	{
	private:
		double a1;
		double a2;
	public:
		Vector2d()
		{
			a1 = 1;
			a2 = 1;
		}
		Vector2d(double a1, double a2)
		{
			this->a1 = a1;
			this->a2 = a2;
		}
		void SetA1(double a1) { this->a1 = a1; }
		void SetA2(double a2) { this->a2 = a2; }
		double GetA1() { return a1; }
		double GetA2() { return a2; }
		Vector2d operator+(int n) { return Vector2d(a1 + n, a2 + n); }
		Vector2d operator+(const Vector2d&other) { return Vector2d(this->a1 + other.a1, this->a2 + other.a2); }
		Vector2d operator-(int n) { return Vector2d(a1 - n, a2 - n); }
		Vector2d operator-() { return Vector2d(a1 = -a1, a2 = -a2); }
		Vector2d operator-(const Vector2d&other) { return Vector2d(this->a1 - other.a1, this->a2 - other.a2); }
		Vector2d operator*(int n) { return Vector2d(a1*n, a2*n); }
		double operator*(const Vector2d&other) { return (this->a1*other.a1) + (this->a2*other.a2); }
		Vector2d operator/(int n) { return Vector2d(a1 / n, a2 / n); }
		void operator+=(int n) { a1 += n; a2 += n; }
		void operator+=(const Vector2d&other) { this->a1 += other.a1; this->a2 += +other.a2; }
		void operator-=(int n) { a1 -= n; a2 -= n; }
		void operator-=(const Vector2d&other) { this->a1 -= other.a1; this->a2 -= other.a2; }
		void operator*=(int n) { a1 *= n; a2 *= n; }
		void operator*=(const Vector2d&other) { this->a1 *= other.a1; this->a2 *= other.a2; }
		void operator/=(int n) { a1 /= n; a2 /= n; }
		void Show() { cout << "(" << a1 << ", " << a2 << ")"; }
	};
//---------------------------------------------------------------
	inline namespace point
	{
		class Point
		{
		private:
			int x;
			int y;
			int z;
		public:
			Point() { x = 3, y = 4, z = 5; }
			Point(int a, int b, int c) { x = a, y = b, z = c; }
			void SetX(int a) { x = a; }
			void SetY(int b) { y = b; }
			void SetZ(int c) { z = c; }
			int GetX() { return x; }
			int GetY() { return y; }
			int GetZ() { return z; }
			void Show() { cout << "(" << x << ", " << y << ", " << z << ")"; }
		};
	}
}
}