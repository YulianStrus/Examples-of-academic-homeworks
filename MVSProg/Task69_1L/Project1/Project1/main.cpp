#include "iostream"
#include "Namespace.h"
using namespace std;

int main()
{
	cout << "\tNamespace: \tStack" << endl << endl;
	stack::Stack<char> a(6);
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

	//------------------------------------------------------
	cout << "\n\n\tNamespace: \tQueue" << endl << endl;
	queue::Queue<char> Data(10);
	if (Data.isEmpty())
		cout << "Queue is empty\n";
	else if (Data.isFull())
		cout << "Queue is full\n";
	else Data.Show();
	int ct = 1;
	char ch;
	while (ct++ < 10)
	{
		//cin >> ch;
		ch = rand() % 100;
		Data.Enqueue(ch);
	}
	if (Data.isEmpty())
		cout << "Queue is empty\n";
	else if (Data.isFull())
		cout << "Queue is full\n";
	else Data.Show();
	Data.Dequeue();
	Data.Show();

	//------------------------------------------------
	cout << "\n\n\tNamespace: \tList" << endl << endl;
	list::List lst;
	int ctr = 0, pr, n, m, l, y;
	while (ctr++ < 30)
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