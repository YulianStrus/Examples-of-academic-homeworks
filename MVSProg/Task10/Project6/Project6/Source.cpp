#include "iostream"
using namespace std;
void main()
{
	double V1, V2, V3, N, Z, Y, St, S;
	cout << "Enter the speed of the ship " << endl;
	cin >> V1;
	cout << "Enter the speed of the tourist " << endl;
	cin >> V2;
	cout << "Enter travel time for the tourist " << endl;
	cin >> N;
	cout << "Enter the return speed of the tourist " << endl;
	cin >> V3;
	cout << "Enter the time between boat stops " << endl;
	cin >> Y;
	cout << "Enter the stopping time of the boat " << endl;
	cin >> Z;
	S = (V1 + V2)*N;
	St = (V3 - V1)*(Y - N + Z);
	(St >= S) ? cout << "The tourist will have time to land on a motor ship" << endl : cout << "The tourist will not have time to get on the boat" << endl;
	system("pause");
}
