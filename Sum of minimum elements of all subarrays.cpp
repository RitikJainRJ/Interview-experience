#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n){
    int left[n], right[n];
    stack<int> s;
    int i, res = 0;

    i = 0;
    while(i < n){
        if(s.empty() || arr[s.top()] <= arr[i])
            s.push(i++);
        else{
            int t = s.top();
            s.pop();
            right[t] = i - t;
        }
    }
    while(!s.empty()){
        int t = s.top();
        s.pop();
        right[t] = i - t;
    }
    i = n - 1;
    while(i >= 0){
        if(s.empty() || arr[s.top()] <= arr[i])
            s.push(i--);
        else{
            int t = s.top();
            s.pop();
            left[t] = t - i;
        }
    }
    while(!s.empty()){
        int t = s.top();
        s.pop();
        left[t] = t - i;
    }
    for(int i = 0; i < n; i++){
        res += (arr[i] * left[i] * right[i]);
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
