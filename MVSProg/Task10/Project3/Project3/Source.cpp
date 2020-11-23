#include <iostream> 
using namespace std;

void main()
{
	double s1, s2, x1, x2, y1, y2;
	cout << "Enter the coordinates of the first point x ";
	cin >> x1;
	cout << "Enter the coordinates of the first point y ";
	cin >> y1;
	cout << "Enter the coordinates of the second point x ";
	cin >> x2;
	cout << "Enter the coordinates of the second point y ";
	cin >> y2;
	s1 = sqrt(x1*x1 + y1 * y1);
	s2 = sqrt(x2*x2 + y2 * y2);
	(s1 > s2) ? (cout << "1 point further 2" << endl) : (cout << "2 point further 1" << endl);
	system("pause");
}
