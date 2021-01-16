#pragma once
#include "iostream"
#include "Header.h"
#include "iomanip"

void main()
{
	int size = 5;
	Employees *DB = new Employees[size];
	double *Age = new double[size];
	double *Stand = new double[size];
	InitDB(DB, size); 
	double Exp;
	char a = 0, sur[32], nm[32];
	int sizeN, d, m, y, Fa;
	cout << "Enter today's date: " << "\nday: ";
	cin >> d;
	cout << "mounth: ";
	cin >> m;
	cout << "year: ";
	cin >> y;
	while (a != 'q')
	{
		cout << "\nEnter number: " << endl;
		cout << "\n\t1 - Enter number new DB" << "\n\t2 - Show all DB" << "\n\t3 - Age" << "\n\t4 - Standing" << "\n\t5 - Add new employees" << "\n\t6 - Delete new employees" << "\n\t7 - Edit surname" << "\n\t8 - Find for surname" << "\n\t9 - Find for Age" << "\n\ta - Find surname for first symbol" << "\n\tb - Show birthday of the month" << "\n\tc - Show male" << "\n\td - Show female" << "\n\te - Show pensioner" << "\n\tq - Exit" << endl;
		cin >> a;
		cout << endl;
		switch (a)
		{
		case '1':
			cout << "Enter number employees: " << endl;
			cin >> sizeN;
			DB = AddDB(DB, size, sizeN);
			size = sizeN;
		case '2':
			ShowDB(DB, size);
			break;
		case '3':
			cout << "Enter surname: ";
			cin.ignore();
			cin.getline(sur, 32);
			cout << "Enter name: ";
			cin.getline(nm, 32);
			cout << endl;
			*Age = AgeEmp(DB, size, Age, d, m, y);
			for (int i = 0; i < size; i++)
			{

				if ((stricmp(DB[i].Surname, sur) == 0)&(stricmp(DB[i].Name, nm) == 0))
					cout << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\tStanding: " << setprecision(3) << Age[i] << " year";
			}
			break;
		case '4':
			cout << "Enter surname: ";
			cin.ignore();
			cin.getline(sur, 32);
			cout << "Enter name: ";
			cin.getline(nm, 32);
			cout << endl;
			*Stand = Standing(DB, size, Stand, d, m, y);
			for (int i = 0; i < size; i++)
			{

				if ((stricmp(DB[i].Surname, sur) == 0)&(stricmp(DB[i].Name, nm) == 0))
					cout << DB[i].Surname << " " << DB[i].Name << " " << DB[i].Patronymic << "\tStanding: " << setprecision(3) << Stand[i] << " year";
			}
			break;
		case '5':
			DB = AddEmpl(DB, size);
			size++;
			break;
		case '6':
			cout << "Enter surname: ";
			cin.ignore();
			cin.getline(sur, 32);
			cout << "Enter name: ";
			cin.getline(nm, 32);
			cout << endl;
			DB = DelEmpl(DB, size, sur, nm);
			size--;
			break;
		case '7':
			cout << "Enter surname: ";
			cin.ignore();
			cin.getline(sur, 32);
			cout << "Enter name: ";
			cin.getline(nm, 32);
			cout << endl;
			DB = EditSur(DB, size, sur, nm);
			break;
		case '8':
			cout << "Enter surname: ";
			cin.ignore();
			cin.getline(sur, 32);
			cout << endl;
			FindSur(DB, size, sur);
			break;
		case '9':
			cout << "Enter age: ";
			cin >> Fa;
			cout << endl;
			*Age = AgeEmp(DB, size, Age, d, m, y);
			FindAge(DB, size, Age, Fa);
			break;
		case 'a':
			FindSymb(DB, size);
			break;
		case 'b':
			FindBirth(DB, size, m);
			break;
		case 'c':
			FindMale(DB, size);
			break;
		case 'd':
			FindFemale(DB, size);
			break;
		case 'e':
			*Age = AgeEmp(DB, size, Age, d, m, y);
			*Stand = Standing(DB, size, Stand, d, m, y);
			FindPens(DB, size, Age, Stand);
			break;
		case 'q':
			break;
		default: cout << "Error!!!"; break;
		}
	}

	DelDB(DB);

	system("pause");
}