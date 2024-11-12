/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

int findDiameter(TreeNode *node, int &d) {
  if (!node) {
    return 0;
  }

  int l = findDiameter(node->left, d);
  int r = findDiameter(node->right, d);
  d = std::max(d, l + r);

  return std::max(l, r) + 1;
}

int diameterOfBinaryTree(TreeNode *root) {
  int d = 0;
  findDiameter(root, d);
  return d;
}
