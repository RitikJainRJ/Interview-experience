#include<bits/stdc++.h>
using namespace std;

int minCashflow(vector<vector<int>> &mat){
    int n = mat.size(), i;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int arr[n] = {0}, res = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            arr[i] -= mat[i][j];
            arr[j] += mat[i][j];
        }
    for(i = 0; arr[i] < 0; i++)
        minHeap.push(arr[i]);
    for(; i < n; i++)
        maxHeap.push(arr[i]);
    while(!minHeap.empty() && !maxHeap.empty()){
        int minTop = minHeap.top(), maxTop = maxHeap.top();
        minHeap.pop(), maxHeap.pop();

        if(abs(minTop) < maxTop)
            maxHeap.push(maxTop + minTop);
        else if(abs(minTop) > maxTop)
            minHeap.push(minTop + maxTop);
        res++;
    }
    return res;
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> mat[i][j];
        cout << minCashflow(mat) << endl;
    }
    return 0;
}
