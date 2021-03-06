class Solution {
 public:
  auto twoSum(vector<int>& nums, int target) -> vector<int> {
    auo toFind = map<int, int> {};

    for (int i {}; i < nums.size(); ++i) {
      int numToFind = target - nums[i];
      if (toFind.find(numToFind) != toFind.end()) return {toFind[numToFind], i};

      toFind[nums[i]] = i;
    }

    return {0, 0};
  }
};