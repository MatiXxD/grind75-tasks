bool isValid(int i, int j, int n, int m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image,
                                        int sr, int sc, int color) {
  int n = image.size(), m = image[0].size();
  std::stack<std::pair<int, int>> st;
  st.push({sr, sc});
  while (!st.empty()) {
    std::pair<int, int> p = st.top();
    st.pop();

    int i = p.first, j = p.second;
    if (!isValid(i, j, n, m) || image[p.first][p.second] == color) {
      continue;
    }

    if (isValid(i + 1, j, n, m) && image[i + 1][j] == image[i][j]) {
      st.push({i + 1, j});
    }
    if (isValid(i, j + 1, n, m) && image[i][j + 1] == image[i][j]) {
      st.push({i, j + 1});
    }
    if (isValid(i - 1, j, n, m) && image[i - 1][j] == image[i][j]) {
      st.push({i - 1, j});
    }
    if (isValid(i, j - 1, n, m) && image[i][j - 1] == image[i][j]) {
      st.push({i, j - 1});
    }

    image[i][j] = color;
  }

  return image;
}

// RECURSIVE SOLUTION
// void dfs(vector<vector<int>> &image, int sr, int sc, int n, int m,
//          int targetColor, int originalColor) {
//   if (sr < 0 || sr >= n || sc < 0 || sc >= m) {
//     return;
//   } else if (image[sr][sc] != originalColor || image[sr][sc] == targetColor)
//   {
//     return;
//   }
//   image[sr][sc] = targetColor;
//   dfs(image, sr + 1, sc, n, m, targetColor, originalColor);
//   dfs(image, sr, sc + 1, n, m, targetColor, originalColor);
//   dfs(image, sr - 1, sc, n, m, targetColor, originalColor);
//   dfs(image, sr, sc - 1, n, m, targetColor, originalColor);
// }
//
// vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
//                               int color) {
//   size_t n = image.size();
//   size_t m = image[0].size();
//   int targetColor = color;
//   int originalColor = image[sr][sc];
//   dfs(image, sr, sc, n, m, targetColor, originalColor);
//   return image;
// }
