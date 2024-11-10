class MyQueue {
public:
  MyQueue() {}

  void push(int x) { input.push(x); }

  int pop() {
    moveInput();
    int ret = output.top();
    output.pop();
    return ret;
  }

  int peek() {
    moveInput();
    return output.top();
  }

  bool empty() { return input.empty() && output.empty(); }

private:
  std::stack<int> input;
  std::stack<int> output;

  void moveInput() {
    if (output.empty()) {
      while (!input.empty()) {
        output.push(input.top());
        input.pop();
      }
    }
  }
};
