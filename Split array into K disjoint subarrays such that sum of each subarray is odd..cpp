#include<bits/stdc++.h>
using namespace std;

void split(int k, int *arr, int n){
    int count = 0;

    for(int i = 0; i < n; i++)
        if(arr[i] % 2)  count++;
    if(count < k)
        cout << -1;
    else if((count - k) % 2)
        cout << -1;
    else{
        for(int i = 0; i < n; i++){
            if(k == 0)
                break;
            if(arr[i] % 2){
                cout << i + 1 << " ";
                k--;
            }
        }
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
        split(k, arr, n);
        cout << endl;
    }
    return 0;
}
