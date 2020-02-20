class Solution {
 public:
  array<string, 26> morse {
      ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
      ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
      "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

  auto to_morse(const string& input) -> string {
    auto result = string {};

    for (auto c : input) result += morse[c - 'a'];
    return result;
  }

  auto uniqueMorseRepresentations(const vector<string>& words) -> int {
    auto seen = unordered_set<string> {};

    for (const auto& word : words) seen.insert(to_morse(word));

    return seen.size();
  }
};