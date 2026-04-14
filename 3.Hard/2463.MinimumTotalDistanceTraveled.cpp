// https://leetcode.com/problems/minimum-total-distance-traveled/description/

class Solution {
public:
    long long INF = (long long)4e18;
    vector<vector<long long>> memo;

    long long solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory) {
        if (i == (int)robot.size()) return 0;
        if (j == (int)factory.size()) return INF;

        if (memo[i][j] != -1) return memo[i][j];

        long long ans = solve(i, j + 1, robot, factory);

        long long cost = 0;
        long long pos = factory[j][0];
        int limit = factory[j][1];

        for (int k = 1; k <= limit && i + k - 1 < (int)robot.size(); k++) {
            cost += llabs((long long)robot[i + k - 1] - pos);
            ans = min(ans, cost + solve(i + k, j + 1, robot, factory));
        }

        return memo[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        memo.assign(n, vector<long long>(m, -1));

        return solve(0, 0, robot, factory);
    }
};
