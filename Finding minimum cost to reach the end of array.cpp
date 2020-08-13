#include<bits/stdc++.h>
using namespace std;

int minDist(vector<bool> &visited, vector<int> &dist, int n){
    int m = INT_MAX, res = 0;

    for(int i = 0; i < n; i++)
        if(!visited[i] && m > dist[i])
            m = dist[i], res = i;
    return res;
}

int minJump(int *arr, int n){
    vector<bool> visited(n, false);
    vector<int> dist(n, INT_MAX);

    dist[0] = 0;
    for(int c = 0; c < n - 1; c++){
        int u = minDist(visited, dist, n);
        visited[u] = true;

        if(u + 2 < n && !visited[u + 2] && dist[u] + arr[u + 2] < dist[u + 2])
            dist[u + 2] = dist[u] + arr[u + 2];
        if(u - 1 >= 0 && !visited[u - 1] && dist[u] + arr[u - 1] < dist[u - 1])
            dist[u - 1] = dist[u] + arr[u - 1];
    }
    return dist[n - 1];
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << minJump(arr, n) << endl;
    }
    return 0;
}
