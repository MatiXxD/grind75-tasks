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

int checkBalance(TreeNode *node) {
  if (!node) {
    return 0;
  }

  int left = checkBalance(node->left);
  if (left == -1) {
    return left;
  }

  int right = checkBalance(node->right);
  if (right == -1) {
    return right;
  }

  return std::abs(left - right) <= 1 ? std::max(left, right) + 1 : -1;
}

bool isBalanced(TreeNode *root) { return checkBalance(root) != -1; }
