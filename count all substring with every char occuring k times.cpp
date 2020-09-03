#include<bits/stdc++.h>
using namespace std;

bool isValid(int *hash, int k){

    for(int i = 0; i < 10; i++)
        if(hash[i]){
            if(hash[i] != k)
                return false;
        }
    return true;
}

int solve(int k, string &s){
    int res = 0, n = s.length();

    for(int i = 0; i < n; i++){
        int hash[10] = {0};
        for(int j = i; j < n; j++){
            hash[s[j] - '0']++;
            if(isValid(hash, k)){
                res++;
            }
        }
    }
    return res;
}

int main(){
    int t, k;
    string s;

    cin >> t;
    while(t--){
        cin >> s >> k;
        cout << solve(k, s) << endl;
    }
    return 0;
}
