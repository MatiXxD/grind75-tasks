int search(std::vector<int> &nums, int target) {
  int i = 0, j = nums.size() - 1;
  while (i <= j) {
    int ind = (i + j) / 2;
    if (target == nums[ind]) {
      return ind;
    } else if (target > nums[ind]) {
      i = ind + 1;
    } else {
      j = ind - 1;
    }
  }
  return -1;
}
