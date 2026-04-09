//https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/description/
class Solution {
    static constexpr long long mod = 1000000007LL;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sq = sqrt(n) + 1;

        vector<long long> mult(n, 1);
        vector<vector<array<int, 3>>> small(sq + 1);

        unordered_map<int, long long> inv;

        auto getInv = [&](int x) -> long long {
            if (inv.count(x))
                return inv[x];
            return inv[x] = power(x, mod - 2);
        };

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            if (k > sq) {
                for (int i = l; i <= r; i += k) {
                    mult[i] = (mult[i] * v) % mod;
                }
            } else {
                small[k].push_back({l, r, v});
            }
        }

        for (int k = 1; k <= sq; k++) {
            if (small[k].empty())
                continue;

            vector<vector<array<int, 3>>> groups(k);

            for (auto& cur : small[k]) {
                int l = cur[0];
                int r = cur[1];
                int v = cur[2];

                int rem = l % k;
                int st = l / k;
                int en = st + (r - l) / k;

                groups[rem].push_back({st, en, v});
            }

            for (int rem = 0; rem < k; rem++) {
                if (rem >= n || groups[rem].empty())
                    continue;

                int len = (n - 1 - rem) / k + 1;
                vector<long long> diff(len + 1, 1);

                for (auto& cur : groups[rem]) {
                    int l = cur[0];
                    int r = cur[1];
                    int v = cur[2];

                    diff[l] = (diff[l] * v) % mod;
                    if (r + 1 <= len) {
                        diff[r + 1] = (diff[r + 1] * getInv(v)) % mod;
                    }
                }

                long long now = 1;
                for (int i = 0, idx = rem; i < len; i++, idx += k) {
                    now = (now * diff[i]) % mod;
                    mult[idx] = (mult[idx] * now) % mod;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long val = (1LL * nums[i] * mult[i]) % mod;
            ans ^= (int)val;
        }

        return ans;
    }
};
