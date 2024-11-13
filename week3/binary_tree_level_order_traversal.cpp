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

std::vector<std::vector<int>> levelOrder(TreeNode *root) {
  if (!root) {
    return {};
  }

  std::vector<std::vector<int>> res;
  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int levelSize = q.size();
    std::vector<int> row(levelSize);
    for (int i = 0; i != levelSize; ++i) {
      TreeNode *tmp = q.front();
      row[i] = tmp->val;
      q.pop();
      if (tmp->left) {
        q.push(tmp->left);
      }
      if (tmp->right) {
        q.push(tmp->right);
      }
    }
    res.push_back(row);
  }
  return res;
}
