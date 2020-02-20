class Solution {
 public:
  auto findAnagrams(const string& s, const string& p) -> vector<int> {
    if (s.size() < p.size()) return {};

    auto pv = vector<int>(26, 0), sv = vector<int>(26, 0);

    for (int i = 0; i < p.size(); ++i) {
      ++pv[p[i] - 'a'];
      ++sv[s[i] - 'a'];
    }

    auto result = vector<int> {};
    if (pv == sv) result.push_back(0);

    for (int i = p.size(); i < s.size(); ++i) {
      ++sv[s[i] - 'a'];

      --sv[s[i - p.size()] - 'a'];

      if (pv == sv) result.push_back(i - p.size() + 1);
    }
    return result;
  }
};