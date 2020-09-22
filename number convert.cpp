#include<bits/stdc++.h>
using namespace std;

string to_string(int n){
    string res;

    while(n){
        res.push_back((n % 10) + '0');
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int stoi(string &s){
    int res = 0;

    for(int i = 0; i < s.length(); i++)
        res = res * 10 + (s[i] - '0');
    return res;
}

int NewNumber(int n){
    string s, res;
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    s = to_string(n);
    for(int i = 0; i < s.length(); i++)
        res.push_back(arr[s[i] - '0'] + '0');
    return stoi(res);
}


int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << NewNumber(n) << endl;
    }
    return 0;
}

