#include "iostream"
#include "thread"
#include "ctime"
#include "vector"
#include "mutex"
using namespace std;

void Add(vector<int>&arr, mutex&m_arr, int n)
{
	m_arr.lock();
	arr.push_back(n);
	m_arr.unlock();
}

void Delete(vector<int>&arr, mutex&m_arr)
{
	m_arr.lock();
	arr.pop_back();
	m_arr.unlock();
}

void AddPos(vector<int>&arr, mutex&m_arr, int pos, int n)
{
	m_arr.lock();
	arr.insert(arr.begin() + pos, n);
	m_arr.unlock();
}

void Show(vector<int>arr, mutex&m_arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		m_arr.lock();
		cout << arr[i] << " ";
		m_arr.unlock();
	}
	cout << endl << endl;
}

int main(void)
{
	vector<int>arr;
	arr.reserve(10);
	mutex m_arr;
	int a, b, c, d, e;
	cout << "Enter 5 number: " << endl;
	cin >> a >> b >> c >> d >> e;
	cout << endl;

	thread th1(Add, ref(arr), ref(m_arr), a);
	if (th1.joinable())th1.join();
	else th1.detach();

	thread th2(Add, ref(arr), ref(m_arr), b);
	if (th2.joinable())th2.join();
	else th2.detach();

	thread th3(Add, ref(arr), ref(m_arr), c);
	if (th3.joinable())th3.join();
	else th3.detach();

	thread th4(Add, ref(arr), ref(m_arr), d);
	if (th4.joinable())th4.join();
	else th4.detach();

	thread th5(Show, arr, ref(m_arr));
	if (th5.joinable())th5.join();
	else th5.detach();

	thread th6(Delete, ref(arr), ref(m_arr));
	if (th6.joinable())th6.join();
	else th6.detach();

	thread th7(Show, arr, ref(m_arr));
	if (th7.joinable())th7.join();
	else th7.detach();

	thread th8(AddPos, ref(arr), ref(m_arr), 2, e);
	if (th8.joinable())th8.join();
	else th8.detach();

	thread th9(Show, arr, ref(m_arr));
	if (th9.joinable())th9.join();
	else th9.detach();

	system("pause");
}

