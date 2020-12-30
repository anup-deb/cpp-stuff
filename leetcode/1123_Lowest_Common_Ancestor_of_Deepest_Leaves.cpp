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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<vector<TreeNode*>> traversal;
        vector<TreeNode*> curr_level{root};
        traversal.push_back(curr_level);
        
        while (!curr_level.empty()) {
            vector<TreeNode*> next_level;
            for (auto& node : curr_level) {
                if (auto left = node->left) {
                    next_level.push_back(left);
                }
                if (auto right = node->right) {
                    next_level.push_back(right);
                }
            }
            if(!next_level.empty()) traversal.push_back(next_level);
            curr_level = next_level;
        }
        vector<TreeNode*> last_level = traversal.back();
        return findAncestor(last_level, root);
    }
    
    TreeNode* findAncestor(const vector<TreeNode *>& targets, TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        bool is_on_left {false};
        bool is_on_right {false};
        for (const auto& target : targets) {
            if (root == target) {
                return root;
            }
            if (contains(root->left, target)) {
                is_on_left = true;
            }
            if (contains(root->right, target)) {
                is_on_right = true;
            }
        }
        if (is_on_left && is_on_right) {
            return root;
        } else if (is_on_left) {
            return findAncestor(targets, root->left);
        } else if (is_on_right) {
            return findAncestor(targets, root->right);
        }
        return nullptr;
    }
    
    bool contains(const TreeNode *root, TreeNode *target) {
        if (root == nullptr) {
            return false;
        } 
        if (root == target) {
            return true;
        }
        return contains(root->left, target) || contains(root->right, target);
    }
};