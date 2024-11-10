bool isValid(std::string s) {
  std::unordered_map<char, char> mp = {{'}', '{'}, {']', '['}, {')', '('}};
  std::stack<char> st;
  for (char &ch : s) {
    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else {
      if (!st.empty() && st.top() == mp[ch]) {
        st.pop();
      } else {
        st.push(ch);
      }
    }
  }
  return st.empty();
}
