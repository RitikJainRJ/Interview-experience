#include<bits/stdc++.h>
using namespace std;

int solve(int m, int n){
    vector<vector<int>> inter(n);
    vector<int> dp(n);

    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        inter[i] = {a, b, c};
    }
    sort(inter.begin(), inter.end());
    dp[0] = inter[0][2];
    for(int i = 1; i < n && inter[i][1] <= m; i++){
        dp[i] = inter[i][2];
        for(int j = 0; j < i; j++){
            if(inter[j][1] + 4 < inter[i][0] && dp[j] + inter[i][2] > dp[i])
                dp[i] = inter[i][2] + dp[j];
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main(){
    int t, m, n;

    cin >> t;
    while(t--){
        cin >> m >> n;
        cout << solve(m, n) << endl;
    }
    return 0;
}
