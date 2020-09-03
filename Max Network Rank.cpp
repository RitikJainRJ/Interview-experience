#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int n;
    vector<int> *adj;
    vector<int> indeg;

    void dfs(int u, vector<bool> &visited, int &res){
        visited[u] = true;

        for(auto it = adj[u].begin(); it != adj[u].end(); it++){
            int v = *it;
            res = max(res, indeg[u] + indeg[v] - 1);
            if(!visited[v]){
                dfs(v, visited, res);
            }
        }
    }

public:
    Graph(int n){
        this->n = n;
        indeg = vector<int>(n, 0);
        adj = new vector<int>[n];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
        indeg[u]++, indeg[v]++;
    }

    int solve(){
        vector<bool> visited(n, false);
        int res = 0;

        dfs(0, visited, res);
        return res;
    }
};

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int a[n], b[n];
        Graph g(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        for(int i = 0; i < n; i++)
            g.addEdge(a[i] - 1, b[i] - 1);
        cout << g.solve() << endl;
    }
    return 0;
}
