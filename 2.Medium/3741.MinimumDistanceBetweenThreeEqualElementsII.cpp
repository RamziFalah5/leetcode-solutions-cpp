//https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int ans = INT_MAX;

        for (int i = 0; i < (int)nums.size(); i++) {
            pos[nums[i]].push_back(i);

            int sz = pos[nums[i]].size();
            if (sz >= 3) {
                int left = pos[nums[i]][sz - 3];
                int right = pos[nums[i]][sz - 1];
                ans = min(ans, 2 * (right - left));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
