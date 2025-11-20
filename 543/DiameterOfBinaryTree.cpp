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
private:
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter;
    }
    int maxDepth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int leftmax = maxDepth(root->left);
        int rightmax = maxDepth(root->right);
        diameter = max(diameter, leftmax + rightmax);
        return 1 + max(leftmax,rightmax);
    }
};