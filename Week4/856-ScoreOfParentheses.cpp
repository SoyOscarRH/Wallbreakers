class Solution {
 public:
  int scoreOfParentheses(string S) {
    auto seen = stack<int> {};

    int current = 0;
    for (char i : S)
      if (i == '(') {
        seen.push(current);
        current = 0;
      } else {
        current += seen.top() + max(current, 1);
        seen.pop();
      }

    return current;
  }
};