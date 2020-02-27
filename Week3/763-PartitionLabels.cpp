class Solution {
 public:
  auto partitionLabels(string& s) -> vector<int> {
    if (not s.size()) return {};

    auto answer = vector<int> {};

    auto memo = unordered_map<char, int> {};
    auto i = 0;
    for (auto c : s) memo[c] = i++;

    auto start = 0, end = 0;
    for (auto i = 0; i < s.size(); i++) {
      end = max(end, memo[s[i]]);
      if (end == i) {
        answer.push_back(end - start + 1);
        start = end + 1;
      }
    }

    return answer;
  }
};