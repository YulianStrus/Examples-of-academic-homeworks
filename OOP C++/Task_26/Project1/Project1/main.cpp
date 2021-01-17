#include "iostream"
using namespace std;

template<class T>
class Unique_Ptr
{
	T *ptr;
public:
	Unique_Ptr() { ptr = nullptr; }
	Unique_Ptr(T *ptr) { this->ptr = ptr; }
	~Unique_Ptr() { delete ptr; }
	Unique_Ptr(const Unique_Ptr&obj) = delete;
	Unique_Ptr operator=(const Unique_Ptr&obj) = delete;
	void Move(Unique_Ptr&obj) { obj.ptr = this->ptr; this->ptr = nullptr; }
	void Show() { cout << "Pointer: " << *ptr << endl; }
};

int main()
{
	Unique_Ptr<int>ptr1(new int(15));
	Unique_Ptr<int>ptr2;
	ptr1.Move(ptr2);
	ptr2.Show();
	
	system("pause");
	return 0;
}