// https://leetcode.com/problems/closest-equal-element-queries/description/

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        long long n = nums.size();
        unordered_map<int, vector<long long>> pos;

        for (long long i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<int> best(n, -1);

        for (auto& it : pos) {
            vector<long long>& v = it.second;
            long long sz = v.size();

            if (sz == 1) {
                best[v[0]] = -1;
                continue;
            }

            for (long long i = 0; i < sz; i++) {
                long long cur = v[i];
                long long prv = v[(i - 1 + sz) % sz];
                long long nxt = v[(i + 1) % sz];

                long long d1 = llabs(cur - prv);
                d1 = min(d1, n - d1);

                long long d2 = llabs(cur - nxt);
                d2 = min(d2, n - d2);

                best[cur] = (int)min(d1, d2);
            }
        }

        vector<int> ans;
        for (int idx : queries) {
            ans.push_back(best[idx]);
        }

        return ans;
    }
};
