#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <thread>
#include <vector>

template <typename it>
void my_mergesort(it first, it last) {
  if (last - first > 1) {
    auto middle = first + (last - first) / 2;
    auto l = std::thread([=]() { my_mergesort(first, middle); });
    auto r = std::thread([=]() { my_mergesort(middle, last); });
    l.join();
    r.join();

    using val = typename std::iterator_traits<it>::value_type;
    std::inplace_merge(first, middle, last, std::less<val> {});
  }
}

template <typename it>
void mergesort(it first, it last) {
  my_mergesort(first, last);
}

int main() {
  // use c++11
  using namespace std;
  auto v = vector<int> {12, 342, 1, 2, 341, 3, 4, 9, 8, 7};
  mergesort(begin(v), end(v));
  for (auto x : v) cout << x << " ";
  cout << endl;

  return 0;
}