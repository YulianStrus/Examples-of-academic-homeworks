#include "iostream"
using namespace std;

int Size();

class ErrorSize
{
	int size;

public:
	ErrorSize() {
		cout << "\nThe size of array cannot be zero" << endl
			<< endl;
	}
	ErrorSize(int size)
	{
		this->size = size;
		cout << "\nThe size of array cannot be zero" << endl
			<< endl;
	}
};

class Stack
{
	int size;
	int top;
	char *data;

public:
	Stack()
	{
		size = 5;
		top = -1;
		data = new char[size];
	}
	~Stack() { delete[] data; }
	Stack(int size)
	{
		try
		{
			if (size <= 0)
				throw ErrorSize(size);
			else
			{
				this->size = size;
				top = -1;
				data = new char[size];
			}
		}
		catch (ErrorSize &obj)
		{
			SetSize(Size());
		}
	}
	void SetSize(int size)
	{
		this->size = size;
		try
		{
			if (size <= 0)
				throw ErrorSize(size);
			else
			{
				this->size = size;
				top = -1;
				data = new char[size];
			}
		}
		catch (ErrorSize &obj)
		{
			SetSize(Size());
		}
	}
	bool IsFull()
	{
		if (top == size - 1)
			return true;
		else
			return false;
	}
	bool IsEmpty()
	{
		try
		{
			if (top == -1)
				throw "Stack is empty";
			else
				return false;
		}
		catch (const char *s)
		{
			cout << s << endl
				<< endl;
		}
	}
	void IfFull()
	{
		char *temp = new char[size];
		for (int i = 0; i < size; ++i)
			temp[i] = data[i];
		delete[] data;
		size++;
		data = new char[size];
		for (int i = 0; i < size - 1; ++i)
			data[i] = temp[i];
		delete[] temp;
	}
	void Push(char s)
	{
		if (IsFull() == false)
		{
			++top;
			data[top] = s;
		}
		else
		{
			IfFull();
			++top;
			data[top] = s;
		}
	}
	void PopShow()
	{
		if (!IsEmpty())
		{
			cout << data[top];
			--top;
		}
	}
	void Count()
	{
		cout << "Count symbols on the stack = " << top + 1 << endl
			<< endl;
	}
	void Show()
	{
		IsEmpty();
		for (int i = 0; i <= top; ++i)
			cout << data[i] << " ";
		cout << endl;
	}
	void Clear()
	{
		int temp = top;
		for (int i = 0; i <= temp; i++)
			--top;
	}
};

int Size()
{
	int size;
	cout << "Enter a new size: ";
	cin >> size;
	return size;
}

char Push()
{
	char s;
	cout << "Enter symbol: ";
	cin >> s;
	return s;
}

int main()
{
	Stack st(0);
	int m = 1;
	while (m != 0)
	{
		cout << "1. Push symbol\n2. Pop symbol\n3. Counting symbol\n4. Stack is empty?\n5. Stack is full?\n6. Clear\n7. Show\n0. Exit\n"
			<< endl;
		cin >> m;
		if (m == 1)
			st.Push(Push());
		else if (m == 2)
			st.PopShow();
		else if (m == 3)
			st.Count();
		else if (m == 4)
			st.IsEmpty();
		else if (m == 5)
		{
			if (st.IsFull())
				cout << "Stack is FULL" << endl
				<< endl;
			else
				cout << "Stack is NOT full" << endl
				<< endl;
		}
		else if (m == 6)
			st.Clear();
		else if (m == 7)
			st.Show();
		else if (m == 0)
			break;
		else
			cout << "Incorrect select. Try again" << endl
			<< endl;
	}
	system("pause");
	return 0;
}