class Solution {
 public:
  vector<int> nextGreaterElement(const vector<int>& nums1,
                                 const vector<int>& nums2) {
    unordered_map<int, int> idx2 {};
    for (size_t i {}; i < nums2.size(); ++i) idx2[nums2[i]] = i;

    vector<int> result(nums1.size());
    int i {};
    for (auto num : nums1) {
      auto candidate {nums2.begin() + idx2[num]};
      while (candidate != end(nums2) and *candidate <= num) ++candidate;

      if (candidate == end(nums2))
        result[i++] = -1;
      else
        result[i++] = *candidate;
    }

    return result;
  }
};