#include <iostream>
#include <vector>
using namespace std;

void Show(vector<int> c)
{
	int length = 0;
	for (int i = c.size() - 1; i >= 0; --i)
	{
		if (c[i] == 0 && length == 0)
			continue;
		else length++;
		if (length > 0)	cout << c[i];
	}
	cout << endl;
}

void Sum (vector<int> &a, vector<int> &b)
{
		int size;
		if (a.size() > b.size()) size = a.size();
		else size = b.size();
		vector<int>c(size + 1);
		if (b.size() > a.size())
		{
			for (int i = 0; i < a.size(); ++i)
			{
				c[i] = c[i] + (a[i] + b[i]);
				c[i + 1] += (c[i] / 10);
				c[i] %= 10;
			}
			for (int i = a.size(); i < b.size(); ++i)
				c[i] += b[i];
			Show(c);
		}
		else
		{
			for (int i = 0; i < b.size(); ++i)
			{
				c[i] = c[i] + (a[i] + b[i]);
				c[i + 1] += (c[i] / 10);
				c[i] %= 10;
			}
			Show(c);
		}
}

void Dif (vector<int> &a, vector<int> &b)
	{
	int length=0, size;
	if (a.size() > b.size()) size = a.size();
	else size = b.size();
	vector<int>c(size);
	if (b.size() > a.size())
	{
		for (int i = 0; i < a.size(); ++i)
		{
			if (b[i] > a[i])
			{
				a[i] += 10;
				a[i + 1] -= 1;
			}
			c[i] = c[i] + (a[i] - b[i]);
		}
		for (int i = a.size(); i < b.size(); ++i)
			c[i] += b[i];
		cout << "-";
		Show(c);
	}
	else
	{
		for (int i = 0; i < b.size(); ++i)
		{
			if (b[i] > a[i])
			{
				a[i] += 10;
				a[i + 1] -= 1;
			}
			c[i] = c[i] + (a[i] - b[i]);
		}
		for (int i = b.size(); i < a.size(); ++i)
			c[i] += a[i];
		Show(c);
	}
}


void Mult(vector<int> &a, vector<int> &b) 
{
		int length=0;
		int size = a.size() + b.size() + 1;
		vector<int>c(size);
		for (int i = 0; i < a.size(); i++)
			for (int k = 0; k < b.size(); k++)
				c[i + k] += a[i] * b[k];
		for (int i = 0; i < c.size() - 1; i++)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
		Show(c);
}


int main(void) 
{
	vector <int> arr1 = { 4,5,6,0,1,3,8,3,4,4,5,6,9,3,1,1,1,9,0,3,4,5,6,7,7,5,6,8,2,3,1,2,9,2,3,6,7,4,3,1,2,0,4,5,7 };
	vector <int> arr2 = { 2,3,4,4,5,7,7,4,3,0,1,3,8,3,4,4,5,6,9,3,1,1,1,9,4,5,8,1,0,5,4,5,6,1,8,5,1,3,9 };

	cout << "Number 1: ";
	Show(arr1);
	cout << "Number 2: ";
	Show(arr2);

	cout << "\nSum:   \t\t";
	Sum(arr1, arr2);
	cout << "\nDifferent:   \t";
	Dif(arr1, arr2);
	cout << "\nMultiplication:   ";
	Mult(arr1, arr2);
	cout << endl << endl;

	system("pause");
}