class Solution {
 public:
  auto frequencySort(string word) -> string {
    array<int, 256> seen {};
    for (auto c : word) ++seen[c];

    auto data = vector<pair<int, char>> {};

    for (auto ch = 0; ch < 256; ++ch) {
      if (seen[ch]) data.push_back({seen[ch], ch});
    }

    auto sort_freq = [](const auto a, const auto b) {
      auto [freq_a, ch_a] = a;
      auto [freq_b, ch_b] = b;

      if (freq_a == freq_b) return ch_a < ch_b;
      return freq_a > freq_b;
    };

    sort(begin(data), end(data), sort_freq);

    auto result = string {};
    for (auto [freq, ch] : data) result.append(freq, ch);

    return result;
  }
};