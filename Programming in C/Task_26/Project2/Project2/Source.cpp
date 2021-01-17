#include "iostream"
using namespace std;

struct Config
{
	unsigned short int CPU : 1;
	unsigned short int Motherboard : 1;
	unsigned short int Videocard : 1;
	unsigned short int Memory : 1;
	unsigned short int PowerSupply : 1;
	unsigned short int SSDdrive : 1;
	unsigned short int HDDdrive : 1;
	unsigned short int Housing : 1;
};

Config * ConfigPC(Config *Day, int size);
void ShowPC(Config *Day, int size);
void DelArr(Config *Day);

void main()
{
	int size = 1;
	Config *PC = new Config[size];
	PC = ConfigPC(PC, size);
	cout << endl;
	ShowPC(PC, size);

	DelArr(PC);
	system("pause");
}


Config * ConfigPC(Config *PC, int size)
{
	for (int i = 0; i < size; i++)
	{
		int a;
		cout << "Processor: 0 - Intel; 1 - AMD;  ";
		cin >> a;
		if ((a==0)&(a==1)) PC[i].CPU = a;
		cout << "Motherboard: 0 - ATX; 1 - microATX;  ";
		cin >> a; PC[i].Motherboard = a;
		if ((a == 0)&(a == 1)) PC[i].CPU = a;
		cout << "Videocard: 0 - Integrated; 1 - Discrete;  ";
		cin >> a; PC[i].Videocard = a;
		if ((a == 0)&(a == 1)) PC[i].CPU = a;
		cout << "Memory: 0 - 8Gb; 1 - 16Gb;  ";
		cin >> a; PC[i].Memory = a;
		if ((a == 0)&(a == 1)) PC[i].CPU = a;
		cout << "PowerSupply: 0 - 20+4 pin; 1 - 24 pin;  ";
		cin >> a; PC[i].PowerSupply = a;
		if ((a == 0)&(a == 1)) PC[i].CPU = a;
		cout << "SSDdrive: 0 - 2.5\"; 1 - M.2;  ";
		cin >> a; PC[i].SSDdrive = a;
		if ((a == 0)&(a == 1)) PC[i].CPU = a;
		cout << "HDDdrive: 0 - 2.5\"; 1 - 3.5\";  ";
		cin >> a; PC[i].HDDdrive = a;
		if ((a == 0)&(a == 1)) PC[i].CPU = a;
		cout << "Housing: 0 - Full Tower; 1 - Mini Tower;  ";
		cin >> a; PC[i].Housing = a;
		if ((a == 0)&(a == 1)) PC[i].CPU = a;
	}

	return PC;
}

void ShowPC(Config *PC, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Processor: " << endl;
		if (PC[i].CPU == 0) cout << "\tIntel" << endl;
		else if (PC[i].CPU == 1) cout << "\tAMD" << endl;
		cout << "Motherboard: " << endl;
		if (PC[i].Motherboard == 0) cout << "\tATX" << endl;
		else if (PC[i].Motherboard == 1) cout << "\tmicroATX" << endl;
		cout << "Videocard: " << endl;
		if (PC[i].Videocard == 0) cout << "\tIntegrated" << endl;
		else if (PC[i].Videocard == 1) cout << "\tDiscrete" << endl;
		cout << "Memory: " << endl;
		if (PC[i].Memory == 0) cout << "\t8Gb" << endl;
		else if (PC[i].Memory == 1) cout << "\t16Gb" << endl;
		cout << "Power Supply: " << endl;
		if (PC[i].PowerSupply == 0) cout << "\t20+4 pin" << endl;
		else if (PC[i].PowerSupply == 1) cout << "\t24 pin" << endl;
		cout << "SSD drive: " << endl;
		if (PC[i].SSDdrive == 0) cout << "\t2.5\"" << endl;
		else if (PC[i].SSDdrive == 1) cout << "\tM.2" << endl;
		cout << "HDD drive: " << endl;
		if (PC[i].HDDdrive == 0) cout << "\t2.5\"" << endl;
		else if (PC[i].HDDdrive == 1) cout << "\t3.5\"" << endl;
		cout << "Housing: " << endl;
		if (PC[i].Housing == 0) cout << "\tFull Tower" << endl;
		else if (PC[i].Housing == 1) cout << "\tMini Tower" << endl;
	}
}

void DelArr(Config *PC)
{
	delete[] PC;
}