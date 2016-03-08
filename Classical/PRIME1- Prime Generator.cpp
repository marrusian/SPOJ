#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<bool> soe(int n)
{
    const int SIZE = n+1;
    const int LIM  = sqrt(SIZE);

    vector<bool> arr(SIZE);

    for(int i=2; i<=LIM; ++i)
        if(!arr[i])
            for(int j=i*i; j<SIZE; j+=i)
                arr[j] = true;

    return arr;
}

vector<bool> offset_soe(int lower, int upper)
{
    if(lower != 1) --lower;
    ++upper;
    const int LENGTH = upper-lower;

    vector<bool> sieve  = soe(sqrt(upper));
    vector<bool> seg_sieve(LENGTH);

    for(int k=2, offset, lim = sieve.size(); k<lim; ++k)
        if(!sieve[k])
        {
            offset = k - (lower % k);
            while(offset < LENGTH){
                if(lower+offset != k)
                    seg_sieve[offset] = true;
                offset += k;
            }
        }

    return seg_sieve;
}

void show_primes(int lower, int upper)
{
    vector<bool> primes = offset_soe(lower, upper);

    int base = lower==1? lower : lower-1;
    for(int i=1, lim = primes.size(); i<lim; ++i)
        if(!primes[i])
            cout << base + i << endl;
}

int main(void)
{
	int t;
    int a,b;

    cin >> t;
    while(t--)
    {
    	cin >> a >> b;
    	show_primes(a,b);
    	cout << endl;
	}

    return 0;
}