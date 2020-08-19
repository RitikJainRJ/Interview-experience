#include<bits/stdc++.h>
using namespace std;

void solve(string &s, int k){
    int hash[26] = {0};
    unordered_set<string> us;
    int n = s.length();

    int i = 0, j;
    for(j = 0; j < n; j++){
        hash[s[j] - 'a']++;
        if(hash[s[j] - 'a'] != 1){
            while(s[i] != s[j]){
                hash[s[i] - 'a']--;
                i++;
            }
            hash[s[i] - 'a']--;
            i++;
        }
        if(j - i + 1 > k){
            hash[s[i] - 'a']--;
            i++;
        }
        if(j - i + 1 == k)
            us.insert(s.substr(i, j - i + 1));
    }
    for(auto it = us.begin(); it != us.end(); it++)
        cout << *it << " ";
}

int main(){
    int t, k;
    string s;

    cin >> t;
    while(t--){
        cin >> s >> k;
        solve(s, k);
        cout << endl;
    }
    return 0;
}
