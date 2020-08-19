#include<bits/stdc++.h>
#define MAP unordered_map<string, vector<string>>
using namespace std;

void favGenre(MAP &um1, MAP &um2){
    unordered_map<string, string> um;
    MAP res;

    for(auto it = um2.begin(); it != um2.end(); it++){
        for(int i = 0; i < it->second.size(); i++)
            um[it->second[i]] = it->first;
    }
    for(auto it = um1.begin(); it != um1.end(); it++){
        unordered_map<string, int> count_map;
        int m = 0;
        for(int i = 0; i < it->second.size(); i++){
            count_map[um[it->second[i]]]++;
            m = max(m, count_map[um[it->second[i]]]);
        }
        for(auto it2 = count_map.begin(); it2 != count_map.end(); it2++)
            if(m == it2->second)
                res[it->first].push_back(it2->first);
    }

    for(auto it = res.begin(); it != res.end(); it++){
        cout << it->first << ": ";
        for(int i = 0; i < it->second.size(); it++)
            cout << it->second[i] << " ";
        cout << endl;
    }
}

int main(){
    int t, n, m, temp;

    cin >> t;
    while(t--){
        cin >> n >> m;
        MAP um1, um2;

        for(int i = 0; i < n; i++){
            string name, song;
            cin >> name >> temp;
            for(int j = 0; j < temp; j++){
                cin >> song;
                um1[name].push_back(song);
            }
        }
        for(int i = 0; i < m; i++){
            string genre, song;
            cin >> genre >> temp;
            for(int j = 0; j < temp; j++){
                cin >> song;
                um2[genre].push_back(song);
            }
        }
        favGenre(um1, um2);
        cout << endl;
    }
    return 0;
}
