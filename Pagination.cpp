#include<bits/stdc++.h>
using namespace std;

class Item{
public:
    string name;
    int rel;
    int price;
};

int main(){
    int numOfitems, sortPara, sortOrder, itemsPerPage, pageNumber;

    cin >> numOfitems;
    vector<Item> items(numOfitems);
    for(int i = 0; i < numOfitems; i++){
        string name;
        int rel, price;
        cin >> name >> rel >> price;
        items[i] = {name, rel, price};
    }
    cin >> sortPara >> sortOrder;
    sort(items.begin(), items.end(), [&](Item &a, Item &b){
        bool flag;
        if(sortPara == 0)
            flag = a.name < b.name;
        else if(sortPara == 1)
            flag = a.rel < b.rel;
        else
            flag = a.price < b.price;
        if(sortOrder == 0)
            return flag;
        else
            return !flag;
    });
    cin >> itemsPerPage >> pageNumber;
    int res = itemsPerPage * pageNumber;
    for(int i = res; i < res + itemsPerPage && i < numOfitems; i++)
        cout << items[i].name << " ";
    return 0;
}
