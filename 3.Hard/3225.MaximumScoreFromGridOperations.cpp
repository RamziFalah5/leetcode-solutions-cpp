// https://leetcode.com/problems/maximum-score-from-grid-operations/description/

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int H = n + 1;
        const long long NEG = -4e18;

        vector<vector<long long>> pref(n, vector<long long>(H, 0));

        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                pref[col][row + 1] = pref[col][row] + grid[row][col];
            }
        }

        auto gain = [&](int col, int ownHeight,
                        int maxNeighborHeight) -> long long {
            if (maxNeighborHeight <= ownHeight)
                return 0;
            return pref[col][maxNeighborHeight] - pref[col][ownHeight];
        };

        vector<vector<long long>> dp(H, vector<long long>(H, NEG));

        for (int h0 = 0; h0 < H; h0++) {
            dp[0][h0] = 0;
        }

        for (int col = 1; col < n; col++) {
            vector<vector<long long>> ndp(H, vector<long long>(H, NEG));

            int scoreCol = col - 1;

            for (int prev = 0; prev < H; prev++) {
                vector<long long> prefixMax(H, NEG);
                long long best = NEG;

                for (int left = 0; left < H; left++) {
                    best = max(best, dp[left][prev]);
                    prefixMax[left] = best;
                }

                vector<long long> suffixMax(H + 1, NEG);
                best = NEG;

                for (int left = H - 1; left >= 0; left--) {
                    best =
                        max(best, dp[left][prev] + gain(scoreCol, prev, left));
                    suffixMax[left] = best;
                }

                for (int cur = 0; cur < H; cur++) {
                    long long op1 = prefixMax[cur] + gain(scoreCol, prev, cur);
                    long long op2 = suffixMax[cur + 1];

                    ndp[prev][cur] = max(op1, op2);
                }
            }

            dp = ndp;
        }

        long long ans = 0;
        int lastCol = n - 1;

        for (int left = 0; left < H; left++) {
            for (int last = 0; last < H; last++) {
                ans = max(ans, dp[left][last] + gain(lastCol, last, left));
            }
        }

        return ans;
    }
};
