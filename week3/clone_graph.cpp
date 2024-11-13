/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

Node *clone(Node *node, std::unordered_map<Node *, Node *> &visited) {
  if (visited.contains(node)) {
    return visited[node];
  }

  Node *newNode = new Node(node->val);
  visited[node] = newNode;
  for (auto &n : node->neighbors) {
    newNode->neighbors.push_back(clone(n, visited));
  }

  return newNode;
}

Node *cloneGraph(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }
  std::unordered_map<Node *, Node *> visited;
  return clone(node, visited);
}
