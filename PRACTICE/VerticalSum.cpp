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

class Solution {
  public:
    vector<int> verticalSum(Node* root) {
       vector<int> ans;
       queue<pair<Node*, int>> q;
       map<int, int> mp;
       q.push({root, 0});
       mp[0] = root->data;
       while(!q.empty()){
           Node* node = q.front().first;
           int axis = q.front().second;
           
           q.pop();
           
           if(node->left){
               q.push({node->left, axis - 1});
               mp[axis-1] += node->left->data;
           }
           if(node->right){
               q.push({node->right, axis + 1});
               mp[axis+1] += node->right->data;
           }
       }
       
       for(auto it = mp.begin(); it != mp.end(); it++){
            // cout << "First: " << it->first << ", " << it->second<< endl;
          ans.push_back(it->second);
       }
        return ans;
    }
};