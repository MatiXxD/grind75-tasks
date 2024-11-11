bool canConstruct(std::string ransomNote, std::string magazine) {
  std::array<int, 26> counts;
  for (char &ch : magazine) {
    counts[ch - 'a']++;
  }

  for (char &ch : ransomNote) {
    counts[ch - 'a']--;
    if (counts[ch - 'a'] < 0) {
      return false;
    }
  }

  return true;
}
