#include<bits/stdc++.h>
using namespace std;

double power(double x, int n){
    if(n == 0)
        return 1;
    double res = power(x, n / 2);

    if(n % 2 != 0)
        return x * res * res;
    else
        return res * res;
}

double nthGP(double f, double s, int n){
    double r = s / f;
    double a = f / r;

    return a * power(r, n - 1);
}

int main(){
    double t, f, s;
    int n;

    cin >> t;
    while(t--){
        cin >> f >> s >> n;
        cout << fixed << setprecision(3) << nthGP(f, s, n) << endl;
    }
    return 0;
}
