#include<bits/stdc++.h>
using namespace std;

int scatterPal(string &s){
    int n = s.length(), res = 0;
    unordered_map<int, int> um;

    um[0] = 1;
    int x = 0;
    for(int i = 0; i < s.length(); i++){
        x ^= 1 << (s[i] - '0');
        res += um[x];
        for(int j = 0; j < 26; j++)
            res += um[x ^ (1 << j)];
        um[x] += 1;
    }
    return res;
}

int main(){
    int t;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        cout << scatterPal(s) << endl;
    }
    return 0;
}
