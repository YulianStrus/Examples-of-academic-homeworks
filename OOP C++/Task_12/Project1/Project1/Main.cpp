#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <time.h>
using namespace std;

template <class T> class matrix 
{
	T **mas;
	int n, m;
public:
	T** get() { return mas; }
	matrix getn() { return n; }
	matrix getm() { return m; }
	
	void set(T** mas) { this->mas = mas; }
	matrix (int n, int m)
	{
		this->n = n;
		this->m = m;
		mas = new T*[n];
		for (int i = 0; i < n; i++) {
			mas[i] = new T[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mas[i][j] = 1 + rand() % 9;
			}
		}
	}
	matrix (const matrix & other)
	{
		this->n = other.n;
		this->m = other.m;
		mas = new T*[n];
		for (int i = 0; i < n; i++) {
			mas[i] = new T[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) 
			{
				mas[i][j] = other.mas[i][j];
			}
		}
	}
	
	~matrix()
	{
		for (int i = 0; i < n; i++) delete[] mas[i];
		delete[]mas;
	}

	void out()
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) 
			{
				cout << setw(5) << setprecision(2) << mas[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	matrix<T> operator+ (matrix<T> &b)
	{
		matrix<T> c(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				c.mas[i][j] = b.mas[i][j] + mas[i][j];
			}
		}
		return c;
	}
	matrix<T> operator- (matrix<T> &b)
	{
		matrix<T> c(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				c.mas[i][j] = b.mas[i][j] - mas[i][j];
			}
		}
		return c;
	}

	matrix<T> operator* (matrix <T> &b)
	{
		matrix<T> c(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				c.mas[i][j] = b.mas[i][j] * mas[i][j];
			}
		}
		return c;
	}

	matrix<T> operator/ (matrix <T> &b)
	{
		matrix<T> c(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				c.mas[i][j] = b.mas[i][j] / mas[i][j];
			}
		}
		return c;
	}
	
	T minSearch()
	{
		T min = mas[0][0];
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				if (mas[i][j] < min) min = mas[i][j];
			}
		}
		return min;
	}
	
	T maxSearch()
	{
		T max = mas[0][0];
		for (int i = 0; i < n; i++) 
		{
			for (int j = 1; j < m; j++)
			{
				if (mas[i][j] > max) max = mas[i][j];
			}
		}
		return max;
	}
};



int main()
{
	matrix <int> a(4,3);
	cout << "Matrix A:" << endl;
	a.out();
	matrix <int> b(4,3);
	cout << "Matrix B:" << endl;
	b.out();
	cout << "Summ  A and B:" << endl;
	(a + b).out();
	cout << "Difference  A and B:" << endl;
	(a - b).out();
	cout << "Multiplication  A and B:" << endl << endl;
	(a*b).out();
	cout << "Division  A and B:" << endl << endl;
	(a/b).out();
	int min = a.minSearch();
	cout << "Min = " << min << endl;
	int max = a.maxSearch();
	cout << "Max = " << max << endl;

	system("pause");
	return 0;
}