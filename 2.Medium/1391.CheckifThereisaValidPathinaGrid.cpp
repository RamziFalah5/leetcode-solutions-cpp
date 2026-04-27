// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dirs = {{},
                                            {{0, -1}, {0, 1}},
                                            {{-1, 0}, {1, 0}},
                                            {{0, -1}, {1, 0}},
                                            {{0, 1}, {1, 0}},
                                            {{0, -1}, {-1, 0}},
                                            {{0, 1}, {-1, 0}}};

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1)
                return true;

            int type = grid[x][y];

            for (auto& d : dirs[type]) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                if (visited[nx][ny])
                    continue;

                int nextType = grid[nx][ny];

                for (auto& back : dirs[nextType]) {
                    if (nx + back[0] == x && ny + back[1] == y) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        break;
                    }
                }
            }
        }

        return false;
    }
};
