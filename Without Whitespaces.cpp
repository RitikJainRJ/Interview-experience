#include<bits/stdc++.h>
using namespace std;

int stoi(string &temp){
    int res = 0;
    for(int i = 0; i < temp.size(); i++)
        res = res * 10 + (temp[i] - '0');
    return res;
}

int main(){
    int n, c, k;
    string s;

    cin >> n >> c >> k;
    int dp[n + 1];
    int MAX = pow(10, k);
    cin >> s;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        for(int j = i - 1; j >= 0; j--){
            string temp = s.substr(j, i - j);
            int x = stoi(temp);
            if(temp[0] != '0' && x <= c)
                dp[i] = (dp[i] + dp[j]) % MAX;
            else if(x > c)
                break;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
