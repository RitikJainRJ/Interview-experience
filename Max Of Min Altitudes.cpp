#include<bits/stdc++.h>
using namespace std;

int maxMinAltitude(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();

    for(int i = 2; i < n; i++)
        mat[i][0] = min(mat[i][0], mat[i - 1][0]);
    for(int i = 2; i < m; i++)
        mat[0][i] = min(mat[0][i], mat[0][i - 1]);
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            mat[i][j] = min(mat[i][j], max(mat[i - 1][j], mat[i][j - 1]));
    return max(mat[n - 2][m - 1], mat[n - 1][m - 2]);
}

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> mat[i][j];
        cout << maxMinAltitude(mat) << endl;
    }
    return 0;
}
