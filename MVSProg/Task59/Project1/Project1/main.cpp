#define QUEUE_H
#include <cassert>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

template<typename T>
class Queue
{
private:
	T *data;
	T *repor;
	int *prior;
	int *prio;
	const int size;
	int sizerep;
	int *time_h;
	int *time_m;
	int head;
	int	tail;
	int count;
public:
	Queue(int = 10);
	~Queue();
	bool isFull();
	bool isEmpty();
	void InsertWithPriority(const T &, int newprt);
	void Sort();
	void Report(const T &, int nprt, int ntime_h, int ntime_m, int full);
	T PullHighestPriorityElement(int maxi);
	T Peek();
	void ShowMax(int maxi);
	void Show();
	void ShowReport(int full);
};
template<typename T>
Queue<T>::Queue(int obj) :
	size(obj), sizerep(obj),
	head(-1), tail(-1), count(0)
{
	data = new T[size + 1];
	repor = new T[sizerep + 1];
	prior = new int[size + 1];
	prio = new int[sizerep + 1];
	time_h = new int[sizerep + 1];
	time_m = new int[sizerep + 1];
}
template<typename T>
Queue<T>::~Queue()
{
	delete[] data;
}
template<typename T>
bool Queue<T>::isFull()
{
	if ((head == -1) && (tail == size - 1)) return true;
	else return false;
}
template<typename T>
bool Queue<T>::isEmpty()
{
	if ((head == -1) && (tail == -1)) return true;
	else return false;
}
template<typename T>
void Queue<T>::InsertWithPriority(const T &newobj, int newprt)
{
	assert(count < size);
	{
		tail++;
		data[tail] = newobj;
		prior[tail] = newprt;
	}
	count++;
	if (tail > size)
		tail -= size + 1;
}

template<typename T>
void Queue<T> :: Sort()
{
	char tmp; int temp;
	bool chg = true;
	while (chg)
	{
		chg = false;
		for (int i = 0; i < count - 1; i++)
			if (prior[i + 1] > prior[i])
			{
				tmp = data[i];
				temp = prior[i];
				data[i] = data[i + 1];
				prior[i] = prior[i + 1];
				data[i + 1] = tmp;
				prior[i + 1] = temp;
				chg = true;
			}
	}
}
template<typename T>
void Queue<T>::Report(const T &nobj, int nprt, int ntime_h, int ntime_m, int full)
{
	repor[full] = nobj;
	prio[full] = nprt;
	time_h[full] = ntime_h;
	time_m[full] = ntime_m;

	if (full > sizerep)
		sizerep++;
}
template<typename T>
T Queue<T>::PullHighestPriorityElement(int maxi)
{
	T Value = 0;
	assert(count > 0);
	if ((head < maxi) && (head > maxi))
		Value = data[head++];
	else head++;
	count--;
	if (head > size)
		head -= size + 1;
	return Value;
}
template<typename T>
T Queue<T>::Peek()
{
	int maxi, max = 0;
	for (int i = 0; i < size; i++)
		if (prior[i] > max)
		{
			max = prior[i];
			maxi = i;
		}

	return maxi;
}
template<typename T>
void Queue<T>::ShowMax(int maxi)
{
	for (int ix = tail; ix >= head; ix--)
	{
		if (ix == maxi)
			cout << data[ix] << "(" << prior[ix] << "); ";
	}
	cout << endl << endl;
}

template<typename T>
void Queue<T>::Show()
{
	for (int ix = tail; ix > head; ix--)
		cout << data[ix] << "(" << prior[ix] << "); ";
	cout << endl << endl;
}
template<typename T>
void Queue<T>::ShowReport(int full)
{
	for (int i = 0; i < full; i++)
		cout << repor[i] << "(" << prio[i] << ")-" << time_h[i] << ":" << time_m[i]<< ";  ";
	cout << endl << endl;
}

int main()
{
	int size=5;
	Queue<char> Data(size);
	if (Data.isEmpty())
		cout << "Queue is empty\n" << endl;
	else if (Data.isFull())
		cout << "Queue is full\n" << endl;
	else Data.Show();
	int ct = 0, ct1 = 0, time_h = 0, time_m = 0, ntime = 0, pr, full=0;
	char ch, cr;
	while (ct++ < size)
	{
		cout << "Enter element: ";
		cin >> ch;
		cr = ch;
		//		cout << "Enter priority: ";
		//		cin >> pr; 
		//		cout << "Enter hour: ";
		//		cin >> time_h; 
		//		cout << "Enter minyts: ";
		//		cin >> time_m; 
		pr = rand() % 10; //як варіант
		time_h = 9;
		time_m = 40+ct;
		Data.Report(ch, pr, time_h, time_m, full);
		Data.InsertWithPriority(ch, pr);		
		full++;
	}
	Data.Show();
	Data.Sort();
	cout << "Sort: \n";
	Data.Show();
	if (Data.isEmpty())
		cout << "Queue is empty\n" << endl;
	else if (Data.isFull())
		cout << "Queue is full\n" << endl;
	int maxi = Data.Peek();
//	cout << "The bigest priority element: "; Data.ShowMax(maxi);
	Data.PullHighestPriorityElement(maxi);
	Data.PullHighestPriorityElement(maxi);
	cout << "Report: "; Data.ShowReport(full);
	system("pause");
	return 0;
}