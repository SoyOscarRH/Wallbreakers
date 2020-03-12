class Solution {
  using matrix = vector<vector<int>>;

 public:
  bool canFinish(int numCourses, const vector<vector<int>>& prer) {
    auto gragh = matrix(numCourses);
    auto visited = vector<int>(numCourses, 0);

    for (auto x : prer) {
      auto for_this = x[0];
      auto need_this = x[1];
      gragh[need_this].push_back(for_this);
    }

    auto cycle = false;
    for (auto i = 0; i < numCourses and not cycle; ++i) {
      if (not visited[i] == 0) cycle = dfs(i, gragh, visited);
    }

    return not cycle;
  }

  auto dfs(int node, const matrix& gragh, vector<int>& visited) -> bool {
    if (visited[node] == 1) return true;

    visited[node] = true;
    const auto& neighbours = gragh[node];
    for (auto n : neighbours) {
      if (dfs(n, gragh, visited)) return true;
    }

    visited[node] = 2;
    return false;
  }
};