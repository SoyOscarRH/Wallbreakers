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
  int longestUnivaluePath(TreeNode* c, TreeNode* r = nullptr) {
    if (not c) return 0;
    if (not r) {
      auto x = longestUnivaluePath(c, c);
      auto y = longestUnivaluePath(c->left, nullptr);
      auto z = longestUnivaluePath(c->right, nullptr);

      return max({x, y, z});
    }

    if (c->val != r->val) return 0;

    auto x = longestUnivaluePath(c->left, r);
    auto y = longestUnivaluePath(c->right, r);

    return (c == r) ? x + y : 1 + max(x, y);
  }
};
