/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    string t1, t2;
    dfs(root1, t1);
    dfs(root2, t2);
    return t1 == t2;
  }

  void dfs(TreeNode* root, string& s) {
    if (not root) return;
    if (not root->left and not root->right) s += to_string(root->val) + "#";
    dfs(root->left, s);
    dfs(root->right, s);
  }
};