//https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/

class Solution {
public:
    long long dist(long long a, long long b) {
        if (a == 26 || b == 26)
            return 0;

        long long x1 = a / 6, y1 = a % 6;
        long long x2 = b / 6, y2 = b % 6;

        return llabs(x1 - x2) + llabs(y1 - y2);
    }

    int minimumDistance(string word) {
        const long long INF = 1e18;

        vector<vector<long long>> dp(27, vector<long long>(27, INF));
        dp[26][26] = 0;

        for (char c : word) {
            long long cur = c - 'A';
            vector<vector<long long>> nextDp(27, vector<long long>(27, INF));

            for (long long f1 = 0; f1 <= 26; f1++) {
                for (long long f2 = 0; f2 <= 26; f2++) {
                    if (dp[f1][f2] == INF)
                        continue;

                    nextDp[cur][f2] =
                        min(nextDp[cur][f2], dp[f1][f2] + dist(f1, cur));
                    nextDp[f1][cur] =
                        min(nextDp[f1][cur], dp[f1][f2] + dist(f2, cur));
                }
            }

            dp = move(nextDp);
        }

        long long ans = INF;
        for (long long i = 0; i <= 26; i++) {
            for (long long j = 0; j <= 26; j++) {
                ans = min(ans, dp[i][j]);
            }
        }

        return (int)ans;
    }
};
