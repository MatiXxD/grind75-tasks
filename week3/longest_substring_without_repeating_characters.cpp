int lengthOfLongestSubstring(std::string s) {
  int max = 0;
  int left = 0;
  std::unordered_set<char> uniq;
  for (int right = 0; right != s.length(); ++right) {
    while (uniq.contains(s[right])) {
      uniq.erase(s[left++]);
    }
    uniq.insert(s[right]);
    max = std::max(max, right - left + 1);
  }
  return max;
}
