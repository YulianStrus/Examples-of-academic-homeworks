#include "iostream"
#include "thread"
#include "ctime"
#include "vector"
#include "mutex"
using namespace std;

void InitArr(vector<int>&arr, mutex&m_arr)
{
	srand(time(NULL));
	for (int i = 0; i < arr.size(); ++i)
	{
		m_arr.lock();
		arr[i] = rand() % 9 + 1;
		m_arr.unlock();
	}
}

void Show(vector<int>arr)
{
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl << endl;
}

class Sum : private vector<int>
{
public:
	void operator()(vector<int>arr, mutex&m_arr)
	{
		int sum = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			m_arr.lock();
			sum += arr[i];
			m_arr.unlock();
		}
		m_arr.lock();
		cout << "Sum of arr = " << sum << endl << endl;
		m_arr.unlock();
	}
};

class Prod : private vector<int>
{
public:
	void operator()(vector<int>arr, mutex&m_arr)
	{
		int mult = 1;
		for (int i = 0; i < arr.size(); ++i)
		{
			m_arr.lock();
			mult *= arr[i];
			m_arr.unlock();
		}
		m_arr.lock();
		cout << "Product of array = " << mult << endl << endl;
		m_arr.unlock();
	}
};

class Arithmetic : private vector<int>
{
public:
	void operator()(vector<int>arr, mutex&m_arr)
	{
		int sum = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			m_arr.lock();
			sum += arr[i];
			m_arr.unlock();
		}
		m_arr.lock();
		cout << "Arithmetic mean of array = " << (double)sum / arr.size() << endl << endl;
		m_arr.unlock();
	}
};

int main(void)
{
	vector<int>arr(3);
	mutex m_arr;

	thread th1(InitArr, ref(arr), ref(m_arr));
	if (th1.joinable())th1.join();
	else th1.detach();

	thread th2(Show, arr);
	if (th2.joinable())th2.join();
	else th2.detach();

	Sum s;
	thread th3(s, arr, ref(m_arr));
	if (th3.joinable())th3.join();
	else th3.detach();

	Prod m;
	thread th4(m, arr, ref(m_arr));
	if (th4.joinable())th4.join();
	else th4.detach();

	Arithmetic ar;
	thread th5(ar, arr, ref(m_arr));
	if (th5.joinable())th5.join();
	else th5.detach();

	system("pause");
}

