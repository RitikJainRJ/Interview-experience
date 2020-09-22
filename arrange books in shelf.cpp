/*
1
11
Mike Bill Bill Mike David Mike Mike Bill Mike Bill Bill
WE D IE WE IOI DS IM IE DS IE IE
4 3
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<string>> &mat, int x, int y){
    map<string, int> om1;
    map<vector<string>, int> om2;

    for(int i = 0; i < mat.size(); i++){
        om1[mat[i][0]]++;
        om2[{mat[i][0], mat[i][1]}]++;
    }
    sort(mat.begin(), mat.end(), [&](vector<string> &a, vector<string> &b){
        if(om1[a[0]] != om1[b[0]])
            return om1[a[0]] > om1[b[0]];
        if(a[0] != b[0])
            return a[0] < b[0];
        if(om2[a] != om2[b])
            return om2[a] > om2[b];
        return a[1] < b[1];
    });
    for(int i = 0; i < mat.size(); i++)
        cout << mat[i][0] << " " << mat[i][1] << endl;
}

int main(){
    int t, n, x, y;

    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<string>> mat(n, vector<string>(2));

        for(int i = 0; i < n; i++)
            cin >> mat[i][0];
        for(int i = 0; i < n; i++)
            cin >> mat[i][1];
        cin >> x >> y;
        solve(mat, x, y);
    }
    return 0;
}
