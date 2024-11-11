int longestPalindrome(std::string s) {
  std::unordered_map<char, int> counts;
  for (char &ch : s) {
    counts[ch]++;
  }

  int res = 0;
  bool hasOne = false;
  for (const auto &[k, v] : counts) {
    res += v / 2;
    hasOne = hasOne ? hasOne : v % 2;
  }

  return 2 * res + hasOne;
}
