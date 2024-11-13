bool isOperator(std::string token) {
  return token == "+" || token == "-" || token == "*" || token == "/";
}

int toInt(std::string token) {
  int num = 0;
  int minus = 1;
  if (token[0] == '-') {
    minus = -1;
    token = std::string(token.begin() + 1, token.end());
  }

  int factor = 1;
  for (auto it = token.rbegin(); it != token.rend(); ++it) {
    num += (*it - '0') * factor;
    factor *= 10;
  }

  return minus * num;
}

int evalRPN(std::vector<std::string> &tokens) {
  std::stack<int> nums;
  for (std::string &token : tokens) {
    if (!isOperator(token)) {
      nums.push(toInt(token));
    } else {
      int n2 = nums.top();
      nums.pop();
      int n1 = nums.top();
      nums.pop();
      if (token == "+") {
        nums.push(n1 + n2);
      } else if (token == "-") {
        nums.push(n1 - n2);
      } else if (token == "*") {
        nums.push(n1 * n2);
      } else if (token == "/") {
        nums.push(n1 / n2);
      }
    }
  }

  return nums.top();
}
