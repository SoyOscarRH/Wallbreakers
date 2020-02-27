class Solution {
 public:
  auto arrayPairSum(vector<int>& nums) -> int {
    auto sum = 0;
    sort(begin(nums), end(nums));
    
    for (int i = 0; i < nums.size(); i += 2) {
      sum += nums[i];
    }

    return sum;
  }
};