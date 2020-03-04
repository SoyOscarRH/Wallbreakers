class Solution {
 public:
  int calPoints(const vector<string>& ops) {
    auto a = vector<int> {};

    for (auto& op : ops) {
      const int n = a.size();

      if (op == "C")
        a.pop_back();
      else if (op == "D")
        a.push_back(2 * a.back());
      else if (op == "+")
        a.push_back(a[n - 2] + a[n - 1]);
      else
        a.push_back(stoi(op));
    }

    return accumulate(begin(a), end(a), 0);
  }
};