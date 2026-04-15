// https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums;
        vector<int> bs(n);
        bs[0] = nums[0];
        for (int i = 1; i < n; i++) {
            bs[i] = bs[i - 1] * nums[i];
        }
        vector<int> ss(n);
        ss[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ss[i] = ss[i + 1] * nums[i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                ans[i] = ss[i + 1];
            else if (i == n - 1)
                ans[i] = bs[i - 1];
            else
                ans[i] = ss[i + 1] * bs[i - 1];
        }
        return ans;
    }
};
