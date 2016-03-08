#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t, N;
	int fz, z;
	double i;

	cin >> t;
	while(t--)
	{	
		z  = 1;
		fz = 0;
		i  = 1.0;
		cin >> N;

		while(z){
			z = N / pow(5.0, i++);
			fz += z;
		}
		cout << fz << endl;
	}
	return 0;
}