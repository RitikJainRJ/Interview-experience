#include<bits/stdc++.h>
using namespace std;

void sortRelative(vector<vector<int>> &nums){
    sort(nums.begin(), nums.end(), [&](vector<int> &a, vector<int> &b){
        return a[1] != b[1] ? a[1] < b[1] : a[2] < b[2];
    });
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i][0] << " ";
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> nums(n);

        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            nums[i] = {a, b, i};
        }
        sortRelative(nums);
        cout << endl;
    }
    return 0;
}
