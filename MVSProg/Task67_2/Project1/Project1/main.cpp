#include <iostream>
using namespace std;
struct Node
{
	int x;
	Node *Next, *Prev;
};

class ErrorEmpty
{
	Node *Head;
public:
	ErrorEmpty() { cout << "List is empty" << endl; }
	ErrorEmpty(Node *Head) { this->Head = Head; }
	void Show() { cout << "List is empty" << endl; }
};

class List
{
	Node *Head, *Tail;

public:
	List() : Head(NULL), Tail(NULL) {};
	~List();
	void Show();
	void Add(int x);
	void AddBefor(int l, int y);
	void AddAfter(int o, int z);
	void DeleteElem(int m);
	void Count();
	void Prod(int s);
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
void List::Add(int x)
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

void List::AddBefor(int l, int y)
{
	Node *temp = Tail;
	int k = 1;
	while (temp->x != l)
	{
		k++;
		temp = temp->Prev;
	}

	temp = new Node;
	temp->Prev = NULL;
	temp->x = y;

	if (k == 1)
	{
		temp->Prev = Tail;
		Tail = temp;
	}
	else
	{
		Node *tT;
		tT = Tail;
		for (int i = 1; i < k - 1; ++i)
			tT = tT->Prev;
		temp->Prev = tT->Prev;
		tT->Prev = temp;
	}
}

void List::AddAfter(int o, int z)
{
	Node *temp = Tail;
	int k = 1;
	while (temp->x != o)
	{
		k++;
		temp = temp->Prev;
	}

	temp = new Node;
	temp->Prev = NULL;
	temp->x = z;

	if (k == 1)
	{
		temp->Prev = Tail;
		Tail = temp;
	}
	else
	{
		Node *tT;
		tT = Tail;
		for (int i = 1; i < k; ++i)
			tT = tT->Prev;
		temp->Prev = tT->Prev;
		tT->Prev = temp;
	}
}

void List::DeleteElem(int m)
{
	try
	{
		if (Head == NULL) throw ErrorEmpty(Head);
		else
		{
	Node *temp = Tail;
	int k = 1;
	while (temp->x != m)
	{
		k++;
		temp = temp->Prev;
	}

	{
		if (k == 1)
		{
			temp = Tail;
			Tail = Tail->Prev;
			temp = NULL;
		}
		else
		{
			Node *tT;
			tT = Tail;
			for (int i = 1; i < k - 1; ++i)
				tT = tT->Prev;
			temp = tT;
			temp = temp->Prev;
			tT->Prev = temp->Prev;
			temp = NULL;
		}
	}
		}
	}
	catch (ErrorEmpty&obj) { obj.Show(); }
}

void List::Count()
{
	try
	{
		if (Head == NULL) throw ErrorEmpty(Head);
		else
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
	}
	catch (ErrorEmpty &obj) { obj.Show(); }
}

void List::Prod(int s)
{
	try
	{
		if (Head == NULL) throw ErrorEmpty(Head);
		else
		{
	Node *temp = Head;
	int k = 1;
	while (temp != NULL)
	{
		if (temp->x > s)
		{
			k *= temp->x;
			temp = temp->Next;
		}
		else
			temp = temp->Next;
	}
	cout << "The product of the larger numbers " << s << " \= " << k << endl;
		}
	}
	catch (ErrorEmpty &obj) { obj.Show(); }
}

void List::Find(int n)
{
	try
	{
		if (Head == NULL) throw ErrorEmpty(Head);
		else
		{
	Node *temp = Head;
	int k = 0;
	while (temp != NULL)
	{
		if (temp->x > n)
		{
			k++;
			temp = temp->Next;
		}
		else
			temp = temp->Next;
	}

	if (k > 0)
		cout << "Found " << k << " numbers greater than " << n << endl;
	else
		cout << "Element not found! " << endl;
		}
	}
	catch (ErrorEmpty &obj) { obj.Show(); }
}

void List::Show()
{
	Node *temp = Tail;
	while (temp != NULL)
	{
		cout << temp->x << " ";
		temp = temp->Prev;
	}
	cout << "\n";
	/*
	temp = Head;
	while (temp != NULL)
	{
		cout << temp->x << " ";
		temp = temp->Next;
	} cout << "\n";
	*/
}

int main()
{
	List lst;
	lst.Count();
	int ct = 0, pr, n, m, l, y, k, z, s;
	cout << "Enter number: ";
	cin >> s;
	lst.Prod(s);
	while (ct++ < 30)
	{
		//		cout << "Enter element: ";
		//		cin >> pr;
		pr = rand() % 10;
		lst.Add(pr);
	}
	lst.Show();

	cout << "Enter number: ";
	cin >> s;
	lst.Prod(s);

	lst.Count();

	cout << "Enter the number to put before: ";
	cin >> l;
	cout << "Enter element: ";
	cin >> y;
	lst.AddBefor(l, y);
	lst.Show();

	cout << "Enter the number to put after: ";
	cin >> k;
	cout << "Enter element: ";
	cin >> z;
	lst.AddAfter(k, z);
	lst.Show();

	cout << "Find element: ";
	cin >> n;
	lst.Find(n);

	cout << "Delete element: ";
	cin >> m;
	lst.DeleteElem(m);
	lst.Show();

	system("PAUSE");
	return 0;
}