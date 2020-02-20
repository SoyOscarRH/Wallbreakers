class Solution {
 public:
  auto first_n_sum(int n) const { return (n * (n + 1)) / 2; }

  auto findErrorNums(const vector<int>& nums) -> vector<int> const {
    const auto unique = unordered_set<int> {begin(nums), end(nums)};

    const auto sum_total = accumulate(begin(nums), end(nums), 0);
    const auto sum_current = accumulate(begin(unique), end(unique), 0);

    const auto difference = first_n_sum(nums.size()) - sum_current;
    const auto missing = sum_total - sum_current;

    return {missing, difference};
  }
};