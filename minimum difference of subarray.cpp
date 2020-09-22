#include<bits/stdc++.h>
using namespace std;

int findDif(int ind, int c, int sum, int ts, int *arr, vector<vector<vector<int>>> &dp){
    if(ind < 0)
        return INT_MAX;
    if(c == 0)
        return abs(ts - 2 * sum);
    if(dp[ind][sum][c] != INT_MAX)
        return dp[ind][sum][c];
    cout << ind << " " << sum << " " << c << endl;
    return dp[ind][sum][c] = min(findDif(ind - 1, c - 1, sum - arr[ind], ts, arr, dp), findDif(ind - 1, c, sum, ts, arr, dp));
}

int solve(int *arr, int n){
    int sum = 0;

    for(int i = 0; i < n; i++)
        sum += arr[i];
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(sum + 1, vector<int>(n / 2 + 1, INT_MAX)));
    return findDif(n - 1, n / 2, sum, sum, arr, dp);
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
