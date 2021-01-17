#include "iostream"
using namespace std;

int main()
{
	char str[128];
	cout << "Enter string: ";
	gets_s(str);
	cout << "String: " << str << endl;
	int W = 0;
	char *p = strtok(str, ".,!? ");
	char *p_min[20], *p_max[20];
	int min = 50, max=0, tmp;
	while (p != NULL)
	{
		tmp = strlen(p);
		if (tmp < min) { min = tmp; *p_min = p; }
		if (tmp > max) { max = tmp; *p_max = p; }
		p = strtok(NULL, ".,!? ");
	}
	cout << "Min word = " << *p_min << endl;
	cout << "Max word = " << *p_max << endl;


	system("pause");
	return 0;
}