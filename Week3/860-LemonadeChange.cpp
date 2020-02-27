class Solution {
 public:
  auto lemonadeChange(const vector<int>& bills) -> bool {
    auto fiveCount = 0, tenCount = 0, twentyCount = 0;

    for (auto bill : bills) {
      if (bill == 5) ++fiveCount;
      if (bill == 10) ++tenCount;
      if (bill == 20) ++twentyCount;

      while (bill > 5) {
        if (bill > 20 and twentyCount > 0) {
          --twentyCount;
          bill -= 20;
        } else if (bill > 10 and tenCount > 0) {
          --tenCount;
          bill -= 10;
        } else if (bill > 5 and fiveCount > 0) {
          --fiveCount;
          bill -= 5;
        } else
          return false;
      }
    }

    return true;
  }
};