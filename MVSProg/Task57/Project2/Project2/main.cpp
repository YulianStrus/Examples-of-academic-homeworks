#include <iostream>
using namespace std;

template <typename T>
class Stack
{
	int size;
	int top;
	T* date;
public:
	Stack() { size = 5; top = -1; date = new T[size]; }
	Stack(int size) { this->size = size; top = -1; date = new T[size]; }

	void Push(T x)
	{
		if (top != size - 1)
		{
			top++;
			date[top] = x;
		}
		else
		{
			T* tmp = new T[size];
			for (int i = 0; i < size; i++)
			{
				tmp[i] = date[i];
			}
			size++;
			date = new T[size];
			for (int i = 0; i < size; i++)
			{
				date[i] = tmp[i];
			}
			top++;
			date[top] = x;
		}
	}

	void Counter()
	{
		int n = 0;
		for (int i = 0; i <= top; i++)
			n++;
		cout << n << endl;
	}

	void POP()
	{
		if (top == -1) cout << "Stack is empty!\n";
		else
		{
			cout << date[top] << " ";
			top--;
		}
	}

	T Pop()
	{
		if (top == -1) cout << "Stack is empty!\n";
		else
		{
			top--;
			return date[top + 1];
		}
	}

	bool isFull()
	{
		if (top == size - 1) return true;
		else return false;
	}

	bool isEmpty()
	{
		if (top == -1) return true;
		else return false;
	}

	void Show()
	{
		cout << "Stack: ";
		for (int i = 0; i <= top; i++)
			cout << date[i] << " ";
		cout << "\n";
	}

	void Clear()
	{
		while (top != -1)
		{
			top--;
		}
	}
};

int main()
{
	Stack<char> a(5);
	a.Push('A');
	a.Push('B');
	a.Push('C');
	a.Push('D');
	a.Push('E');
	a.Push('F');
	a.Show();
	cout << "Pushing a character from the stack: "; a.POP();
	int x = a.Pop();
	cout << "\nNumber of characters = "; a.Counter();
	a.Show();
	a.Clear();
	a.Show();
	system("pause");
	return 0;
}