// https://leetcode.com/problems/closest-equal-element-queries/description/

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int t = nums.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < t; i++) {
            m[nums[i]].push_back(i);
        }
        vector<int> best(t, -1);
        for (auto& a : m) {
            int k = a.first;
            vector<int>& now = a.second;
            int lnow = now.size();
            if (lnow >= 2) {
                for (int i = 0; i < lnow; i++) {
                    int num = now[i];
                    int next = (i + 1) % lnow;
                    next = now[next];
                    int prev = (i - 1 + lnow) % lnow;
                    prev = now[prev];
                    int mn1 = min(abs(num - next), t - abs(num - next));
                    int mn2 = min(abs(num - prev), t - abs(num - prev));
                    best[num] = min(mn1, mn2);
                }
            }
        }
        vector<int> ans;
        for (int i : queries) {
            ans.push_back(best[i]);
        }
        return ans;
    }
};
