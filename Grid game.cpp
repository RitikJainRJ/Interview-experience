#include<bits/stdc++.h>
using namespace std;

void gridGame(vector<vector<int>> &mat, unordered_set<int> &us, int p){
    int xMove[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int yMove[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int n = mat.size(), m = mat[0].size(), count;

    while(p--){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                count = 0;
                for(int k = 0; k < 8; k++){
                    int nx = i + xMove[k];
                    int ny = j + yMove[k];
                    if(0 <= nx && nx < n && 0 <= ny && ny < m && mat[nx][ny] != 0 && mat[nx][ny] != -2)
                        count++;
                }
                if(us.find(count) != us.end()){
                    if(mat[i][j] == 0)
                        mat[i][j] = -2;
                }
                else{
                    if(mat[i][j] == 1)
                        mat[i][j] = -1;
                }
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mat[i][j] == -1)
                    mat[i][j] = 0;
                else if(mat[i][j] == -2)
                    mat[i][j] = 1;
    }
}

int main(){
    int t, n, m, k, p;

    cin >> t;
    while(t--){
        cin >> n >> m >> k >> p;
        vector<vector<int>> mat(n, vector<int>(m));
        unordered_set<int> us;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> mat[i][j];
        for(int i = 0; i < k; i++){
            int a;
            cin >> a;
            us.insert(a);
        }
        gridGame(mat, us, p);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
