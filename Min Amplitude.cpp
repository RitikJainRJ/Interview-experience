#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n){
    priority_queue<int, vector<int>, greater<int>> minHeap, temp;
    priority_queue<int> maxHeap;
    int res = INT_MAX;

    for(int i = 0; i < 4; i++)
        minHeap.push(arr[i]), maxHeap.push(arr[i]);
    for(int i = 4; i < n; i++){
        if(maxHeap.top() > arr[i]){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
        if(minHeap.top() < arr[i]){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    while(!maxHeap.empty()){
        temp.push(maxHeap.top());
        maxHeap.pop();
    }
    while(!minHeap.empty()){
        res = min(res, minHeap.top() - temp.top());
        minHeap.pop(), temp.pop();
    }
    return res;
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << solve(arr, n) << endl;
    }
    return 0;
}
