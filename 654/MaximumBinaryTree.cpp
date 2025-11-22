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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traverse(nums, 0, nums.size() - 1);
    }
    TreeNode* traverse(vector<int>&nums, int lo, int high){
        if (lo > high) return nullptr;
        int index = -1, max = INT_MIN;
        for(int i = lo; i <= high ; i++){
            if (nums[i] > max){
                max = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = traverse(nums, lo, index - 1);
        root->right = traverse(nums, index + 1, high);
        return root;
    }
};