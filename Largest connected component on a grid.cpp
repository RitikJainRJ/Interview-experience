/*
1
6 8
1 4 4 4 4 3 3 1
2 1 1 4 3 3 1 1
3 2 1 1 2 3 2 1
3 3 2 1 2 2 2 2
3 1 3 1 1 4 4 4
1 1 3 1 1 4 4 4
*/
#include<bits/stdc++.h>
using namespace std;

int dfs(int x, int y, vector<vector<int>> &mat){
    int xMove[] = {-1, 0, 1, 0};
    int yMove[] = {0, 1, 0, -1};
    int val = mat[x][y], res = 1;

    mat[x][y] = -1;
    for(int i = 0; i < 4; i++){
        int nx = x + xMove[i];
        int ny = y + yMove[i];
        if(0 <= nx && nx < mat.size() && 0 <= ny && ny < mat[0].size() && mat[nx][ny] == val)
            res += dfs(nx, ny, mat);
    }
    return res;
}

int largeComp(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();
    int res = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] != -1)
                res = max(res, dfs(i, j, mat));
    return res;
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
        cout << largeComp(mat) << endl;
    }
    return 0;
}
