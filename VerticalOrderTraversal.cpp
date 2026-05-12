#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : data(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}    
  };
  
class Solution {
public:
    vector<vector<int> > verticalTraversal(TreeNode* root) {
    	map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            TreeNode* currNode = q.front().first;
            int axis = q.front().second.first;
            int level = q.front().second.second;

            nodes[axis][level].insert(currNode->data);
            if(currNode->left) 
                q.push({currNode->left, {axis - 1, level + 1}});
            if(currNode->right) 
                q.push({currNode->right, {axis + 1, level + 1}});

            q.pop();
        }
        vector<vector<int> > ans;

        for(auto &p : nodes){
            vector<int> column;
            for(auto &q : p.second){
                column.insert(column.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(column);
        }
        return ans;
    }
};