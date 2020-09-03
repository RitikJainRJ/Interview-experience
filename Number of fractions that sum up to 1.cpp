#include<bits/stdc++.h>
using namespace std;

int solve(int *x, int *y, int n){
    unordered_map<double, int> um;
    int res = 0;

    for(int i = 0; i < n; i++){
        double t = 1 - ((double)x[i] / y[i]);
        cout << t << " ";
        if(um.find(t) != um.end())
            res += um[t];
        um[(double)x[i] / y[i]]++;
    }
    return res;
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int x[n], y[n];

        for(int i = 0; i < n; i++)
            cin >> x[i];
        for(int i = 0; i < n; i++)
            cin >> y[i];
        cout << solve(x, y, n) << endl;
    }
    return 0;
}
