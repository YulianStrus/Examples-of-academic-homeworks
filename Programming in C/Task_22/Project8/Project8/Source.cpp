#include <iostream>
using namespace std;
int main()
{
	char s[128];
	char c;
	cout << "Enter string: ";
	gets_s(s);
	cout << "Enter symbol: ";
	cin >> c;

	int i = 0;
	int j = i;

	while (s[i])
	{
		if (s[i] != c)
			s[j++] = s[i];
		i++;
	}

	s[j] = '\0';

	cout << s << endl;

	system("pause");
	return 0;

}