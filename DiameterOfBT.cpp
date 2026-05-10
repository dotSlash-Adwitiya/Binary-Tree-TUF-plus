#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}    
  };

// * BRUTE FORCE : O(N²)
int maxi = 0;
int height(TreeNode* root){
    if(!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    // * Calculate heigh of each node
    int lh = height(root->left);
    int rh = height(root->right);

    // * Return left Height + Right Height and store max one
    maxi = max(maxi, lh + rh);

    // * Traverse on tree
    diameterOfBinaryTree(root->left);
    diameterOfBinaryTree(root->right);
    return maxi;
}

// * Optimized Approach
// * TC: O(N)
int height(TreeNode* root, int &maxi){
    if(!root) return 0;

    int lh = height(root->left, maxi);
    int rh = height(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return max(lh, rh) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    int maxi = 0;
    height(root, maxi);
    return maxi;
}

