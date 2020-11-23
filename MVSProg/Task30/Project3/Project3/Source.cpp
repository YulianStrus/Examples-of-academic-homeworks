#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void main()
{
	srand(unsigned(time(0)));

	const int size = 10;
	double *mas[size];
	for (int i = 0; i < size; ++i)
		mas[i] = new double(-5 + (double)rand() / RAND_MAX * 25);


	cout << "Array:" << endl;
	for (int i = 0; i < size; ++i)
		cout << *mas[i] << " ";
	cout << endl;

	double min = *mas[0];
	int p_min = 0;
	for (int i = 1; i < size; ++i)
	{
		if (*mas[i] < min)
		{
			min = *mas[i];
			p_min = i;
		}
	}
	cout << "Min: " << min << endl;

	*mas[p_min] = *mas[size - 1];
	*mas[size - 1] = min;

	cout << "Swap array:" << endl;
	for (int i = 0; i < size; ++i)
		cout << *mas[i] << " ";
	cout << endl;

	for (int i = 0; i < size; ++i)
		delete mas[i];

	system("pause");
}