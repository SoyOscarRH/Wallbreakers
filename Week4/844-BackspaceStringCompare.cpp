class Solution {
 public:
  bool backspaceCompare(const string& S, const string& T) {
    auto s = string {}, t = string {};

    for (const auto x : S) {
      if (x == '#' and s.size()) s.pop_back();
      if (x != '#') s.push_back(x);
    }

    for (const auto x : T) {
      if (x == '#' and t.size()) t.pop_back();
      if (x != '#') t.push_back(x);
    }

    return s == t;
  }
};