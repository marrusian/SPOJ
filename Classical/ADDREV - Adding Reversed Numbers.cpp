// Variant for very big numbers (to prevent overflowing)

#include <iostream>
using namespace std;
 
void reverse_add(int num1[], int num2[], int num_sz)
{
    int carry = 0;
    int sum   = 0;
 
    int *res = new int[num_sz+1];
 
    int i;
    for(i=0; i < num_sz; ++i)
    {
        sum    = num1[i] + num2[i] + carry;
        res[i] = sum%10;
        carry  = sum/10;
    }
 
    int res_sz = carry? num_sz+1 : num_sz;
    res[i] = carry;
 
    // Skip trailing zeroes
    for(i=0; !res[i]; ++i)
        continue;
 
    for(i; i<res_sz; ++i)
        cout << res[i];
    cout << endl;
}
 
int num_length(int num)
{
    int length = 0;
 
    while(num){
        ++length;
        num /= 10;
    }
 
    return length;
}
 
void num_to_array(int num, int num_sz, int arr[], int arr_sz)
{
    for(int i = num_sz-1; i >= 0; --i){
        arr[i] = num%10;
        num   /= 10;
    }
 
    for(int i = num_sz; i < arr_sz; ++i)
        arr[i] = 0;
}
 
int main() {
    int t, a, b;
 
    cin >> t;
    while(t--){
        cin >> a >> b;
 
        int a_sz   = num_length(a);
        int b_sz   = num_length(b);
        int max_sz = max(a_sz, b_sz);
 
        int *arra = new int[max_sz];
        int *arrb = new int[max_sz];
 
        num_to_array(a, a_sz, arra, max_sz);
        num_to_array(b, b_sz, arrb, max_sz);
 
        reverse_add(arra, arrb, max_sz);
 
        delete[] arra;
        delete[] arrb;
    }
 
    return 0;
}

// ------------------------------------------------------------------------------------
// Assuming a+b < 2^(sizeof(unsigned) * 8)
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

unsigned int rev(unsigned int num)
{
    unsigned int rv = 0;
    
    while(num){
        rv   = rv*10 + num%10;
        num /= 10;
    }
    
    return rv;    
}

unsigned int length(unsigned int num)
{
    unsigned int lgth = 0;
    while(num){
        ++lgth;
        num /= 10;
    }
    
    return lgth? lgth : 1;
}

unsigned int trail(unsigned int a, unsigned int b, unsigned int sum)
{
    unsigned int lgth_a = length(a), lgth_b = length(b);

	if(lgth_a != length(rev(a)) || lgth_b != length(rev(b))){
        auto mima = minmax(lgth_a, lgth_b);
	    sum *= pow(10.0, mima.second - mima.first);
    }
    
    return sum;
}

int main() {
    int t;
    unsigned int a, b, reva, revb;

    cin >> t;
    while(t--){
        cin >> a >> b; 
        cout << trail(a, b, rev(rev(a) + rev(b))) << endl; 
    }

    return 0;
}