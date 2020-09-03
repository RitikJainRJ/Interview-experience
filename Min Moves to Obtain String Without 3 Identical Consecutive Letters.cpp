#include<bits/stdc++.h>
using namespace std;

int solve(string &s){
    int n = s.length();

    for(int i = 0; i < n; i++){
        int count = 1;
        while(i + 1 < n && s[i] == s[i + 1])
            count++;
        res += count / 3;
    }
    return res;
}

int main(){
    int t;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
