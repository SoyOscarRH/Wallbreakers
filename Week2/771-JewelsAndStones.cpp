class Solution {
 public:
  auto numJewelsInStones(const string& J, const string& S) -> int {
    const auto jewels = unordered_set<char> {begin(J), end(J)};

    auto stones = 0;
    for (auto stone : S) {
      if (jewels.count(stone)) ++stones;
    }

    return stones;
  }
};