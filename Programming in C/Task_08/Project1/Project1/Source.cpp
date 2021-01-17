#include "iostream"
using namespace std;
void main()
{
	int n, l, j, i, h, k=1;
	char s;
	cout << "Choose the type of rectangular triangle: " << endl;
	cout << "1 +\t " << "2   +\t " << "3 +++\t " << "4 +++\t " << endl;
	cout << "  ++\t " << "   ++\t " << "  ++\t " << "   ++\t " << endl;
	cout << "  +++\t " << "  +++\t " << "  +  \t " << "    +\t " << endl;
	cin >> n;

	switch (n)
	{
		case 1: 	cout << "Enter the length of the catheter " << endl; cin >> l;
					cout << "Enter symbol " << endl; cin >> s;
					h = l;
					for (i = 1; i <= h; i++)
					{
						for (j = 1; j <= l; j++)
							if (j >= k)
							{
								cout << " ";
							}
							else cout << s;

							cout << endl; k++;
					}
		break;
		case 2: 	cout << "Enter the length of the catheter " << endl; cin >> l;
					cout << "Enter symbol " << endl; cin >> s;
					h = l;
					k = l;
					for (i = 1; i <= h; i++)
					{
						for (j = 1; j <= l; j++)
							if (j < k)
							{
								cout << " ";
							}
							else cout << s;

							cout << endl; k--;
					}
					break;
		case 3: 	cout << "Enter the length of the catheter " << endl; cin >> l;
					cout << "Enter symbol " << endl; cin >> s;
					h = l;
					for (i = 1; i <= h; i++)
					{
						for (j = 1; j <= l; j++)
						
							cout << s; l--;
						
							cout << endl;
					}
					break;
		case 4: 	cout << "Enter the length of the catheter " << endl; cin >> l;
					cout << "Enter symbol " << endl; cin >> s;
					h = l;
					for (i = 1; i <= h; i++)
					{
						for (j = 1; j <= l; j++)
							if (j >= k) 
							{
								cout << s; 
							}
							else cout << " ";

							cout << endl; k++;
					}
			break;

		default: cout << "Incorrect choice!!!"; break;
	}

	system("pause");
}
