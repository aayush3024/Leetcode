class Solution {
public:
    int m, n;
    vector<vector<int>> vis;

    long long dfs(int i, int j, vector<vector<int>>& grid) {
        vis[i][j] = 1;

        long long sum = grid[i][j];

        vector<vector<int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        for (auto& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];

            if (x >= 0 && x < m && y >= 0 && y < n &&
                grid[x][y] > 0 && !vis[x][y]) {
                sum += dfs(x, y, grid);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vis.assign(m, vector<int>(n, 0));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    long long sum = dfs(i, j, grid);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};