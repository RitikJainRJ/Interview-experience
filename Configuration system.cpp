#include<bits/stdc++.h>
using namespace std;

int binary_search(int l, int r, int x, int *arr){
    int m;

    while(l <= r){
        m = (l + r) / 2;
        if(arr[m] <= x)
            l = m + 1;
        else
            r = m - 1;
    }
    return r + 1;
}

int main(){
    int n, s0, k, b, m, a, res = 0;

    cin >> n >> s0 >> k >> b >> m >> a;
    int arr[n];

    arr[0] = s0;
    for(int i = 1; i < n; i++)
        arr[i] = ((k * arr[i - 1] + b) % m) + 1 + arr[i - 1];

    for(int i = 0; i < n; i++)
        res += binary_search(0, n - 1, a / arr[i], arr);
    cout << res << endl;
    return 0;
}
