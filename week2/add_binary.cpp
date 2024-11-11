std::string addBinary(std::string a, std::string b) {
  int i = a.size() - 1;
  int j = b.size() - 1;

  int additional = 0;
  std::string res = "";
  while (i >= 0 || j >= 0 || additional) {
    int sum = additional;
    if (i >= 0) {
      sum += a[i] - '0';
      i--;
    }
    if (j >= 0) {
      sum += b[j] - '0';
      j--;
    }

    additional = sum / 2;
    res += '0' + (sum % 2);
  }

  return std::string(res.rbegin(), res.rend());
}
