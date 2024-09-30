// https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int res = INT_MIN;
    int dfs(TreeNode* root){
        if(root == NULL)
            return 0;
        // We are ignoring negative anyways they won't for biggest
        int left = max(0,dfs(root->left));
        int right = max(0,dfs(root->right));
        res = max(res , left+right+root->val);
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};