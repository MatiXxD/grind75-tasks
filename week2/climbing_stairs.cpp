int climbStairs(int n) {
  if (n <= 2) {
    return n;
  }

  int slow = 1, fast = 2;
  for (int i = 2; i < n; i++) {
    int tmp = slow;
    slow = fast;
    fast = slow + tmp;
  }

  return fast;
}
