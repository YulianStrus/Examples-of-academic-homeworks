#include "iostream"
#include <ctime>
using namespace std;

class Array
{
	int *Arr;
	int size;
public:
	Array() { size = 5, Arr = new int[size]; }
	Array(int s) { size = s, Arr = new int[size]; }
	Array(const Array & other) 
	{ 
		this->size = other.size, this->Arr = new int[size];
			for (int i=0; i<size; i++)
			{
				this->Arr[i] = other.Arr[i];
			}
	}
	~Array() { delete[]Arr; }
	void Init()
	{
		for (int i = 0; i < size; i++)
		{
			int a;
			cout << "Enter " << i + 1 << " number: ";
			cin >> a;
			Arr[i] = a;
		}
		cout << endl;
	}
	void Max()
	{
		int max = Arr[0];
		for (int i = 1; i < size; i++)
			if (Arr[i] > max) max = Arr[i];
		cout << "max: " << max << endl;
	}
	void Min()
	{
		int min = Arr[0];
		for (int i = 1; i < size; i++)
			if (Arr[i] < min) min = Arr[i];
		cout << "max: " << min << endl;
	}
	void Sort()
	{
		int tmp;
		bool chg = true;
		while (chg)
		{
			chg = false;
			for (int i = 0; i < size - 1; i++)
				if (Arr[i + 1] < Arr[i])
				{
					tmp = Arr[i];
					Arr[i] = Arr[i + 1];
					Arr[i + 1] = tmp;
					chg = true;
				}
		}
	}
	void Show()
	{
		for (int i = 0; i < size; i++)
			cout << Arr[i] << " ";
		cout << endl;
	}
};

int main()
{
	srand(time(0));
	int size;
	cout << "Enter size: ";
	cin >> size;
	Array Arr(size);
	Arr.Init();
	Arr.Show();
	Arr.Max();
	Arr.Min();
	Arr.Sort();
	Arr.Show();
	system("pause");
	return 0;
}