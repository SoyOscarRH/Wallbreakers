class Solution {
 public:
  auto numSpecialEquivGroups(const vector<string>& words) -> int {
    auto groups = set<pair<string, string>> {};
    for (const auto& word : words) {
      auto odds = string {}, evens = string {};
      const auto size = word.size() / 2;
      odds.reserve(size), evens.reserve(size);

      for (auto i = 0; i < word.size(); i += 2) evens += word[i];
      for (auto i = 1; i < word.size(); i += 2) odds += word[i];

      sort(begin(evens), end(evens));
      sort(begin(odds), end(odds));

      groups.insert({evens, odds});
    }

    return groups.size();
  }
};