#include "iostream"
using namespace std;
template <typename T>T ProdNum (T a, T b){
	return a * b;}int main(){
	double a, b;
	cout << "Enter two number: " << endl;	cin >> a;	cin >> b;	cout << ProdNum(a, b) << endl;	system("pause");}