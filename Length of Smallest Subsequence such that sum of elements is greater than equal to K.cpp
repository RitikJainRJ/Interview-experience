#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0, sum = 0, res = INT_MAX;

    while(i < n){
        if(sum < k){
            pq.push(arr[i]);
            sum += arr[i];
            i++;
        }
        else{
            res = min(res, (int)pq.size());
            sum -= pq.top();
            pq.pop();
        }
    }
    return res == INT_MAX ? -1 : res;
}

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << solve(arr, n, k) << endl;
    }
    return 0;
}
