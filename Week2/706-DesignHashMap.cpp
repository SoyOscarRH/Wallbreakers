class MyHashMap {
  vector<list<pair<int, int>>> m_data;
  size_t m_size = 10000;

public:
  MyHashMap() { m_data.resize(m_size); }

  void put(int key, int value) {
    auto &list = m_data[key % m_size];

    for (auto &[key_c, value_c] : list) {
      if (key_c == key) {
        value_c = value;
        return;
      }
    }

    list.emplace_back(key, value);
  }

  int get(int key) {
    const auto &list = m_data[key % m_size];

    for (const auto &[key_c, value_c] : list) {
      if (key_c == key) {
        return value_c;
      }
    }

    return -1;
  }

  void remove(int key) {
    auto &list = m_data[key % m_size];
    list.remove_if([key](const auto n) { return n.first == key; });
  }
};