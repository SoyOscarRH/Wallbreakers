class Solution {
 public:
  int rob(vector<int>& nums) {
    auto robber = [&](const int start, const int end) {
      int previous = 0, current = 0;

      for (auto i = start; i <= end; ++i) {
        auto temporal = max(previous + nums[i], current);
        previous = current;
        current = temporal;
      }

      return current;
    };

    int n = nums.size();
    if (n < 2) return n ? nums[0] : 0;
    return max(robber(0, n - 2), robber(1, n - 1));
  }
};