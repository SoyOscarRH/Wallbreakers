class Solution {
 public:
  auto encode(const string& word) const {
    auto seen = array<vector<int>, 256> {};
    auto i = 0;
    for (const auto character : word) seen[character].push_back(i++);

    sort(begin(seen), end(seen));

    return seen;
  }

  auto isIsomorphic(string s, string t) -> bool const {
    const auto e1 = encode(s), e2 = encode(t);

    return e1 == e2;
  }
};