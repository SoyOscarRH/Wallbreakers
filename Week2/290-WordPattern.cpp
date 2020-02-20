class Solution {
 public:
  auto wordPattern(const string& pattern, const string& str) {
    auto data = std::stringstream {str};

    auto get_string = map<char, string> {};
    auto get_symbol = map<string, char> {};
    auto current = string {};

    for (const auto symbol : pattern) {
      data >> current;

      if (not get_string.count(symbol) and not get_symbol.count(current)) {
        get_string[symbol] = current;
        get_symbol[current] = symbol;
      } else if (get_string[symbol] != current)
        return false;
      else if (get_symbol[current] != symbol)
        return false;
    }

    return data.eof();
  }
};