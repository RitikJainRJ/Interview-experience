#include<bits/stdc++.h>
#define pii pair<double, double>
using namespace std;

class TreeNode{
public:
    double val;
    vector<TreeNode*> children;

    TreeNode(double val){
        this->val = val;
    }
};

pii solve(TreeNode *root, double &res){
    if(!root)   return {0, 0};
    else if(root->children.size() == 0)     return {root->val, 1};
    else{
        double sum = root->val, numOfnodes = 1;

        for(double i = 0; i < root->children.size(); i++){
            pii temp = solve(root->children[i], res);
            sum += temp.first;
            numOfnodes += temp.second;
        }
        if(res < sum / numOfnodes)
            res = sum / numOfnodes;
        return {sum, numOfnodes};
    }
}

double maxAvg(TreeNode *root){
    double res = 0;

    solve(root, res);
    return res;
}
