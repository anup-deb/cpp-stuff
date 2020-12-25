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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            vector<string> res;
            return res;
        }
        vector<string> left;
        if (root->left == nullptr && root->right == nullptr) {
            vector<string> res;
            res.push_back(to_string(root->val));
            return res;
        } else {
            left = binaryTreePaths(root->left);
            vector<string> right = binaryTreePaths(root->right);
            left.insert(left.end(), right.begin(), right.end());
        }
        for (auto& s : left) {
            s = to_string(root->val) + "->" + s;
        }
        return left;
    }
};