#include "iostream"
using namespace std;
template <typename T>
T SymbPunct(T arr[], int size, T s)
{
	int k=0;
	for (int i = 0; i < size; i++)
	{
		if (s == arr[i]) k = 1;
	}
	return k;
}


int main()
{
	const int size = 10;
	char arr[size] = { '.',',',':',';','-','"','!','?','\'','...' };
	cout << "Enter symbol:" << endl;
	char s;
	cin >> s;

	bool Symb = SymbPunct(arr, size, s);
	if (Symb == 1) cout << "true" << endl;
	else cout << "false" << endl;

	system("pause");
}