#include<bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> &a, vector<int> &b){
    vector<int> res;
    int i = 0, j = 0;

    while(i < a.size() && j < b.size()){
        if(a[i] == b[j]){
            res.push_back(a[i]);
            i++, j++;
        }
        else if(a[i] < b[j])
            i++;
        else
            j++;
    }
    return res;
}

void solve(vector<string> &sentences, vector<string> &phrases){
    unordered_map<string, vector<int>> um;

    for(int i = 0; i < sentences.size(); i++){
        int j = 0, k;
        for(k = 0; k < sentences[i].size(); k++){
            if(isalpha(sentences[i][k]))
                continue;
            um[sentences[i].substr(j, k - j)].push_back(i);
            j = k + 1;
        }
    }
    for(int i = 0; i < phrases.size(); i++){
        vector<int> res(sentences.size());
        for(int i = 0; i < sentences.size(); i++)
            res[i] = i;
        int j = 0, k;
        for(k = 0; k < phrases[i].size(); k++){
            if(isalpha(phrases[i][k]))
                continue;
            res = intersect(um[phrases[i].substr(j, k - j)], res);
            j = k + 1;
        }
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<string> sentences(n), phrases(m);

        cin >> ws;
        for(int i = 0; i < n; i++)
            getline(cin, sentences[i]);
        cin >> ws;
        for(int i = 0; i < m; i++)
            getline(cin, phrases[i]);
        solve(sentences, phrases);
        cout << endl;
    }
    return 0;
}
