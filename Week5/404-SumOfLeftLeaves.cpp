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
    bool leaf(const TreeNode* p) {
      return not (p->left or p->right);
    }
  
    int sumOfLeftLeaves(TreeNode* p, bool init = true) {
      if (not p) return 0;
      if (not p->left and not p->right) return init? 0 : p->val;
      
      auto result = sumOfLeftLeaves(p->left, false);
      
      if (p->right != NULL and leaf(p->right)) return result;
      
      return result + sumOfLeftLeaves(p->right, false); 
  }
};404. Sum of Left Leaves