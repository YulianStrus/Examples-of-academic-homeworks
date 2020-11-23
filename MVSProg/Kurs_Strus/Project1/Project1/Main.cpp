#pragma once
#include "iostream"
#include "cstdio"
#include "Header.h"
using namespace std;

int main()
{
	int size = 5;
	int d = 21, m = 01, y = 2019;
	int a = 1, b = 1, c = 1, s = 1, dy, mth, yr, ag, gld, slvr, brz, dsq, sizeN;
	char  nm[32], sur[32], ptr[32], cntr[32], sprt[32];
	SportTab *mas = new SportTab[size];
	double *Age = new double[size];
	double *Awd = new double[size];
	*Age = AgeEmp(mas, size, Age, d, m, y);
	*Awd = AwdEmp(mas, size, Awd);

	while (a != 0)
	{
		cout << "Enter number:" << endl;
		cout << "\t1 - Create \n\t2 - Initialization \n\t3 - Show \n\t4 - Add new element \n\t5 - Delete element \n\t6 - Edit \n\t7 - Find \n\t8 - Sort \n\t9 - Write in file \n\t10 - Read from file \n\t0 - Quit" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			mas = Create(mas, size);
			break;
		case 2:
			InitMas(mas);
			break;
		case 3:
			ShowMas(mas, size, Age, Awd);
			break;
		case 4:
			cout << "Enter number sportsmen: " << endl;
			cin >> sizeN;
			mas = AddMas(mas, size, sizeN);
			size = sizeN;
			break;
		case 5:
			cout << "Enter surname: ";
			cin.ignore();
			cin.getline(sur, 32);
			cout << "Enter name: ";
			cin.getline(nm, 32);
			cout << endl;
			mas = DelElm(mas, size, sur, nm);
			size--;
			break;
		case 6:
			while (b != 0)
			{
				cout << "Enter number:" << endl;
				cout << "\t1 - Edit surname \n\t2 - Edit name \n\t3 - Edit Patronymic \n\t4 - Edit birthday \n\t5 - Edit country \n\t6 - Edit sport \n\t7 - Edit award \n\t8 - Edit disqualification \n\t0 - Main menu" << endl;
				cin >> b;

				if (b == 61)
				{
					cout << "Enter surname: ";
					cin.ignore();
					cin.getline(sur, 32);
					cout << "Enter name: ";
					cin.getline(nm, 32);
					cout << endl;
					mas = EditSur(mas, size, sur, nm);
				}
				else if (b == 62)
				{
					cout << "Enter surname: ";
					cin.ignore();
					cin.getline(sur, 32);
					cout << "Enter name: ";
					cin.getline(nm, 32);
					cout << endl;
					mas = EditName(mas, size, sur, nm);
				}
				else if (b == 63)
				{
					cout << "Enter surname: ";
					cin.ignore();
					cin.getline(sur, 32);
					cout << "Enter name: ";
					cin.getline(nm, 32);
					cout << endl;
					mas = EditPatronymic(mas, size, sur, nm);
				}
				else if (b == 64)
				{
					cout << "Enter surname: ";
					cin.ignore();
					cin.getline(sur, 32);
					cout << "Enter name: ";
					cin.getline(nm, 32);
					cout << endl;
					mas = EditBirth(mas, size, sur, nm);
				}
				else if (b == 65)
				{
					cout << "Enter surname: ";
					cin.ignore();
					cin.getline(sur, 32);
					cout << "Enter name: ";
					cin.getline(nm, 32);
					cout << endl;
					mas = EditCountry(mas, size, sur, nm);
				}
				else if (b == 66)
				{
					cout << "Enter surname: ";
					cin.ignore();
					cin.getline(sur, 32);
					cout << "Enter name: ";
					cin.getline(nm, 32);
					cout << endl;
					mas = EditSport(mas, size, sur, nm);
				}
				else if (b == 67)
				{
					cout << "Enter surname: ";
					cin.ignore();
					cin.getline(sur, 32);
					cout << "Enter name: ";
					cin.getline(nm, 32);
					cout << endl;
					mas = EditAward(mas, size, sur, nm);
				}
				else if (b == 68)
				{
					cout << "Enter surname: ";
					cin.ignore();
					cin.getline(sur, 32);
					cout << "Enter name: ";
					cin.getline(nm, 32);
					cout << endl;
					mas = EditDisqual(mas, size, sur, nm);
				}
				else continue;
			}
			break;
		case 7:
			while (c != 0)
			{
				cout << "Enter number:" << endl;
				cout << "\t71 - Find surname \n\t72 - Find name \n\t73 - Find patronymic \n\t74 - Find age \n\t75 - Find year \n\t76 - Find month \n\t77 - Find day \n\t78 - Find country \n\t79 - Find sport \n\t710 - Find gold \n\t711 - Find silver \n\t712 - Find bronze \n\t713 - Find disqualification \n\t0 - Main menu" << endl;
				cin >> c;

				if (c == 71)
				{
					cout << "Enter surname: ";
					cin.ignore();
					cin.getline(sur, 32);
					cout << endl;
					FindSur(mas, size, Age, Awd, sur);
				}
				else if (c == 72)
				{
					cout << "Enter name: ";
					cin.ignore();
					cin.getline(nm, 32);
					cout << endl;
					FindName(mas, size, Age, Awd, nm);
				}
				else if (c == 73)
				{
					cout << "Enter patronymic: ";
					cin.ignore();
					cin.getline(ptr, 32);
					cout << endl;
					FindPatronymic(mas, size, Age, Awd, ptr);
				}
				else if (c == 74)
				{
					cout << "Enter age: ";
					cin.ignore();
					cin >> ag;
					cout << endl;
					FindAge(mas, size, Age, Awd, ag);
				}
				else if (c == 75)
				{
					cout << "Enter year: ";
					cin.ignore();
					cin >> yr;
					cout << endl;
					FindYear(mas, size, Age, Awd, yr);
				}
				else if (c == 76)
				{
					cout << "Enter month: ";
					cin.ignore();
					cin >> mth;
					cout << endl;
					FindMonth(mas, size, Age, Awd, mth);
				}
				else if (c == 77)
				{
					cout << "Enter day: ";
					cin.ignore();
					cin >> dy;
					cout << endl;
					FindDay(mas, size, Age, Awd, dy);
				}
				else if (c == 78)
				{
					cout << "Enter country: ";
					cin.ignore();
					cin.getline(cntr, 32);
					cout << endl;
					FindCntr(mas, size, Age, Awd, cntr);
				}
				else if (c == 79)
				{
					cout << "Enter sport: ";
					cin.ignore();
					cin.getline(sprt, 32);
					cout << endl;
					FindSport(mas, size, Age, Awd, sprt);
				}
				else if (c == 710)
				{
					cout << "Enter gold: ";
					cin.ignore();
					cin >> gld;
					cout << endl;
					FindGold(mas, size, Age, Awd, gld);
				}
				else if (c == 711)
				{
					cout << "Enter silver: ";
					cin.ignore();
					cin >> slvr;
					cout << endl;
					FindSilver(mas, size, Age, Awd, slvr);
				}
				else if (c == 712)
				{
					cout << "Enter bronze: ";
					cin.ignore();
					cin >> brz;
					cout << endl;
					FindBronz(mas, size, Age, Awd, brz);
				}
				else if (c == 713)
				{
					cout << "Enter disqualification: ";
					cin.ignore();
					cin >> dsq;
					cout << endl;
					FindDisqual(mas, size, Age, Awd, dsq);
				}
				else continue;
			}
			break;
		case 8:
			while (s != 0)
			{
				cout << "Enter number:" << endl;
				cout << "\t81 - Sort surname \n\t82 - Sort name \n\t83 - Sort patronymic \n\t84 - Sort age \n\t85 - Sort country \n\t86 - Sort sport \n\t87 - Sort gold \n\t88 - Sort silver \n\t89 - Sort bronze \n\t810 - Sort disqualification \n\t0 - Main menu" << endl;
				cin >> s;

				if (s == 81)
				{
					mas = SortSur(mas, size);
					ShowMas(mas, size, Age, Awd);
				}
				else if (s == 82)
				{
					mas = SortName(mas, size);
					ShowMas(mas, size, Age, Awd);
				}
				else if (s == 83)
				{
					mas = SortPatronymic(mas, size);
					ShowMas(mas, size, Age, Awd);
				}
				else if (s == 84)
				{
					mas = SortAge(mas, size, Age);
					ShowMas(mas, size, Age, Awd);
				}
				else if (s == 85)
				{
					mas = SortCountry(mas, size);
					ShowMas(mas, size, Age, Awd);
				}
				else if (s == 86)
				{
					mas = SortSport(mas, size);
					ShowMas(mas, size, Age, Awd);
				}
				else if (s == 87)
				{
					mas = SortGold(mas, size);
					ShowMas(mas, size, Age, Awd);
				}
				else if (s == 88)
				{
					mas = SortSilver(mas, size);
					ShowMas(mas, size, Age, Awd);
				}
				else if (s == 89)
				{
					mas = SortBronze(mas, size);
					ShowMas(mas, size, Age, Awd);
				}
				else if (s == 810)
				{
					mas = SortDisqual(mas, size);
					ShowMas(mas, size, Age, Awd);
				}
				else continue;
			}

			break;

		case 9:
			WriteFile(mas, size);
			break;
		case 10:
			ReadFile(mas, size);
			ShowMas(mas, size, Age, Awd);
			break;
		case 0:
			break;
		}
	}

	system("pause");
	return 0;
}