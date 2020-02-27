class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    auto max_profit = 0;
    auto min_price = numeric_limits<int>::max();

    for (const auto price : prices) {
      min_price = min(min_price, price);
      max_profit = max(max_profit, price - min_price);
    }

    return max_profit;
  }
};
