class Solution {
 public:
  bool isSubsequence(const string& short_s, const string& long_s) {
    auto i = 0;
    for (char l : long_s) {
      if (l == short_s[i]) ++i;
    }

    return i == short_s.size();
  }
};
