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

TreeNode *invertTree(TreeNode *root) {
  if (!root) {
    return nullptr;
  }

  std::queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *tmp = q.front();
    q.pop();

    std::swap(tmp->left, tmp->right);
    if (tmp->left) {
      q.push(tmp->left);
    }
    if (tmp->right) {
      q.push(tmp->right);
    }
  }

  return root;
}
