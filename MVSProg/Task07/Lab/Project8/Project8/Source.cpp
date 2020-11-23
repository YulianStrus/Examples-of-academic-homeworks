#include "iostream"
using namespace std;
void main()
{
	float a, b;
	cout << "Input digit ";
	cin >> a;
	cout << "Input the degree of the number (from 0 to 7) ";
	cin >> b;
	if (b == 0) cout << "1" << endl; else
		if (b == 1) cout << a << endl; else
			if (b == 2) cout << a*a << endl; else
				if (b == 3) cout << a * a * a << endl; else
					if (b == 4) cout << a * a * a * a << endl; else
						if (b == 5) cout << a * a * a * a * a << endl; else
							if (b == 6) cout << a * a * a * a * a * a << endl; else
								if (b == 7) cout << a * a * a * a * a * a * a << endl;
	system("pause");
}
