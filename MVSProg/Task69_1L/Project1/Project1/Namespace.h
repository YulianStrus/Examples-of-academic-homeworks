#pragma once;
#define QUEUE_H
#include <cassert>
#include "iostream"
using namespace std;

//-----------------------------------------------------------------
namespace list
{
	struct Node
	{
		int x;
		Node *Next, *Prev;
	};
	class List
	{
		Node *Head, *Tail;

	public:
		List() : Head(NULL), Tail(NULL) {};
		~List();
		void Show();
		void AddEnd(int x);
		void AddCentr(int x, int y);
		void DeleteElem(int m);
		void Count();
		void Summ();
		void Find(int x);
	};
	List::~List()
	{
		while (Head)
		{
			Tail = Head->Next;
			delete Head;
			Head = Tail;
		}
	}
	void List::AddEnd(int x)
	{
		Node *temp = new Node;
		temp->Next = NULL;
		temp->x = x;
		if (Head != NULL)
		{
			temp->Prev = Tail;
			Tail->Next = temp;
			Tail = temp;
		}
		else
		{
			temp->Prev = NULL;
			Head = Tail = temp;
		}
	}

	void List::AddCentr(int l, int y)
	{
		Node *temp = Head;
		int k = 1;
		while (temp->x != l)
		{
			k++;
			temp = temp->Next;
		}

		temp = new Node;
		temp->Next = NULL;
		temp->x = y;

		if (k == 1)
		{
			temp->Next = Head;
			Head = temp;
		}
		else
		{
			Node *tH;
			tH = Head;
			for (int i = 1; i < k - 1; ++i)
				tH = tH->Next;
			temp->Next = tH->Next;
			tH->Next = temp;
		}
	}

	void List::DeleteElem(int m)
	{
		Node *temp = Head;
		int k = 1;
		while (temp->x != m)
		{
			k++;
			temp = temp->Next;
		}

		{
			if (k == 1)
			{
				temp = Head;
				Head = Head->Next;
				temp = NULL;
			}
			else
			{
				Node *tH;
				tH = Head;
				for (int i = 1; i < k - 1; ++i)
					tH = tH->Next;
				temp = tH;
				temp = temp->Next;
				tH->Next = temp->Next;
				temp = NULL;
			}
		}
	}

	void List::Count()
	{
		Node *temp = Head;
		int k = 0;
		while (temp != NULL)
		{
			k++;
			temp = temp->Next;
		}
		cout << "Count element = " << k << endl;
	}

	void List::Summ()
	{
		Node *temp = Head;
		int k = 0;
		while (temp != NULL)
		{
			k += temp->x;
			temp = temp->Next;
		}
		cout << "Summ = " << k << endl;
	}

	void List::Find(int n)
	{
		Node *temp = Head;
		int k = 0;
		while (temp != NULL)
		{
			if (temp->x == n)
			{
				k++;
				temp = temp->Next;
			}
			else
				temp = temp->Next;
		}

		if (k > 0)
			cout << "Find " << k << " element" << endl;
		else
			cout << "Element not found! " << endl;
	}

	void List::Show()
	{
		Node *temp = Head;
		while (temp != NULL)
		{
			cout << temp->x << " ";
			temp = temp->Next;
		}
		cout << "\n";
	}
}

//-----------------------------------------------------------------
namespace stack
{
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
			else cout << "Stack is full!\n";
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
}

//-----------------------------------------------------------------
namespace queue
{
	template<typename T>
	class Queue
	{
	private:
		T *data;
		const int size;
		int head;
		int	tail;
		int count;
	public:
		Queue(int = 10);
		~Queue();
		bool isFull();
		bool isEmpty();
		void Enqueue(const T &);
		T Dequeue();
		void Show();
	};
	template<typename T>
	Queue<T>::Queue(int obj) :
		size(obj),
		head(0), tail(0), count(0)
	{
		data = new T[size + 1];
	}
	template<typename T>
	Queue<T>::~Queue()
	{
		delete[] data;
	}
	template<typename T>
	bool Queue<T>::isFull()
	{
		if ((head == 0) && (tail == size - 1)) return true;
		else return false;
	}
	template<typename T>
	bool Queue<T>::isEmpty()
	{
		if ((head == 0) && (tail == 0)) return true;
		else return false;
	}
	template<typename T>
	void Queue<T>::Enqueue(const T &newobj)
	{
		assert(count < size);
		data[tail++] = newobj;
		count++;
		if (tail > size)
			tail -= size + 1;
	}
	template<typename T>
	T Queue<T>::Dequeue()
	{
		assert(count > 0);
		T Value = data[head++];
		count--;
		if (head > size)
			head -= size + 1;
		return Value;
	}
	template<typename T>
	void Queue<T>::Show()
	{
		for (int ix = tail; ix >= head; ix--)
			cout << data[ix] << " ";
		cout << endl;
	}
}