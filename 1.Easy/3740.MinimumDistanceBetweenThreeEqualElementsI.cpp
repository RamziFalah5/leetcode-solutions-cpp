//https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        long long ans = LLONG_MAX;

        for (int i = 0; i < (int)nums.size(); i++) {
            pos[nums[i]].push_back(i);

            int sz = (int)pos[nums[i]].size();
            if (sz >= 3) {
                long long first = pos[nums[i]][sz - 3];
                long long third = pos[nums[i]][sz - 1];

                ans = min(ans, 2LL * (third - first));
            }
        }

        return (ans == LLONG_MAX ? -1 : (int)ans);
    }
};
