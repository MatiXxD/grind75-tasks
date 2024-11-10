std::vector<int> twoSum(std::vector<int> &nums, int target) {
  std::unordered_map<int, int> numToTarget;
  for (int i = 0; i != nums.size(); ++i) {
    if (numToTarget.find(nums[i]) != numToTarget.end()) {
      return {numToTarget[nums[i]], i};
    }
    numToTarget[target - nums[i]] = i;
  }
  return {};
}
