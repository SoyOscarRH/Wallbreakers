class Solution {
 public:
  using matrix = vector<vector<int>>;
  auto findMinArrowShots(matrix& points) -> int {
    sort(begin(points), end(points),
         [](const auto& i, const auto& j) { return i[1] < j[1]; });

    bool isBurst = false;
    auto lastEnd = 0, count = 0;

    for (auto const& p : points) {
      if (isBurst and p[0] <= lastEnd) continue;

      isBurst = true;
      lastEnd = p[1];
      ++count;
    }

    return count;
  }
};