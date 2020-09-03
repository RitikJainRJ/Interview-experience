#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

int stoi(string s){
    int res = 0;

    for(int i = 0; i < s.length(); i++)
        res = res * 10 + (s[i] - '0');
    return res;
}

int splitPrime(string &s, bool *sieve){
    int n = s.length();
    int dp[n + 1];

    dp[0] = -1;
    for(int i = 1; i <= n; i++){
        dp[i] = INT_MAX;
        for(int j = 1; j <= i; j++){
            if(dp[j - 1] != INT_MAX && sieve[stoi(s.substr(j - 1, i - j))])
                dp[i] = min(dp[i], 1 + dp[j - 1]);
        }
    }
    return dp[n];
}

int main(){
    int t;
    string s;
    bool sieve[MAX + 1];

    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = false;
    for(int i = 2; i * i <= MAX; i++)
        if(sieve[i])
            for(int j = i * i; j <= MAX; j += i)
                sieve[j] = false;
    cin >> t;
    while(t--){
        cin >> s;
        cout << splitPrime(s, sieve) << endl;
    }
    return 0;
}
