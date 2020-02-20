class Solution {
 public:
  auto mostCommonWord(string& paragraph, vector<string>& banned) -> string {
    const auto lower = [](string& s) {
      transform(begin(s), end(s), begin(s), ::tolower);
    };
    for (auto& c : paragraph) c = isalpha(c) ? tolower(c) : ' ';

    auto is_banned = set<string> {};
    for (auto& ban : banned) {
      lower(ban);
      is_banned.insert(ban);
    }

    auto frequency = map<string, int> {};

    auto words = stringstream {paragraph};
    auto word = string {};

    while (words >> word) {
      while (not isalpha(word.back())) word.pop_back();

      if (is_banned.count(word)) continue;
      ++frequency[word];
    }

    const auto sec = [](const auto& x, const auto& y) {
      return x.second < y.second;
    };
    return max_element(begin(frequency), end(frequency), sec)->first;
  }
};