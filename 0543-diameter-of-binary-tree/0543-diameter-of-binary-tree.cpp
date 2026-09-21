/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dmtr = 0;
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int lft_hgt = height(root->left);
        int rgt_hgt = height(root->right);

        dmtr = max(dmtr, lft_hgt + rgt_hgt);
        return 1 + max(lft_hgt, rgt_hgt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return dmtr;
    }
};