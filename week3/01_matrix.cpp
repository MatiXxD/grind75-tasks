std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat) {
  std::vector<std::vector<int>> dists(mat.size(),
                                      std::vector<int>(mat[0].size(), 1E6));
  int n = mat.size(), m = mat[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 0) {
        dists[i][j] = 0;
      } else {
        if (i > 0) {
          dists[i][j] = std::min(dists[i][j], dists[i - 1][j] + 1);
        }
        if (j > 0) {
          dists[i][j] = std::min(dists[i][j], dists[i][j - 1] + 1);
        }
      }
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (mat[i][j] == 0) {
        dists[i][j] = 0;
      } else {
        if (i < n - 1) {
          dists[i][j] = std::min(dists[i][j], dists[i + 1][j] + 1);
        }
        if (j < m - 1) {
          dists[i][j] = std::min(dists[i][j], dists[i][j + 1] + 1);
        }
      }
    }
  }

  return dists;
}

// BFS SOLUTION
// std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>
// &mat) {
//   int n = mat.size(), m = mat[0].size();
//   std::vector<std::vector<int>> dists(n, std::vector<int>(m, 1E6));
//   std::queue<std::pair<int, int>> q;
//
//   for (int i = 0; i != n; ++i) {
//     for (int j = 0; j != m; ++j) {
//       if (mat[i][j] == 0) {
//         q.push({i, j});
//         dists[i][j] = 0;
//       }
//     }
//   }
//
//   std::vector<std::pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//   while (!q.empty()) {
//     auto [i, j] = q.front();
//     q.pop();
//
//     for (auto [di, dj] : dirs) {
//       int ni = i + di;
//       int nj = j + dj;
//       if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
//         if (dists[ni][nj] > dists[i][j] + 1) {
//           dists[ni][nj] = dists[i][j] + 1;
//           q.push({ni, nj});
//         }
//       }
//     }
//   }
//
//   return dists;
// }
