#define QUEUE_H
#include <cassert>
#include <iostream>
using namespace std;

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
bool Queue<T>:: isFull()
{
	if ((head == 0) && (tail == size -1)) return true;
	else return false;
}
template<typename T>
bool Queue<T>::isEmpty()
{
	if ((head == 0)&&(tail == 0)) return true;
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

int main()
{
	Queue<char> Data(10);
	if  (Data.isEmpty())
		cout << "Queue is empty\n";
	else if (Data.isFull())
		cout << "Queue is full\n";
	else Data.Show();
	int ct = 1;
	char ch;
	while (ct++ < 10)
	{
		cin >> ch;
		Data.Enqueue(ch);
	}
	if (Data.isEmpty())
		cout << "Queue is empty\n";
	else if (Data.isFull())
		cout << "Queue is full\n";
	else Data.Show();
	Data.Dequeue();
	Data.Show();
	system("pause");
	return 0;
}