class Solution {
 public:
  auto search(const std::vector<int>& nums, const int target) -> int {
    auto start = nums.begin(), end = nums.end() - 1;

    while (start <= end) {
      const auto middle = start + (end - start) / 2;

      if (*middle == target) return middle - nums.begin();

      if (target < *middle)
        end = middle - 1;
      else
        start = middle + 1;
    }

    return -1;
  }
};