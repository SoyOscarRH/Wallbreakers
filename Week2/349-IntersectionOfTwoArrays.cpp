class Solution {
 public:
  auto intersection(const vector<int>& nums1, const vector<int>& nums2)
      -> vector<int> {
    const auto s1 = unordered_set<int>(begin(nums1), end(nums1));
    const auto s2 = unordered_set<int>(begin(nums2), end(nums2));

    auto result = vector<int> {};
    for (const auto& element : s1) {
      if (s2.count(element)) result.push_back(element);
    }

    return result;
  }
};