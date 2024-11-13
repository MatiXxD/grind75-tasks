std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points,
                                       int k) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      heap;
  for (int i = 0; i != points.size(); ++i) {
    heap.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
  }

  std::vector<std::vector<int>> res;
  for (int i = 0; i != k && !heap.empty(); ++i) {
    res.push_back(points[heap.top().second]);
    heap.pop();
  }

  return res;
}
