#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

class myComp{
public:
    bool operator()(const pii &a, const pii &b){
        return a.second > b.second;
    }
};

void solve(int *arr, int n, int k){
    unordered_map<int, int> um;
    priority_queue<pii, vector<pii>, myComp> pq;

    for(int i = 0; i < n; i++)
        um[arr[i]]++;
    for(auto it = um.begin(); it != um.end(); it++)
        if(pq.size() < k)
            pq.push({it->first, it->second});
        else if(pq.top().second < it->second){
            pq.pop();
            pq.push({it->first, it->second});
        }
    while(!pq.empty()){
        cout << pq.top().first << " ";
        pq.pop();
    }
}

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        solve(arr, n, k);
        cout << endl;
    }
    return 0;
}
