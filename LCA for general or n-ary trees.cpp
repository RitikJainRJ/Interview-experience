#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int n;
    vector<int> *adj;

    int lca(int u, int a, int b, int &res){
        if(res != -1)   return 0;
        int m1 = 0, m2 = 0, temp = 0;
        if(u == a || u == b)
            temp = 1;
        for(auto it = adj[u].begin(); it != adj[u].end(); it++){
            int v = *it;
            int t = lca(v, a, b, res);
            if(m1 <= t)
                m2 = m1, m1 = t;
            else if(m2 < t)
                m2 = t;
        }
        if(m1 == 1 && m2 == 1)
            res = u;
        else if(m1 == 1 && temp == 1)
            res = u;
        return 1 + m1 + m2;
    }

public:
    Graph(int n){
        this->n = n;
        adj = new vector<int>[n];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    int LCA(int a, int b){
        int res = -1;
        lca(0, a, b, res);
        return res;
    }
};

int main(){
    int n, m;
    int u, v;
    cin >> n >> m;
    Graph g(n);

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cin >> u >> v;
    cout << g.LCA(u, v) << endl;
    return 0;
}
