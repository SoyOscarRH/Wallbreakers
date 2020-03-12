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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (not p and not q) return true;
    if (not p or not q) return false;

    if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
  }
};