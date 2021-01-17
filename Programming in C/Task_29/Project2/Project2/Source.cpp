#include <iostream>
using namespace std;

struct Baggage
{
	int number;
	double mass;
};

Baggage* Add(Baggage *ArrayData, int size);
Baggage* AddLine(Baggage *ArrayData, int &size);
Baggage* menu(Baggage *ArrayData, int &size);

void main()
{
	int size = 1;
	Baggage *ArrayData = new Baggage[size];
	ArrayData = Add(ArrayData, size);
	ArrayData = menu(ArrayData, size);
	for (int i = 0; i < size; ++i)
		cout << i + 1 << ". " << ArrayData[i].number << " baggage - " << ArrayData[i].mass << endl;
	FILE *f;
	fopen_s(&f, "1.dat", "wb");
	fwrite(&*ArrayData, sizeof(Baggage), size, f);
	fclose(f);
	delete[]ArrayData;
	ArrayData = new Baggage[size];
	double sum = 0;
	double count = 0;
	int count1 = 0;
	fopen_s(&f, "1.dat", "rb");
	fread(&*ArrayData, sizeof(Baggage), size, f);
	fclose(f);
	for (int i = 0; i < size; ++i)
	{
		sum = sum + (ArrayData[i].mass / ArrayData[i].number);
		++count;
	}
	double av;
	av = sum / count;
	cout << "Task 1: " << endl;
	for (int i = 0; i < size; ++i)
	{
		if ((ArrayData[i].mass / ArrayData[i].number) <= av + 0.3 && (ArrayData[i].mass / ArrayData[i].number) >= av - 0.3)
		{
			cout << i + 1 << ". " << ArrayData[i].number << " baggage - " << ArrayData[i].mass << " kg" << endl;
			++count1;
		}
	}
	if (count1 == 0) cout << "Not baggage, the average weight of one thing is not different more than 0.3 kg from the total average weight of one thing " << endl;
	cout << "Task 2: " << endl;
	sum = 0, count = 0, count1 = 0;
	for (int i = 0; i < size; ++i)
	{
		sum = sum + ArrayData[i].number;
		++count;
	}
	av = sum / count;
	for (int i = 0; i < size; ++i)
	{
		if (ArrayData[i].number > 2 || ArrayData[i].number > av)
		{
			cout << i + 1 << ". " << ArrayData[i].number << " baggage - " << ArrayData[i].mass << " kg" << endl;
			++count1;
		}
	}
	if (count1 = 0) cout << "Not passengers who have more than two things and the number of passengers who have more things than all on average" << endl;
	cout << "Task 3: " << endl;
	count1 = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int k = i + 1; k < size; ++k)
		{
			if (ArrayData[i].number == ArrayData[k].number && (ArrayData[i].mass <= ArrayData[k].mass + 0.5 &&  ArrayData[i].mass >= ArrayData[k].mass - 0.5))
			{
				++count1;
				cout << i + 1 << ". " << ArrayData[i].number << " baggage - " << ArrayData[i].mass << " kg - " << k + 1 << ". " << ArrayData[k].number << " baggage - " << ArrayData[k].mass << " kg" << endl;
			}
		}
	}
	if (count1 = 0) cout << "Not passenger whose baggage coincides in quantity and differ in weight by no more than on 0,5 kg" << endl;
	cout << "Task 4: " << endl;
	count1 = 0, count = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int k = 0; k < size; ++k)
		{
			if (i == k) continue;
			if (ArrayData[i].number > ArrayData[k].number && ArrayData[i].mass / ArrayData[i].number > ArrayData[k].mass / ArrayData[k].number)
				++count;
		}
		if (count == size - 1)
		{
			++count1;
			cout << i + 1 << ". " << ArrayData[i].number << " baggage - " << ArrayData[i].mass << " kg" << endl;
		}
		count = 0;
	}
	if (count1 = 0) cout << "Not passenger whose baggage exceeds the baggage of each of the other passengers and the number of items and weight" << endl;
	delete[]ArrayData;
	fclose(f);
	system("pause");
}

Baggage* Add(Baggage *ArrayData, int size)
{
	cout << "Please enter number of buggage: ";
	cin >> ArrayData[size - 1].number;
	cout << "Please enter the weight: ";
	cin >> ArrayData[size - 1].mass;
	return ArrayData;
}

Baggage* AddLine(Baggage *ArrayData, int &size)
{
	Baggage *temp = new Baggage[size];
	for (int i = 0; i < size; ++i)
		temp[i] = ArrayData[i];
	delete[]ArrayData;
	++size;
	ArrayData = new Baggage[size];
	for (int i = 0; i < size - 1; ++i)
		ArrayData[i] = temp[i];
	delete[]temp;
	ArrayData = Add(ArrayData, size);
	return ArrayData;
}

Baggage* menu(Baggage *ArrayData, int &size)
{
	char select;
	cout << "Add passanger [y/n]" << endl;
	cin >> select;
	switch (select)
	{
	case 'y':
		ArrayData = AddLine(ArrayData, size);
		ArrayData = menu(ArrayData, size);
		break;
	}
	return ArrayData;
}
