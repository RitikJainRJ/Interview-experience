#include<bits/stdc++.h>
using namespace std;

class Window{
public:
    int count;
    vector<int> hash;

    Window(){
        count = 0;
        hash = vector<int>(26, 0);
    }

    void add(char ch){
        hash[ch - 'A']++;
        if((ch == 'A' || ch == 'B' || ch == 'C') && hash[ch - 'A'] == 1)
            count++;
    }

    void remove(char ch){
        hash[ch - 'A']--;
        if((ch == 'A' || ch == 'B' || ch == 'C') && hash[ch - 'A'] == 0)
            count--;
    }
};

int countString(string &s){
    int res = 0;
    Window w1, w2;

    int l1 = 0, l2 = 0, r;
    for(r = 0; r < s.length(); r++){
        w1.add(s[r]);
        w2.add(s[r]);

        while(w2.count > 2)
            w2.remove(s[l2++]);
        while(w1.count > 3)
            w1.remove(s[l1++]);
        res += (l2 - l1);
    }
    return res;
}

int main(){
    int t;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        cout << countString(s) << endl;
    }
    return 0;
}
