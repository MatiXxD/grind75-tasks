int maxSubArray(std::vector<int> &nums) {
  int sum = 0;
  int max = nums[0];
  for (int &num : nums) {
    sum += num;
    max = std::max(sum, max);
    sum = std::max(0, sum);
  }
  return max;
}
