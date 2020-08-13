#include<bits/stdc++.h>
using namespace std;

void maxCom(string &s){
    int n = s.length(), res = 0, ind;
    vector<vector<int>> left(n, vector<int>(26, 0)), right(n, vector<int>(26, 0));

    left[0][s[0] - 'a'] = 1;
    right[n - 1][s[n - 1] - 'a'] = 1;
    for(int i = 1, j = n - 2; i < n; i++, j--){
        left[i][s[i] - 'a'] = 1;
        for(int k = 0; k < 26; k++)
            left[i][k] += left[i - 1][k];
        right[j][s[j] - 'a'] = 1;
        for(int k = 0; k < 26; k++)
            right[j][k] += right[j + 1][k];
    }
    for(int i = 0; i < n - 1; i++){
        int temp = 0;
        for(int j = 0; j < 26; j++){
            temp += min(left[i][j], right[i + 1][j]);
        }
        if(res < temp){
            res = temp;
            ind = i;
        }
    }
    cout << s.substr(0, ind + 1) << " " << s.substr(ind + 1, n - (ind + 1));
}

int main(){
    int t;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        maxCom(s);
        cout << endl;
    }
    return 0;
}
