class Solution {
 public:
  auto findTheDifference(const string& s, const string& t) -> char {
    const auto s_xor = accumulate(begin(s), end(s), 0, bit_xor<int> {});
    const auto t_xor = accumulate(begin(t), end(t), 0, bit_xor<int> {});

    return t_xor xor s_xor;
  }
};