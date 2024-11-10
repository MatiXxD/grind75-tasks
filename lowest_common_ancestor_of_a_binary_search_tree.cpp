/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *lowestCommonAncestor(TreeNode *node, TreeNode *p, TreeNode *q) {
  if (!node || node == p || node == q) {
    return node;
  }

  TreeNode *left = lowestCommonAncestor(node->left, p, q);
  TreeNode *right = lowestCommonAncestor(node->right, p, q);
  if (left && right) {
    return node;
  }

  return left ? left : right;
}
