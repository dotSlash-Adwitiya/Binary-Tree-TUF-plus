#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};


vector<int> verticalOrderTraversal(TreeNode *root) {
  queue<pair<TreeNode*, int>> q;
  vector<int> ans;
  map<int, int> mp;
  q.push({root, 0});

  while(!q.empty()){
      TreeNode* node = q.front().first;
      int axis = q.front().second;
      q.pop();
      if(node->left) q.push({node->left, axis-1});
      if(node->right) q.push({node->right, axis+1});
      mp[axis] = node->data;
  }
  for(auto it = mp.begin(); it != mp.end(); it++)
      ans.push_back(it->second);
  return ans;
}

vector <int> bottomView(TreeNode *root){
  return verticalOrderTraversal(root);
}