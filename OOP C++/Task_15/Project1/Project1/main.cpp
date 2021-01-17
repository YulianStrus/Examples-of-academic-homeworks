#include <iostream>
using namespace std;
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
int main()
{
	List lst;
	int ct = 0, pr, n, m, l, y;
	while (ct++ < 30)
	{
		//		cout << "Enter element: ";
		//		cin >> pr;
		pr = rand() % 100;
		lst.AddEnd(pr);
	}
	lst.Show();

	lst.Summ();

	lst.Count();

	cout << "Enter the number to put before: ";
	cin >> l;
	cout << "Enter element: ";
	cin >> y;
	lst.AddCentr(l, y);
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