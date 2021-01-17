#include <iostream>
#include <vector>
using namespace std;

class maxmin : private vector<int>
{
	char op;
public:
	maxmin(const vector<int>& ini) { for (auto x : ini) this->push_back(x); }
	int operator()(char op)
	{
		if (op == '>')
		{
			auto i = begin();
			int max = *i;
			while (i < end())
			{
				if (max < *i++) max = *i++;
				if (i == end()) break;
				i++;
			}
			return max;
		}
		else if (op == '<')
		{
			auto i = begin();
			int min = *i;
			while (i < end())
			{
				if (min > *i++) min = *i++;
				if (i == end()) break;
				i++;
			}
			return min;
		}
	}
};

void Show(vector<int> num)
{

	for (int i = 0; i < num.size(); ++i)
	{
		cout << num[i] << " ";
	}
	cout << endl;
}

class srt : private vector<int>
{
	char op;

public:
	srt(const vector<int> &ini)
	{
		for (auto x : ini)
			this->push_back(x);
	}
	void operator()(vector<int> num, char op)
	{
		if (op == '+')
		{
			int temp;
			for (int i = 0; i < num.size() - 1; ++i)
			{
				for (int k = 0; k < num.size() - i - 1; ++k)
				{
					if (num[k] > num[k + 1])
					{
						temp = num[k];
						num[k] = num[k + 1];
						num[k + 1] = temp;
					}
				}
			}
			Show(num);
		}
		else if (op == '-')
		{
			int temp;
			for (int i = 0; i < num.size() - 1; ++i)
			{
				for (int k = 0; k < num.size() - i - 1; ++k)
				{
					if (num[k] < num[k + 1])
					{
						temp = num[k];
						num[k] = num[k + 1];
						num[k + 1] = temp;
					}
				}
			}
			Show(num);
		}
	}
};

class addsubdel : private vector<int>
{
	char op;
public:
	addsubdel(const vector<int>& ini) { for (auto x : ini) this->push_back(x); }
	void operator()(vector<int> num, int op, int a)
	{
		if (op == '+')
		{
			for (int i = 0; i < num.size(); ++i)
			{
				num[i] = num[i] + a;
				i++;
			}
			Show(num);
		}
		else if (op == '-')
		{
			for (int i = 0; i < num.size(); ++i)
			{
				num[i] = num[i] - a;
				i++;
			}
			Show(num);
		}
		else if (op == '=')
		{
			for (int i = 0; i < num.size(); ++i)
			{
				if (num[i] == a)
					num.erase(num.begin() + i);
			}
			Show (num);
		}
	}
};

int main(void) {
	vector <int> arr = { 21, 2, 33, 4, -5, 61, 97, 8, 9, 10, 0, -9, 88, 7, 6, 5, 49, 3, 12, 1 };
	
	maxmin arr1(arr);
	srt arr2(arr);
	addsubdel arr3(arr);

	cout << "Max = " << arr1('>') << endl;
	cout << "Min = " << arr1('<') << endl << endl;

	cout << "Sort +: ";	arr2(arr, '+');
	cout << "Sort -: ";	arr2(arr, '-');

	cout << endl;
	cout << "Sort +5: "; arr3(arr, '+', 5);
	cout << "Sort -5: "; arr3(arr, '-', 5);
	cout << "\nDelete: "; arr3(arr, '=', 9);

	system("pause");
}