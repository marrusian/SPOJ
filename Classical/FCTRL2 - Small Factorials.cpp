#include <iostream>
using namespace std;

int multiply(int x, int res[], int res_size)
{
	int carry = 0;
	int prod  = 0;
	
	for(int i=0; i < res_size; ++i)
	{
		prod   = res[i]*x + carry;
		res[i] = prod%10;
		carry  = prod/10;
	}
	
	while(carry)
	{
		res[res_size] = carry%10;
		carry /= 10;
		++res_size;
	}
	
	return res_size;
}

void factorial(int n)
{
	static constexpr int SIZE = 1024;

	int res[SIZE] = {1};
	int res_size  = 1;
	
	for(int i=2; i <= n; ++i)
		res_size = multiply(i, res, res_size);
	
	for(int i = res_size-1; i >= 0; --i)
		cout << res[i];
	cout << endl;
}

int main() {
	int t, n;
	
	cin >> t;
	while(t-- > 0){
		cin >> n;
		factorial(n);
	}

	return 0;
}