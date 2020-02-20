class MyHashSet {
  vector<list<int>> m_data;
  size_t m_size = 1000;

public:
  MyHashSet() { m_data.resize(m_size); }

  void add(int key) {
    auto &list = m_data[key % m_size];

    for (const auto &key_c : list) {
      if (key_c == key)
        return;
    }

    list.emplace_back(key);
  }

  bool contains(int key) const {
    const auto &list = m_data[key % m_size];

    for (const auto &key_c : list) {
      if (key_c == key)
        return true;
    }

    return false;
  }

  void remove(int key) {
    auto &list = m_data[key % m_size];
    list.remove_if([key](const auto &key_t) { return key_t == key; });
  }
};
