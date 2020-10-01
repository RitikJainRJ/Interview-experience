#include<bits/stdc++.h>
using namespace std;

/*
input:-
1 1 2 33 4 6 9 7 36 12 58 32 28 994 22 255 47 69 558 544 21 36 48 85 48 58
236

252 888 578 746 295 884 198 655 503 868 942 506 718 498 727 338 43 768 783 312 369 712 230 106 102 554
6674
*/

bool _solve(int *A, int ind, int w, string &ans){
    if(w == 0)
        return true;
    if(ind < 0 || w < 0)
        return false;
    ans.push_back(ind + 'a');
    if(_solve(A, ind, w - A[ind], ans))
        return true;
    ans.pop_back();
    if(_solve(A, ind - 1, w, ans))
        return true;
}

string solve(int *A, int w){
    string ans;

    _solve(A, 25, w, ans);
    return ans;
}

int main(){
    int t, w;

    cin >> t;
    while(t--){
        int A[26];

        for(int i = 0; i < 26; i++)
            cin >> A[i];
        cin >> w;
        cout << solve(A, w) << endl;
    }
    return 0;
}
