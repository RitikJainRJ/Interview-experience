#include<bits/stdc++.h>
using namespace std;

int MaxSum(int *arr, int n){
    unordered_map<int, int> um;
    int i = 0, j, sum = 0, res = 0;

    for(j = 0; j < n; j++){
        um[arr[j]]++;
        sum += arr[j];

        if(um[arr[j]] != 1){
            while(arr[i] != arr[j]){
                um[arr[i]]--;
                sum -= arr[i];
                i++;
            }
            um[arr[i]]--;
            sum -= arr[i];
            i++;
        }
        res = max(res, sum);
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
        cout << MaxSum(arr, n) << endl;
    }
    return 0;
}
