#include "iostream"
#include "stdio.h"
#include "string.h"
using namespace std;

struct Node
{
	char *AutoNum;
	Node *left, *right;
};

class DB_DAI
{
	Node *root;
public:
	DB_DAI() : root(NULL) {};
	~DB_DAI();
	void Add(char *AutoNum, char *offence);
	void FindAutoNum(char *AutoNum);
	void FindDiapason(char *AutoNumr1, char *AutoNum2);
	void Show();
	void Delete(Node *temp);
};

DB_DAI::~DB_DAI()
{
	Delete(root);
}

void DB_DAI::Add(char *AutoNum, char *offence)
{
	Node *temp = new Node;
	temp->right = NULL;
	temp->left = NULL;
	temp->AutoNum = new char[10];
	strcpy(temp->AutoNum, AutoNum);
	Node *temp2 = new Node;
	temp2->right = NULL;
	temp2->left = NULL;
	temp2->AutoNum = new char[256];
	strcpy(temp2->AutoNum, offence);
	if (root == NULL)
	{
		root = temp;
		root->left = temp2;
	}
	else
	{
		Node *temp3 = new Node;
		temp3 = root;
		while (temp3->right)
			temp3 = temp3->right;
		temp3->right = temp;
		temp->left = temp2;
	}
}

void DB_DAI::FindAutoNum(char * AutoNum)
{
	if (root == NULL) cout << "Database is EMPTY" << endl << endl;
	else
	{
		int count = 0;
		Node *temp = new Node;
		temp = root;
		while (temp)
		{
			if (strcmp(temp->AutoNum, AutoNum) == 0)
			{
				++count;
				if (count == 1) cout << "\t" << AutoNum << " have offence: " << endl;
				cout << count << ". " << temp->left->AutoNum << endl;
			}
			temp = temp->right;
		}
		if (count == 0) cout << "Not find offence" << endl << endl;
		else cout << endl;
	}
}

void DB_DAI::FindDiapason(char * AutoNum1, char * AutoNum2)
{
	int count = 0;
	Node *temp = new Node;
	temp = root;
	while (temp)
	{
		if (strcmp(temp->AutoNum, AutoNum1) >= 0 && strcmp(temp->AutoNum, AutoNum2) <= 0)
		{
			++count;
			if (count == 1) cout << "\t" << "Found numbers in this diapason" << endl;
			cout << count << ". " << temp->AutoNum << "\n   " << temp->left->AutoNum << endl;
		}
		temp = temp->right;
	}
	if (count == 0) cout << "Not find numbers" << endl << endl;
	else cout << endl;
}

void DB_DAI::Show()
{
	if (root == NULL) cout << "The database DAI is EMPTY" << endl << endl;
	else
	{
		int count = 0;
		Node *temp = new Node;
		temp = root;
		while (temp)
		{
			++count;
			cout << count << ". " << temp->AutoNum << "\n   " << temp->left->AutoNum << endl;
			temp = temp->right;
		}
		cout << endl;
	}
}

void DB_DAI::Delete(Node * temp)
{
	if (temp != NULL)
	{
		if (temp->left != NULL) Delete(temp->left);
		if (temp->right != NULL) Delete(temp->right);
		delete[]temp->AutoNum;
		temp = NULL;
	}
}

int main()
{
	DB_DAI dai;
	char *AutoNum = new char[10];
	char *offence = new char[256];
	int s = 1, m;
	while (s != 0)
	{
		cout << "Enter number:" << endl;
		cout << "\t1 - Fill up \n\t2 - Add new offence \n\t3 - Show \n\t4 - Offense by number \n\t5 - Offense by diapason \n\t0 - Quit" << endl;
		cin >> s;

		if (s == 1)
		{
			strcpy(AutoNum, "BX7777BC");
			strcpy(offence, "Violation of the rules of using the safety belt");
			dai.Add(AutoNum, offence);
			strcpy(AutoNum, "BX8769BC");
			strcpy(offence, "Violation of stop rules");
			dai.Add(AutoNum, offence);
			strcpy(AutoNum, "BX7777BC");
			strcpy(offence, "Driving a defective vehicle");
			dai.Add(AutoNum, offence);
			strcpy(AutoNum, "AA9876BC");
			strcpy(offence, "Violation of stop rules");
			dai.Add(AutoNum, offence);
			strcpy(AutoNum, "AA9876BC");
			strcpy(offence, "Driving a defective vehicle");
			dai.Add(AutoNum, offence);
		}
		else if (s == 2)
		{
			cin.get();
			cout << "Enter car number: ";
			gets_s (AutoNum,10);
			cout << "Enter offence: ";
			gets_s(offence,256);
			dai.Add(AutoNum, offence);
		}
		else if (s == 3)
		{
			dai.Show();
		}
		else if (s == 4)
		{
			cin.get();
			cout << "Enter car number: ";
			gets_s(AutoNum, 10);
			dai.FindAutoNum(AutoNum);
		}
		else if (s == 5)
		{
			char *AutoNum2 = new char[10];
			strcpy(AutoNum, "BX0000");
			strcpy(AutoNum2, "BX9999");
			dai.FindDiapason(AutoNum, AutoNum2);
		}
		else if (s == 2)
		{
			break;
		}
	}
	delete[]AutoNum;
	delete[]offence;
	system("pause");
	return 0;
}
