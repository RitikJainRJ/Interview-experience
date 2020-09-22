#include<bits/stdc++.h>
using namespace std;

int dfs(int ind, int x, int y, char *word, char **board, int m, int n){
    if(word[ind + 1] == '\0'){
        return 1;
    }
    int xMove[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int yMove[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int res = 0;

    board[x][y] = '$';
    for(int i = 0; i < 8; i++){
        int nx = x + xMove[i];
        int ny = y + yMove[i];

        if(0 <= nx && nx < m && 0 <= ny && ny < n && board[nx][ny] == word[ind + 1])
            res += dfs(ind + 1, nx, ny, word, board, m, n);
    }
    board[x][y] = word[ind];
    return res;
}

int findFrequency(char **board, int m, int n, char *word){
    int res = 0;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == word[0])
                res += dfs(0, i, j, word, board, m, n);
    return res;
}
