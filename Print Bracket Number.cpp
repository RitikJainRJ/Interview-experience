#include<bits/stdc++.h>
#define pci pair<char, int>
using namespace std;

void solve(string &s){
    stack<pci> st;
    int c = 1;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            st.push({'(', c});
            cout << c << " ";
            c++;
        }
        else if(s[i] == ')'){
            pci top = st.top();
            st.pop();
            cout << top.second << " ";
        }
    }
}

int main(){
    int t;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        solve(s);
        cout << endl;
    }
    return 0;
}
