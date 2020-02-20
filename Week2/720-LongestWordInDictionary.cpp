class Solution {
public:
  auto longestWord(vector<string> &words) -> string {
    sort(begin(words), end(words));
    auto built = unordered_set<string>{};

    auto result = string{};
    for (const auto word& : words) {

      auto almost_word = word;
      word.pop_back();

      if (w.size() == 1 or built.count(almost_word)) {
        result = w.size() > res.size() ? word : result;
        built.insert(word);
      }
    }
    return result;
  }
};