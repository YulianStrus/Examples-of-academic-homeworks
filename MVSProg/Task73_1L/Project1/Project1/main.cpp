#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>

using namespace std;

class Car
{
	char *brend;
	char *model;
	int year;
	int volume;
	int price;
public:
	Car() { brend = new char[20]; strcpy(brend, "Opel"); model = new char[20]; strcpy (model, "Astra"); year = 1999; volume = 2000; price = 3500; }
	Car(char* brend, char* model, int year, int volume, int price)
	{
		this->brend = new char[20];
		this->model = new char[20];
		strcpy(this->brend, brend);
		strcpy(this->model, model);
		this->year = year;
		this->volume = volume;
		this->price = price;
	}
	Car(const Car&other)
	{
		this->brend = new char[20];
		this->model = new char[20];
		strcpy(this->brend, other.brend);
		strcpy(this->model, other.model);
		this->year = other.year;
		this->volume = other.volume;
		this->price = other.price;
	}
	Car operator=(const Car&other)
	{
		this->brend = new char[20];
		this->model = new char[20];
		strcpy(this->brend, other.brend);
		strcpy(this->model, other.model);
		this->year = other.year;
		this->volume = other.volume;
		this->price = other.price;
		return *this;
	}
	void SetBrend(char *brend) { this->brend = new char[20]; strcpy(this->brend, brend); }
	void SetModel(char *model) { this->model = new char[20]; strcpy(this->model, model); }
	void SetYear(int year) { this->year = year; }
	void SetVolume(int volume) { this->volume = volume; }
	void SetPrice(int price) { this->price = price; }
	char *GetBrend() { return brend; }
	char *GetModel() { return model; }
	int GetYear() { return year; }
	int GetVolume() { return volume; }
	int GetPrice() { return price; }
	char *AddBrand()
	{
		cin.ignore();
		cout << "Enter brend: ";
		cin.getline(brend, 20);
		return brend;
	}
	char *AddModel()
	{
//		cin.ignore();
		cout << "Enter model: ";
		cin.getline(model, 20);
		return model;
	}
	int AddYear()
	{
		cout << "Enter year: ";
		cin >> year;
		return year;
	}
	int AddVolume()
	{
		cout << "Enter volume: ";
		cin >> volume;
		return volume;
	}
	int AddPrice()
	{
		cout << "Enter price: ";
		cin >> price;
		return price;
	}
	void Show()
	{
		cout << "\tBrend:\t" << brend << endl;
		cout << "\tModel:\t" << model << endl;
		cout << "\tYear:\t" << year << endl;
		cout << "\tVolume:\t" << volume << " m3" << endl;
		cout << "\tPrice:\t" << price << " $" << endl;
	}
};

void Save(vector <Car> ArrayCar)
{
	ofstream g;
	g.open("file.txt", ios_base::trunc);
	for (int i = 0; i < ArrayCar.size(); ++i)
	{
		g << ArrayCar[i].GetBrend() << endl;
		g << ArrayCar[i].GetModel() << endl;
		g << ArrayCar[i].GetYear() << endl;
		g << ArrayCar[i].GetVolume() << endl;
		g << ArrayCar[i].GetPrice() << endl;
	}
	g.close();
	cout << "Save complete" << endl;
}

vector <Car> Add(vector <Car> ArrayCar)
{
	Car temp;
	temp.SetBrend(temp.AddBrand());
	temp.SetModel(temp.AddModel());
	temp.SetYear(temp.AddYear());
	temp.SetVolume(temp.AddVolume());
	temp.SetPrice(temp.AddPrice());
	ArrayCar.push_back(temp);
	cin.ignore();
	return ArrayCar;
}

vector <Car> Delete(vector <Car> ArrayCar)
{
	int num;
	cout << "Enter number: ";
	cin >> num;
	if (num > 0 && num <= ArrayCar.size())
		ArrayCar.erase(ArrayCar.begin() + num - 1);
	else cout << "Error! Incorect number" << endl;
	ArrayCar = Delete(ArrayCar);
	return ArrayCar;
}

void Show(vector<Car>ArrayCar)
{
	cout << "Motor show:\n" << endl;
	for (int i = 0; i < ArrayCar.size(); ++i)
	{
		cout << i + 1 << ". ";
		ArrayCar[i].Show();
		cout << endl;
	}
	cout << endl;
}

vector<Car> Load()
{
	int count = 0;
	char *buf = new char[100];
	double double_buf;
	ifstream g;
	Car temp;
	g.open("file.txt", ios_base::in);
	while (g.good())
	{
		g.getline(buf, sizeof(char[100]));
		temp.SetBrend(buf);
		g.getline(buf, sizeof(char[100]));
		temp.SetModel(buf);
		g >> double_buf;
		temp.SetYear(double_buf);
		g >> double_buf;
		temp.SetVolume(double_buf);
		g >> double_buf;
		temp.SetPrice(double_buf);
		g.ignore();

		++count;
	}
	vector<Car>AutoSalon(count);
	g.close();
	if (AutoSalon.size() == 0)
	{
		cout << "Not car in autosalon yet.\nPlease enter information about the first car." << endl;
		AutoSalon = Add(AutoSalon);
	}
	else
	{
		g.open("file.txt", ios_base::in);
		for (int i = 0; i < AutoSalon.size(); ++i)
		{
			g.getline(buf, sizeof(char[100]));
			AutoSalon[i].SetBrend(buf);
			g.getline(buf, sizeof(char[100]));
			AutoSalon[i].SetModel(buf);
			g >> double_buf;
			AutoSalon[i].SetYear(double_buf);
			g >> double_buf;
			AutoSalon[i].SetVolume(double_buf);
			g >> double_buf;
			AutoSalon[i].SetPrice(double_buf);
			g.ignore();
		}
		//cin.ignore();
		g.close();
	}
	delete[]buf;
	return AutoSalon;
}


//-----------------------------------------------
void SortByBrend(vector<Car> ArrayCar)
{
	vector<Car>tmp(ArrayCar);
	Car tmp1;
	for (int i = 0; i < tmp.size() - 1; ++i)
	{
		for (int k = 0; k < tmp.size() - i - 1; ++k)
		{
			if (strcmp(tmp[k].GetBrend(), tmp[k + 1].GetBrend()) > 0)
			{
				tmp1 = tmp[k];
				tmp[k] = tmp[k + 1];
				tmp[k + 1] = tmp1;
			}
		}
	}
	Show(tmp);
}

void SortByModel(vector<Car> ArrayCar)
{
	vector<Car>tmp(ArrayCar);
	Car tmp1;
	for (int i = 0; i < tmp.size() - 1; ++i)
	{
		for (int k = 0; k < tmp.size() - i - 1; ++k)
		{
			if (strcmp(tmp[k].GetModel(), tmp[k + 1].GetModel()) > 0)
			{
				tmp1 = tmp[k];
				tmp[k] = tmp[k + 1];
				tmp[k + 1] = tmp1;
			}
		}
	}
	Show(tmp);
}

void SortByYear(vector<Car> ArrayCar)
{
	vector<Car>tmp(ArrayCar);
	Car tmp1;
	for (int i = 0; i < tmp.size() - 1; ++i)
	{
		for (int k = 0; k < tmp.size() - i - 1; ++k)
		{
			if (tmp[k].GetYear() > tmp[k + 1].GetYear())
			{
				tmp1 = tmp[k];
				tmp[k] = tmp[k + 1];
				tmp[k + 1] = tmp1;
			}
		}
	}
	Show(tmp);
}

void SortByVolume(vector<Car> ArrayCar)
{
	vector<Car>tmp(ArrayCar);
	Car tmp1;
	for (int i = 0; i < tmp.size() - 1; ++i)
	{
		for (int k = 0; k < tmp.size() - i - 1; ++k)
		{
			if (tmp[k].GetVolume() > tmp[k + 1].GetVolume())
			{
				tmp1 = tmp[k];
				tmp[k] = tmp[k + 1];
				tmp[k + 1] = tmp1;
			}
		}
	}
	Show(tmp);
}

void SortByPrice(vector<Car> ArrayCar)
{
	vector<Car>tmp(ArrayCar);
	Car tmp1;
	for (int i = 0; i < tmp.size() - 1; ++i)
	{
		for (int k = 0; k < tmp.size() - i - 1; ++k)
		{
			if (tmp[k].GetPrice() > tmp[k + 1].GetPrice())
			{
				tmp1 = tmp[k];
				tmp[k] = tmp[k + 1];
				tmp[k + 1] = tmp1;
			}
		}
	}
	Show(tmp);
}

void FindByBrend(vector<Car> ArrayCar)
{
	char brend[20];
	int count = 0;
	int count_tmp = 0;
	cout << "Enter brend: ";
	gets_s(brend, 20);
	for (int i = 0; i < ArrayCar.size(); ++i)
	{
		for (int k = 0; k < strlen(brend); ++k)
		{
			if (brend[k] == ArrayCar[i].GetBrend()[k])
				count++;
		}
		if (count == strlen(brend))
		{
			count_tmp++;
			cout << i + 1 << ". ";
			ArrayCar[i].Show();
			cout << endl;
		}
		count = 0;
	}
	if (count_tmp == 0) cout << "Error! There is no match" << endl << endl;
}

void FindByModel(vector<Car> ArrayCar)
{
	char model[20];
	int count = 0;
	int count_tmp = 0;
	cout << "Enter model: ";
	gets_s(model, 20);
	for (int i = 0; i < ArrayCar.size(); ++i)
	{
		for (int k = 0; k < strlen(model); ++k)
		{
			if (model[k] == ArrayCar[i].GetModel()[k])
				count++;
		}
		if (count == strlen(model))
		{
			count_tmp++;
			cout << i + 1 << ". ";
			ArrayCar[i].Show();
			cout << endl;
		}
		count = 0;
	}
	if (count_tmp == 0) cout << "Error! There is no match" << endl << endl;
}

void FindByYear(vector<Car> ArrayCar)
{
	int year;
	int count = 0;
	cout << "Enter year: ";
	cin >> year;
	for (int i = 0; i < ArrayCar.size(); ++i)
	{
		if (year == ArrayCar[i].GetYear())
		{
			count++;
			cout << i + 1 << ". ";
			ArrayCar[i].Show();
			cout << endl;
		}
	}
	if (count == 0) cout << "Error! There is no match" << endl << endl;
}

void FindByVolume(vector<Car> ArrayCar)
{
	double volume;
	int count = 0;
	cout << "Enter volume of engine: ";
	cin >> volume;
	for (int i = 0; i < ArrayCar.size(); ++i)
	{
		if (volume == ArrayCar[i].GetVolume())
		{
			count++;
			cout << i + 1 << ". ";
			ArrayCar[i].Show();
			cout << endl;
		}
	}
	if (count == 0) cout << "Error! There is no match" << endl << endl;
}

void FindByPrice(vector<Car> ArrayCar)
{
	double price;
	int count = 0;
	cout << "Enter price: ";
	cin >> price;
	for (int i = 0; i < ArrayCar.size(); ++i)
	{
		if (price == ArrayCar[i].GetPrice())
		{
			count++;
			cout << i + 1 << ". ";
			ArrayCar[i].Show();
			cout << endl;
		}
	}
	if (count == 0) cout << "Error! There is no match" << endl << endl;
}


int main()
{
	vector<Car>MotorShow;
	MotorShow = Load();
	int m=1;
	while (m!=0)
	{
		cout << "1. Add car\n2. Delete car\n3. Show cars\n4. Sort by\n5. Searching by\n6. Download from file\n7. Save to file\n0. Exit" << endl;
		cin >> m;
		if (m==0) break;
		else if (m==1) MotorShow = Add(MotorShow);
		else if (m == 2) MotorShow = Delete(MotorShow);
		else if (m == 3) Show(MotorShow);
		else if (m == 4) 
		{
			int ms = 1;
			while (ms != 0)
			{
				cout << "1. By brend\n2. By model\n3. By year\n4. By volume\n5. By price\n0. Back" << endl;
				cin >> ms;
				if (ms == 0) break;
				else if (ms == 1) SortByBrend(MotorShow);
				else if (ms == 2) SortByModel(MotorShow);
				else if (ms == 3) SortByYear(MotorShow);
				else if (ms == 4) SortByVolume(MotorShow);
				else if (ms == 5) SortByPrice(MotorShow);
				else cout << "Error! Incorrect select." << endl << endl;
			}
		}
		else if (m == 5)
		{
			int mf=1;
			while (mf!=0)
			{
			cout << "1. By brend\n2. By model\n3. By year\n4. By volume\n5. By price\n0. Back" << endl;
			cin >> mf;
			if (mf==0) break;
			else if (mf == 1) FindByBrend(MotorShow);
			else if (mf == 2) FindByModel(MotorShow);
			else if (mf == 3) FindByYear(MotorShow);
			else if (mf == 4) FindByVolume(MotorShow);
			else if (mf == 5) FindByPrice(MotorShow);
			else cout << "Error! Incorrect select." << endl << endl;
			}
		}
		else if (m == 6) MotorShow = Load();
		else if (m == 7) Save(MotorShow);
		else cout << "Error! Incorrect select" << endl << endl;
	}

	system("pause");
	return 0;
}