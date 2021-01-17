#include "iostream"
using namespace std;

int main()
{
	char str[128];
	cout << "Enter string: ";
	gets_s(str);
	cout << "String: " << str << endl;
	char *p = strtok(str, ".,!? ");
	while (p != NULL)
	{
		int n = strlen(p);
		int W = 0;
		for (int i=0; i<n; i++)
			if ((p[i] >= 48)&(p[i] <= 57)) W++;
		if (W == 1) cout << p << endl;
		p = strtok(NULL, ".,!? ");
	}	


	system("pause");
	return 0;
}