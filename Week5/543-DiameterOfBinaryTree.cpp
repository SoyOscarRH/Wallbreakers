class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
  }

 private:
  int height(TreeNode* node, int& diameter) {
    if (not node) return 0;

    int l = height(node->left, diameter);
    int r = height(node->right, diameter);

    diameter = max(diameter, l + r);
    return 1 + max(l, r);
  }
};