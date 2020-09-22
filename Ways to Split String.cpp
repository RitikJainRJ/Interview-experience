#include<bits/stdc++.h>
using namespace std;

int solve(string &s){
    unordered_map<char, int> um1, um2;
    int n = s.length(), res = 0;

    for(int i = n - 1; i > 0; i--)
        um2[s[i]]++;
    for(int i = 0; i < n - 1; i++){
        um1[s[i]]++;
        if(um1.size() == um2.size())
            res++;
        um2[s[i + 1]]--;
        if(um2[s[i + 1]] == 0)
            um2.erase(s[i + 1]);
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
