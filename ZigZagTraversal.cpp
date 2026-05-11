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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int> > ans; 
        vector<int> temp;
        bool alternate = true;

        while(!q.empty()){
            TreeNode* currNode = q.front();
            if(currNode){
                temp.push_back(currNode->data);
                if(currNode->left)
                    q.push(currNode->left);
                if(currNode->right)
                    q.push(currNode->right);
            }
            q.pop();

            if(currNode == nullptr){
                if(alternate) alternate = !alternate;
                else{
                    alternate = !alternate;
                    reverse(temp.begin(), temp.end());
                }
                ans.push_back(temp);
                temp.clear();
            }

            if(!q.empty() && currNode == nullptr) q.push(nullptr);

        }

        return ans;
    }
};