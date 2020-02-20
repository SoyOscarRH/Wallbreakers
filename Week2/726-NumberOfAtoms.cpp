class Solution {
 public:
  auto countOfAtoms(string formula) -> string {
    auto i = 0;
    const auto data = parseElement(formula, i);

    auto result = string {};
    for (auto const& [name, value] : data) {
      result += name;
      if (value > 1) result += to_string(value);
    }

    return result;
  }

  auto parseElement(string& formula, int& i) -> map<string, int> {
    auto data = map<string, int> {};

    while (i < formula.size() and formula[i] != ')') {
      if (formula[i] == '(') {
        auto data_c = parseElement(formula, ++i);
        for (auto const& [n, v] : data_c) data[n] += v;
      } else {
        auto atom = string {};
        atom += formula[i++];
        while (i < formula.size() && isalpha(formula[i]) && islower(formula[i]))
          atom += formula[i++];
        data[atom] += parseInt(formula, i);
      }
    }

    if (i < formula.size() && formula[i] == ')') {
      int n = parseInt(formula, ++i);
      for (auto& p : cnt) p.second *= n;
    }

    return data;
  }

  auto parseInt(string& s, int& i) -> int {
    int n = 0;
    while (i < s.length() && isdigit(s[i])) n = 10 * n + s[i++] - '0';
    return n == 0 ? 1 : n;
  }
};