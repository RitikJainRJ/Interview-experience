#include<bits/stdc++.h>
using namespace std;

void reverse(int i, string &s){
    if(i >= s.length() / 2)
        return;
    swap(s[i], s[s.length() - 1 - i]);
    reverse(i + 1, s);
}

int main(){
    int t;
    string s;

    cin >> t;
    cin >> ws;
    while(t--){
        getline(cin, s);
        reverse(0, s);
        cout << s << endl;
    }
    return 0;
}
