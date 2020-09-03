#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    int res = 0, i = 0;

    for(int i = 0; i < n; i++)
        pq.push(arr[i]);
    while(!pq.empty() && i < n - 1){
        int a = pq.top();
        pq.pop();
        if(pq.empty())
            break;
        int b = pq.top();
        pq.pop();
        res += (a + b);
        pq.push(a + b - 1);
    }
    return res;
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << solve(arr, n) << endl;
    }
    return 0;
}
