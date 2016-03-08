#include <iostream>
#include <cmath>
using namespace std;
     
int main() {
    int t;
    double u, v, w, U, V, W;
    double a, b, c, d, X, x, Y, y, Z, z;
    double vol;
     
    cin >> t;
    while(t--)
    {
        cin >> u >> v >> w >> W >> V >> U;
     
        X = (w-U+v)*(U+v+w);
        x = (U-v+w)*(v-w+U);
        Y = (u-V+w)*(V+w+u);
        y = (V-w+u)*(w-u+V);
        Z = (v-W+u)*(W+u+v);
        z = (W-u+v)*(u-v+W);
     
        a = sqrt(x*Y*Z);
        b = sqrt(y*Z*X);
        c = sqrt(z*X*Y);
        d = sqrt(x*y*z);
     
        vol = (sqrt((-a+b+c+d))*sqrt((a-b+c+d))*sqrt((a+b-c+d))*sqrt((a+b+c-d)))/(192.0*u*v*w);
        cout.precision(4);
        cout.setf(ios::fixed, ios::floatfield );
        cout << vol << endl;
     
    }
    
    return 0;
} 