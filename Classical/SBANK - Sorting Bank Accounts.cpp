#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t, n;

    cin >> t;
    while(t--)
    {
        cin >> n;
        cin.get();

        string *accounts = new string[n];

        for(int i=0; i<n; ++i)
            getline(cin, accounts[i]);

        sort(accounts, accounts+n);

        for(int i=0, rep=1; i<n; ++i)
        {
            if(i < n-1 && accounts[i] == accounts[i+1])
                ++rep;
            else{
                cout << accounts[i] << " " << rep << endl;
                rep = 1;
            }
        }

        delete[] accounts;
        cout << endl;
    }

    return 0;
}
