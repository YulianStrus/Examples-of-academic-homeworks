#include "iostream"
#include "string"
using namespace std;

void Palindrom(string st)
{
	int count = 0;
	string temp;
	for (int i = 0; i < st.length(); ++i)
	{
		if (isalpha(st[i]))
			temp += st[i];
	}

	for (int i = 0; i < temp.length(); ++i)
		temp[i] = towlower(temp[i]);
	for (int i = 0; i < temp.length() / 2; ++i)
	{
		if (temp[i] == temp[temp.length() - 1 - i])
			++count;
	}
	if (count == temp.length() / 2) cout << st << " = palindrom" << endl << endl;
	else cout << st << " = not palindrom" << endl << endl;
}

void MaxMinWord(string st)
{
	string temp;
	string min;
	string max;
	int m = 0;
	for (int i = 0; i <= st.length(); ++i)
	{
		if (isalpha(st[i]))
			temp += st[i];
		else
		{
			if (temp.length() > m)
			{
				m = temp.length() - 1;
				max = temp;
			}
			temp.clear();
		}
	}
	cout << "Max word = " << max << endl;
	temp.clear();
	
	for (int i = 0; i <= st.length(); ++i)
	{
		if (isalpha(st[i]))
			temp += st[i];
		else
		{
			if (temp.length() < m && temp.length() != 0)
			{
				m = temp.length();
				min = temp;
			}
			temp.clear();
		}
	}
	cout << "min word = " << min << endl << endl;
}

void WithNumber(string st)
{
	int count = 0;
	string temp;
	for (int i = 0; i <= st.length(); ++i)
	{
		if (isalnum(st[i]))
			temp += st[i];
		else
		{
			for (int k = 0; k < temp.length(); ++k)
			{
				if (isdigit(temp[k]))
					++count;
			}
			if (count == 1) cout << temp << endl;
			temp.clear();
			count = 0;
		}
	}
	cout << endl;
}

void SameWords(string st)
{
	int count = 0;
	string temp, temp1;
	for (int i = 0; i <= st.length(); ++i)
	{
		if (isalpha(st[i]))
			temp += st[i];
		else
		{
			if (temp.empty()) continue;
			else break;
		}
	}
	for (int i = 0; i <= st.length(); ++i)
	{
		if (isalpha(st[i]))
			temp1 += st[i];
		else
		{
			if (temp1.length() == temp.length())
			{
				for (int k = 0; k < temp1.length(); ++k)
					if (tolower(temp1[k]) == tolower(temp[k])) count++;
			}
			if (count == temp1.length() && count != 0) cout << temp1 << endl;
			temp1.clear();
			count = 0;
		}
	}
	cout << endl;
}

int Compare(string st1, string st2)
{
	string temp1, temp2;
	temp1 = st1;
	temp2 = st2;
	for (int i = 0; i < temp1.length(); ++i)
		temp1[i] = tolower(temp1[i]);
	for (int i = 0; i < temp2.length(); ++i)
		temp2[i] = tolower(temp2[i]);
	return temp1.compare(temp2);
}

void SortWords(string st)
{
	int size = 0;
	string temp, temp2;
	for (int i = 0; i <= st.length(); ++i)
	{
		if (isalpha(st[i]))
			temp += st[i];
		else
		{
			if (temp.empty()) continue;
			++size;
			temp.clear();
		}
	}
	string *temp1 = new string[size];
	int count = 0;
	for (int i = 0; i <= st.length(); ++i)
	{
		if (isalpha(st[i]))
			temp += st[i];
		else
		{
			if (temp.empty()) continue;
			temp1[count] = temp;
			++count;
			temp.clear();
		}
	}
	for (int i = 0; i < size - 1; ++i)
	{
		for (int k = 0; k < size - 1 - i; ++k)
		{
			if (Compare(temp1[k], temp1[k + 1]) > 0)
				temp1[k].swap(temp1[k + 1]);
		}
	}
	for (int i = 0; i < size; ++i)
		cout << temp1[i] << endl;

}

void AllPalindrom(string st)
{
	int count = 0;
	string temp;
	for (int i = 0; i <= st.length(); ++i)
	{
		if (isalpha(st[i]))
			temp += st[i];
		else
		{
			if (temp.empty()) continue;
			for (int i = 0; i < temp.length() / 2; ++i)
			{
				if (tolower(temp[i]) == tolower(temp[temp.length() - 1 - i]))
					++count;
			}
			if (count == temp.length() / 2 && temp.length() != 1) cout << temp << endl;
			count = 0;
			temp.clear();
		}
	}
}

int main()
{
	string st = "Ab1e was I, ere I saw E1ba";
	cout << "\tPalindrom:" << endl;
	Palindrom(st);
	cout << "\tMax, min:" << endl;
	MaxMinWord(st);	
	cout << "\tWords with one number:" << endl;
	WithNumber(st);
	cout << "\tWords the same with first word"  << endl;
	SameWords(st);
	cout << "\tSort:" << endl;
	SortWords(st);
	cout << "\tPalindromic words:" << endl;
	AllPalindrom(st);
	
	system("pause");
	return 0;
}