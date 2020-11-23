#include<iostream>
#include<ctime>
using namespace std;

template <typename T>
class Array
{
	T * data;
	int size;
	int count;
public:
	Array();
	Array(int);
	Array(const Array&);
	~Array();
	int GetSize();
	void SetSize(int size);
	int GetUpperBound();
	bool IsEmpty();
	void FreeExtra();
	void RemoveAll();
	int GetAt(int pos);
	void SetAt(int pos, T num);
	T& operator[](int pos);
	Array operator=(const Array&);
	void Add(T num);
	void Append(const Array&);
	T* GetData();
	void Show();
};
template <typename T> Array<T>::Array() 
{ 
	size = 5; 
	count = 5; 
	data = new T[size]; 
	for (int i = 0; i < size; i++) 
		data[i] = rand() % 10; 
}
template <typename T> Array<T>::Array(int size) 
{ 
	this->size = size; 
	count = 1; 
	data = new T[size]; 
	for (int i = 0; i < size; i++) 
		data[i] = rand() % 10; 
}
template <typename T> Array<T>::Array(const Array &other)
{
	this->count = other.count;
	this->size = other.size;
	this->data = new T[size];
	for (int i = 0; i < size; ++i)
		this->data[i] = other.data[i];
}
template <typename T> Array<T>::~Array() { delete[]data; }
template <typename T> int Array<T>::GetSize() { return size; }
template <typename T> void Array<T>::SetSize(int size)
{
	if (this->size < size)
	{
		T *temp = new T[this->size];
		for (int i = 0; i < this->size; ++i)
			temp[i] = data[i];
		delete[]data;
		data = new T[size];
		for (int i = 0; i < this->size; ++i)
			data[i] = temp[i];
		delete[]temp;
		count = this->size;
	}
	else if (this->size > size)
	{
		T *temp = new T[size];
		for (int i = 0; i < size; ++i)
			temp[i] = data[i];
		delete[]data;
		data = new T[size];
		for (int i = 0; i < size; ++i)
			data[i] = temp[i];
		delete[]temp;
		count = size;
	}
	this->size = size;
}
template <typename T> int Array<T>::GetUpperBound() { return count - 1; }
template <typename T> bool Array<T>::IsEmpty()
{
	if (count == 0) return true;
	else return false;
}
template <typename T> void Array<T>::FreeExtra()
{
	if (count < size)
		SetSize(count);
}
template <typename T> void Array<T>::RemoveAll()
{
	for (int i = 0; i < size; ++i)
		data[i] == 0;
	delete[]data;
	size = 0;
}
template <typename T> int Array<T>::GetAt(int pos)
{
	if (pos >= 0 && pos < count)
		return data[pos];
	else return -1;
}
template <typename T> void Array<T>::SetAt(int pos, T num)
{
	if (pos >= 0 && pos < count)
		data[pos] = num;
	else cout << "Error!!!" << count << endl;
}
template <typename T> T& Array<T>:: operator [] (int pos)
{
	if (pos >= 0 && pos < count)
		return data[pos];
}
template <typename T> Array<T> Array<T>:: operator=(const Array &other)
{
	this->count = other.count;
	this->size = other.size;
	this->data = new T[size];
	for (int i = 0; i < size; ++i)
		this->data[i] = other.data[i];
	return *this;
}
template <typename T> void Array<T>::Add(T num)
{
	if (count < size)
		data[count] = num;
	else if (count >= size)
	{
		SetSize(size + 1);
		data[size - 1] = num;
		count++;
	}
}
template <typename T> void Array<T>::Append(const Array &obj)
{
	int cnt = 0;
	SetSize(count + obj.size);
	for (int i = count; i < size; ++i)
	{
		data[i] = obj.data[cnt];
		cnt++;
		count++;
	}
}
template <typename T> T* Array<T>::GetData() { return data; }
template <typename T> void Array<T>::Show()
{
	for (int i = 0; i < size; i++)
	{
		if (i > count - 1)
			cout << "NULL ";
		else cout << data[i] << " ";
	}
	cout << endl;
}


int main()
{
	srand(time(0));
	int size = 5;
	cout << "Array1: \t";
	Array <int> arr1;
	arr1.Show();
	cout << "GetSize: \t";
	cout << arr1.GetSize() << endl;
	arr1.SetSize(10);
	cout << "SetSize (10): \t";
	cout << arr1.GetSize() << endl;
	arr1.Show();
	cout << "GetUpperBound: \t";
	cout << arr1.GetUpperBound() << endl;
	cout << "IsEmpty: \t";
	if (arr1.IsEmpty() == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << "FreeExtra: \t" << endl;
	arr1.FreeExtra();
	arr1.Show();
	cout << "RemoveAll: \t";
	arr1.RemoveAll();
	arr1.Show();
	cout  << endl << endl;
	cout << "Array2: \t";
	Array <int> arr2;
	arr2.Show();
	cout << "GetAt (2 element): \t";
	cout << arr2.GetAt(1) << endl;
	arr2.SetAt(1, 43);
	cout << "SetAt (2 element to 43): \t";
	arr2.Show();
	cout << "operator[] (2 element): \t";
	cout << arr2[1] << endl;
	arr2[1] = 89;
	cout << "operator[] (2 element to 89): \t";
	arr2.Show();
	arr2.Add(52);
	cout << "Add: \t";
	arr2.Show();
	Array <int> arr3;
	arr2.Append(arr3);
	cout << "Array 3: \t";
	arr3.Show();
	cout << "Append: \t";
	arr2.Show();
	arr3 = arr2;
	cout << "operator= (Array 2 = Array 1): \t";
	arr3.Show();
	cout << "GetData: \t";
	cout << arr1.GetData() << endl;
	system("pause");
	return 0;
}