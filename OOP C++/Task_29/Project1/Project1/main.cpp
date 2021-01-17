#include "iostream"
#include "fstream"
#include "string"
#include "map"
#include "iterator"
using namespace std;

class Dictionary
{
	string word;
	string value;
public:
	Dictionary() { word = "a"; value = "Used when mentioning someone or something for the first time in a text or conversation."; }
	Dictionary(string word, string value) { this->word = word; this->value = value; }
	void SetWord(string word) { this->word = word; }
	void SetDefinition(string value) { this->value = value; }
	string GetWord() { return word; }
	string GetValue() { return value; }
	void Show() { cout << word << " - " << value << endl; }
	string AddWord()
	{
		cout << "Enter the word: ";
		getline(cin, word);
		return word;
	}
	string AddDefinition()
	{
		cout << "Enter the word value: ";
		getline(cin, value);
		return value;
	}
};

map<string, string> Add(map<string, string> ArrayWords)
{
	Dictionary temp;
	temp.SetWord(temp.AddWord());
	temp.SetDefinition(temp.AddDefinition());
	ArrayWords.insert(pair<string, string>(temp.GetWord(), temp.GetValue()));
	return ArrayWords;
}

map<string, string> Delete(map<string, string> ArrayWords)
{
	int pos;
	cout << "Enter the number of the word to be deleted" << endl;
	cin >> pos;
	cin.ignore();
	if (pos > 0 && pos <= ArrayWords.size())
	{
		map<string, string>::iterator it = ArrayWords.begin();
		advance(it, pos - 1);
		ArrayWords.erase(it);
	}
	else
	{
		cout << "Error! Incorrect position.";
	}
	return ArrayWords;
}

void Show(map<string, string> ArrayWords)
{
	map<string, string>::iterator it = ArrayWords.begin();
	cout << "\tDictionary" << endl;
	for (int i = 0; i < ArrayWords.size()-1; ++i)
	{
		cout << i + 1 << ". ";
		advance(it, i);
		cout << it->first << " - " << it->second << endl;
	}
	cout << endl;
}

map<string, string> Load()
{
	string tmp1;
	string tmp2;
	ifstream g;
	Dictionary tmp;
	map<string, string>ArrayWords;
	g.open("file.txt", ios_base::in);
	while (g.good())
	{
		getline(g, tmp1);
		getline(g, tmp2);
		if (tmp1.empty() == false && tmp2.empty() == false)
		{
			tmp.SetWord(tmp1);
			tmp.SetDefinition(tmp2);
			ArrayWords.insert(pair<string, string>(tmp.GetWord(), tmp.GetValue()));
		}
		//g.ignore();
	}
	g.close();
	return ArrayWords;
}

map<string, string> Edit(map<string, string> ArrayWords)
{
	int pos;
	cout << "Enter the number of the word to edit: ";
	cin >> pos;
	cin.ignore();
	if (pos > 0 && pos <= ArrayWords.size())
	{
		map<string, string>::iterator it = ArrayWords.begin();
		advance(it, pos - 1);
		Dictionary temp;
		temp.SetWord(temp.AddWord());
		temp.SetDefinition(temp.AddDefinition());
		ArrayWords[it->first] = temp.GetWord();
		ArrayWords[it->second] = temp.GetValue();
		ArrayWords.erase(it);
	}
	else
	{
		cout << "Error! Incorrect position.";
	}
	return ArrayWords;
}

void Save(map<string, string> ArrayWords)
{
	ofstream g;
	g.open("file.txt", ios_base::trunc);
	for (map<string, string>::iterator it = ArrayWords.begin(); it != ArrayWords.end(); ++it)
	{
		g << it->first << endl;
		g << it->second << endl;
	}
	g.close();
	cout << "Save complete" << endl;
}

int main()
{
	map <string, string> ArrayWords;
	ArrayWords = Load();

	int m = 1;
	while (m != 0)
	{
		cout << endl << "1. Add word\n2. Delete word\n3. Show dictionary\n4. Edit word\n0. Exit\n" << endl;
		cin >> m;
		if (m == 0)	break;
		else if (m == 1) ArrayWords = Add(ArrayWords);
		else if (m == 2) ArrayWords = Delete(ArrayWords);
		else if (m == 3) Show(ArrayWords);
		else if (m == 4) ArrayWords = Edit(ArrayWords);
		else	cout << "Error! Incorrect position." << endl << endl;
	}

	system("pause");
	return 0;
}