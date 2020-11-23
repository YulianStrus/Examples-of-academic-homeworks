#include <iostream>
using namespace std;

class Body
{
protected:
	char *typeB;
public:
	Body() { typeB = new char[20]; strcpy(this->typeB, "Sedan"); }
	Body(char* typeB) { this->typeB = new char[20]; strcpy(this->typeB, typeB); }
	~Body() { delete[]typeB; }
	void SetTypeB (char* type) { this->typeB = new char[20]; strcpy(this->typeB, typeB); }
	char *GetTypeB() { return typeB; }
	void ShowB() 
	{
		cout << "Car: \n\tBody: ";
		GetTypeB();
	}
};

class Engine
{
protected:
	char *typeE;
	double volumes;
public:
	Engine() { typeE = new char[20]; strcpy(this->typeE, "Gasoline"); volumes = 1997; }
	Engine(char* typeE, double volumes) { this->typeE = new char[20]; strcpy(this->typeE, typeE); this->volumes = volumes; }
	~Engine() { delete[]typeE; }
	void SetTypeE(char* typeE) { this->typeE = new char[20]; strcpy(this->typeE, typeE); }
	void SetVolumes(double volumes) { this->volumes = volumes; }
	char *GetTypeE() { return typeE; }
	double GetVolumes() { return volumes; }
	void ShowE()
	{
		cout << "\n\tEngine: ";
		GetTypeE();
		cout << "\n\tVolumes: ";
		GetVolumes();
	}
};

class Transmission
{
protected:
	char *typeT;
	int steps;
public:
	Transmission() { typeT = new char[20]; strcpy(this->typeT, "Stepped"); steps = 5; }
	Transmission(char* typeT, int steps) { this->typeT = new char[20]; strcpy(this->typeT, typeT); this->steps = steps; }
	~Transmission() { delete[]typeT; }
	void SetTypeT(char* typeT) { this->typeT = new char[20]; strcpy(this->typeT, typeT); }
	void SetSteps(int steps) { this->steps = steps; }
	char *GetTypeT() { return typeT; }
	int GetSteps() { return steps; }
	void ShowB()
	{
		cout << "\n\tTransmission: ";
		GetTypeT(); cout << " "; GetSteps(); cout << " steps";
	}
};

class Wheels
{
protected:
	int number;
	int diametr;
public:
	Wheels() { this->number = 4; diametr = 18; }
	Wheels(int number, int diametr) { this->number = number; this->diametr = diametr; }
	void SetNumber(int number) { this->number = number; }
	void SetDiametr(int diametr) { this->diametr = diametr; }
	int GetNumber() { return number; }
	int GetDiametr() { return diametr; }
	void ShowB()
	{
		cout << "\n\tWheels: ";
		GetNumber(); cout << " Diametr: "; GetDiametr(); cout << " in\n";
	}
};

class Car : public Body, public Engine, public Transmission, public Wheels
{
protected:
	char *brand;
	char *model;
public:
	Car(){ brand = new char[20]; strcpy(this->brand, "Ford");  model = new char[20]; strcpy(this->model, "Mondeo");}
	Car(char *brand, char *model) { brand = new char[20]; strcpy(this->brand, brand);  model = new char[20]; strcpy(this->model, model); }
	void SetBrand (char *brand) { brand = new char[20]; strcpy(this->brand, brand); }
	void SetModel(char *model) { model = new char[20]; strcpy(this->model, model); }
	char *GetBrand() { return brand; }
	char *GetModel() { return model; }
	void Show()
	{
		char *TB = new char[20];
		char *TE = new char[20];
		char *TT = new char[20];
		int S = GetSteps();
		int N = GetNumber();
		int D = GetDiametr();
		double V = GetVolumes();
		strcpy(TB, GetTypeB());
		strcpy(TE, GetTypeE());
		strcpy(TT, GetTypeT());
		cout << "Car: \t" << brand << " " << model;
		cout << "\n\tBody: "<< TB;
		cout << "\n\tEngine: " << TE << "; \t Volumes: " << V << " cm3";
		cout << "\n\tTransmission: " << TT << "; \t " << S << " steps";
		cout << "\n\tWheels: "<< N << "; \t Diametr: "<< D << " inch\n";
	}
};

int main()
{
	Car Auto1;
	Auto1.Show();

	system("pause");
	return 0;
}