#include "iostream"
using namespace std;

template<class T>
class Shared_Ptr
{
	T *ptr;
	int *count;
public:
	Shared_Ptr() { ptr = nullptr; count = new int(0); }
	Shared_Ptr(T *ptr) { count = new int(1); this->ptr = ptr; }
	~Shared_Ptr()
	{
		if (*count == 1)
		{
			delete ptr;
			cout << "Remove" << endl;
		}
		else
		{
			(*count)--;
			cout << "Delete" << endl;
		}
	}
	Shared_Ptr(const Shared_Ptr&obj)
	{
		this->ptr = obj.ptr;

		this->count = obj.count;
		(*this->count)++;
	}
	Shared_Ptr operator=(const Shared_Ptr&obj)
	{
		this->ptr = obj.ptr;

		this->count = obj.count;
		(*this->count)++;
		return *this;
	}
};

int main()
{
	Shared_Ptr<int>ptr1(new int(15));
	Shared_Ptr<int>ptr2(ptr1);
	Shared_Ptr<int>ptr3 = ptr1;
	ptr2 = ptr3;
	ptr1 = ptr3;
	
	system("pause");
	return 0;
}