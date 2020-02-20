class Trie {
  array<Trie*, 26> nodes {};
  bool end = false;

 public:
  Trie() {}

  void insert(const string& word) {
    auto* current = this;
    for (char c : word) {
      if (current->nodes[c - 'a'] == nullptr)
        current->nodes[c - 'a'] = new Trie();

      current = current->nodes[c - 'a'];
    }

    current->end = true;
  }

  bool search(const string& word) const {
    auto* current = this;
    for (char c : word) {
      if (current == nullptr) return false;
      current = current->nodes[c - 'a'];
    }

    return current and current->end;
  }

  bool startsWith(const string& prefix) const {
    auto* current = this;
    for (char c : prefix) {
      if (current == nullptr) return false;
      current = current->nodes[c - 'a'];
    }

    return current;
  }
};
