#define QUEUE_H
#include <cassert>
#include <iostream>
using namespace std;

template<typename T>
class Queue
{
private:
	T *data;
	int *prior;
	const int size;
	int head;
	int	tail;
	int count;
public:
	Queue(int = 10);
	~Queue();
	bool isFull();
	bool isEmpty();
	void InsertWithPriority(const T &, int newprt);
	T PullHighestPriorityElement(int maxi);
	T Peek();
	void ShowMax(int maxi);
	void Show();
};
template<typename T>
Queue<T>::Queue(int obj) :
	size(obj),
	head(-1), tail(-1), count(0)
{
	data = new T[size + 1];
	prior = new int[size + 1];
}
template<typename T>
Queue<T>::~Queue()
{
	delete[] data;
}
template<typename T>
bool Queue<T>::isFull()
{
	if ((head == -1) && (tail == size-1)) return true;
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
T Queue<T>::PullHighestPriorityElement(int maxi)
{
	T Value = 0;
	assert(count > 0);
	if ((head < maxi) && (head>maxi))
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

int main()
{
	Queue<char> Data(10);
	if (Data.isEmpty())
		cout << "Queue is empty\n" << endl;
	else if (Data.isFull())
		cout << "Queue is full\n" << endl;
	else Data.Show();
	int ct = 0, pr;
	char ch;
	while (ct++ < 10)
	{
		cout << "Enter element: ";
		cin >> ch;
//		cout << "Enter priority: ";
//		cin >> pr; 
		pr = rand() % 10; //як варіант
		Data.InsertWithPriority(ch, pr);
	}
	Data.Show();
	if (Data.isEmpty())
		cout << "Queue is empty\n" << endl;
	else if (Data.isFull())
		cout << "Queue is full\n" << endl;
	int maxi = Data.Peek();
	cout << "The bigest priority element: "; Data.ShowMax(maxi);
	Data.PullHighestPriorityElement(maxi);
	Data.Show();	
	system("pause");
	return 0;
}