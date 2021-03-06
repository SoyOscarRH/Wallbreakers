class Solution {
 public:
  auto minDistance(const string& word1, const string& word2) -> int {
    int m = word1.size(), n = word2.size();
    auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) dp[i][0] = i;
    for (int j = 1; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        }
      }
    }

    return dp[m][n];
  }
};