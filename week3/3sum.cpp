std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
  std::vector<std::vector<int>> triplets;
  std::sort(nums.begin(), nums.end());
  for (int k = 0; k != nums.size() - 2; ++k) {
    if (k > 0 && nums[k] == nums[k - 1]) {
      continue;
    }

    int i = k + 1, j = nums.size() - 1;
    while (i < j) {
      int sum = nums[k] + nums[i] + nums[j];
      if (sum == 0) {
        triplets.push_back({nums[k], nums[i], nums[j]});
        while (i < j && nums[i + 1] == nums[i]) {
          i++;
        }
        while (i < j && nums[j - 1] == nums[j]) {
          j--;
        }
        i++;
        j--;
      } else if (sum > 0) {
        j--;
      } else {
        i++;
      }
    }
  }
  return triplets;
}
