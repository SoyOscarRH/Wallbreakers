class Solution {
 public:
  auto uncommonFromSentences(const string& A, const string& B)
      -> vector<string> {
    auto data = stringstream {A + " " + B};
    auto word = string {};

    auto seen = unordered_map<string, int> {};
    while (data >> word) ++seen[word];

    auto result = vector<string> {};
    for (const auto& [str, frequency] : seen) {
      if (frequency == 1) result.push_back(str);
    }

    return result;
  }
};