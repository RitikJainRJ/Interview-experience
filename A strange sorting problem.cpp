#include<bits/stdc++.h>
#define psi pair<string, int>
using namespace std;

int convert(string &s, unordered_map<int, int> &um){
    int res = 0;

        res = res * 10 + (um[s[i] - '0']);
    }
    return res;
}

void solve(vector<int> &mapping, vector<string> &nums){
    int n = nums.size();
    unordered_map<int, int> um;
    vector<psi> res(n);

    for(int i = 0; i < 10; i++)
        um[mapping[i]] = i;
    for(int i = 0; i < n; i++){
        int t = convert(nums[i], um);
        res[i] = {nums[i], t};
    }
    sort(res.begin(), res.end(), [&](psi &a, psi &b){
        return a.second < b.second;
    });
    for(int i = 0; i < n; i++)
        cout << res[i].first << " ";
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> mapping(10);
        vector<string> nums(n);

        for(int i = 0; i < 10; i++)
            cin >> mapping[i];
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        solve(mapping, nums);
        cout << endl;
    }
    return 0;
}
