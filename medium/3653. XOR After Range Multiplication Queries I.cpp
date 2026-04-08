//https://leetcode.com/problems/xor-after-range-multiplication-queries-i/

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1000000007LL;

        for (long long i = 0; i < (long long)queries.size(); i++) {
            long long l = queries[i][0];
            long long r = queries[i][1];
            long long k = queries[i][2];
            long long v = queries[i][3];

            for (long long idx = l; idx <= r; idx += k) {
                nums[idx] = (long long)nums[idx] * v % MOD;
            }
        }

        int ans = 0;
        for (long long i = 0; i < (long long)nums.size(); i++) {
            ans ^= nums[i];
        }

        return ans;
    }
};
