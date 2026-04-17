// https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/

class Solution {
public:
    long long rev(long long x) {
        long long r = 0;
        while (x > 0) {
            r = r * 10 + (x % 10);
            x /= 10;
        }
        return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<long long, int> last;
        int ans = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (last.count(nums[i])) {
                ans = min(ans, i - last[nums[i]]);
            }
            long long reversedValue = rev(nums[i]);
            last[reversedValue] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
