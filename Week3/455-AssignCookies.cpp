class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(begin(g), end(g));
    sort(begin(s), end(s));

    auto i = 0, j = 0;
    while (i < g.size() and j < s.size()) {
      if (s[j] >= g[i]) i++;
      j++;
    }

    return i;
  }
};