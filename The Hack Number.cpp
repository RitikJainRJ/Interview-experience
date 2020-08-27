#include<bits/stdc++.h>
using namespace std;

void fillLps(string &s, int *lps, int n){
    int i = 1, l = 0;

    lps[0] = 0;
    while(i < n){
        if(s[i] == s[l]){
            l++;
            lps[i] = l;
            i++;
        }
        else{
            if(l != 0)
                l = lps[l - 1];
            else
                lps[i] = 0, i++;
        }
    }
}

void solve(string &s1, string &s2, char c, int k){
    int n = s1.length(), m = s2.length();
    int lps[m];

    fillLps(s2, lps, m);
    int i = 0, j = 0;
    while(i < n){
        if(s1[i] == s2[j])
            i++, j++;
        if(j == m){

        }
    }
}

int main(){
    int t, k;
    string s1, s2;
    char c;

    cin >> t;
    while(t--){
        cin >> s1 >> s2 >> c >> k;
        solve(s1, s2, c, k);
        cout << endl;
    }
    return 0;
}
