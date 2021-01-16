#include "iostream"
using namespace std;
int main()
{
	int k, x1, y1, x2, y2;
	cout << "Enter a chess shape number\n1 - Tour\n2 - Elephant\n3 - Horse" << endl;
	cin >> k;
	if ((k != 1) && (k != 2) && (k != 3)) 
		cout << "Incorrect data entered" << endl;
	else {
		cout << "Enter the chess shape coordinates \"x\" (from 1 to 8)\n";
		cin >> x1;
		if (1 > x1); else if (x1 > 8)
			cout << "Incorrect data entered" << endl;
		else {
			cout << "Enter the chess shape coordinates \"y\" (from 1 to 8)\n";
			cin >> y1;
			if (1 > y1); else if (y1 > 8)
				cout << "Incorrect data entered" << endl;
			else {
				cout << "Enter the coordinates of the opponent's chess shape \"x\" (1 to 8)\n";
				cin >> x2;
				if (1 > x2); else if (x2 > 8)
					cout << "Incorrect data entered" << endl;
				else {
					cout << "Enter the coordinates of the opponent's chess shape \"y\" (1 to 8)\n";
					cin >> y2;
					if (1 > y2); else if (y2 > 8)
						cout << "Incorrect data entered" << endl;
					if (k == 1) {
						if ((x1 == x2) || (y1 == y2)) cout << "Yes!" << endl;
						else cout << "No!" << endl;
					}
					if (k == 2) {
						if ((x1 + y1 == x2 + y2) || (x1 - y1 == x2 - y2)) cout << "Yes!" << endl;
						else cout << "No!" << endl;
					}
					if (k == 3) {
						if ((x1 - x2) + (y1 - y2) == 3) cout << "Yes!" << endl;
						else cout << "No!" << endl;
					}
				
						
					
				}
			}
		}
	}
	system("pause");
	return 0;
}