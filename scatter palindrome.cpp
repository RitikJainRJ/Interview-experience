#include<bits/stdc++.h>
using namespace std;

bool isValid(int *hash){
    int res = 0;

    for(int i = 0; i < 26; i++)
        if(hash[i] % 2)
            res++;
    return res <= 1 ? true : false;
}

int solve(string &s){
    int res = 0, n = s.length();

    for(int i = 0; i < n; i++){
        int hash[26] = {0};
        for(int j = i; j < n; j++){
            hash[s[j] - 'a']++;
            if(isValid(hash))
                res++;
        }
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
