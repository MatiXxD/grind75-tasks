bool isAnagram(std::string s, std::string t) {
  if (s.length() != t.length()) {
    return false;
  }

  std::array<int, 'z' - 'a' + 1> counts;
  for (size_t i = 0; i != s.length(); ++i) {
    counts[s[i] - 'a']++;
    counts[t[i] - 'a']--;
  }

  for (int &count : counts) {
    if (count != 0) {
      return false;
    }
  }

  return true;
}
