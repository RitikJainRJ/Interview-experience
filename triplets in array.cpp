#include<bits/stdc++.h>
using namespace std;

int countTriplet(int *arr, int n){
    int leftmax[n], rightmin[n], res = 0;
    set<int, greater<int>> s1;
    set<int> s2;

    for(int i = 0; i < n; i++){
        s1.insert(arr[i]);
        leftmax[i] = distance(s1.begin(), s1.lower_bound(arr[i]));
    }
    for(int i = n - 1; i >= 0; i--){
        s2.insert(arr[i]);
        rightmin[i] = distance(s2.begin(), s2.lower_bound(arr[i]));
    }
    for(int i = 0; i < n; i++)
        res += (leftmax[i] * rightmin[i]);
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
        cout << countTriplet(arr, n) << endl;
    }
    return 0;
}
