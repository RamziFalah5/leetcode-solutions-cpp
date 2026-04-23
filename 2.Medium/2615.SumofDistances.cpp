// https://leetcode.com/problems/sum-of-distances/
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long, vector<long long>> m;
        long long n = nums.size();

        for (long long i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for (auto& a : m) {
            vector<long long>& pos = a.second;
            long long k = pos.size();

            if (k == 1)
                continue;

            vector<long long> pref(k, 0);
            pref[0] = pos[0];

            for (long long i = 1; i < k; i++) {
                pref[i] = pref[i - 1] + pos[i];
            }

            for (long long i = 0; i < k; i++) {
                long long leftSum = 0;
                long long rightSum = 0;

                if (i > 0) {
                    leftSum = i * pos[i] - pref[i - 1];
                }

                if (i + 1 < k) {
                    long long sumRight = pref[k - 1] - pref[i];
                    rightSum = sumRight - (k - i - 1) * pos[i];
                }

                ans[pos[i]] = leftSum + rightSum;
            }
        }

        return ans;
    }
};
