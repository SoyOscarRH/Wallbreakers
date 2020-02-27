class Solution {
 public:
  auto peakIndexInMountainArray(const vector<int>& A) -> int {
    int l = 0, r = A.size() - 1;

    while (l <= r) {
      auto mid = l + (r - l) / 2;
      if (A[mid] > A[mid + 1] and A[mid] > A[mid - 1]) return mid;
      if (A[mid] < A[mid + 1]) l = mid + 1;
      if (A[mid] > A[mid + 1]) r = mid - 1;
    }
    
    return -1;
  }
};