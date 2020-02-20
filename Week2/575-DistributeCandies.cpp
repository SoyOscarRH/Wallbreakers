class Solution {
 public:
  int distributeCandies(const vector<int>& candies) {
    const auto limit = candies.size() / 2;
    auto unique = unordered_set<int> {};
    for (auto candy : candies) {
      if (unique.size() > limit) return limit;
      unique.insert(candy);
    }

    return min(unique.size(), limit);
  }
};