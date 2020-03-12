class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int count = 0, repeat = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] != 1) continue;
          if (i != 0 and grid[i - 1][j] == 1) repeat++;
          if (j != 0 and grid[i][j - 1] == 1) repeat++;
          count++;
      }
    }
    return 4 * count - repeat * 2;
  }
};