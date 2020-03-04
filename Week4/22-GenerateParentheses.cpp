class Solution {
  vector<string> result;

 public:
  auto generateParenthesis(int n) -> vector<string> {
    result = {};
    helper("", n, n);
    return result;
  }
  auto helper(const string& str, int left, int right) -> void {
    if (left == 0 and right == 0) {
      result.push_back(str);
      return;
    }

    if (left > 0) helper(str + "(", left - 1, right);
    if (right > left) helper(str + ")", left, right - 1);
  }
};