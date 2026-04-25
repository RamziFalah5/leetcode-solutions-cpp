// https://leetcode.com/problems/compare-sums-of-bitonic-parts/description/

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[peak]) {
                peak = i;
            }
        }

        long long ascSum = 0, descSum = 0;

        for (int i = 0; i <= peak; i++) {
            ascSum += nums[i];
        }

        for (int i = peak; i < n; i++) {
            descSum += nums[i];
        }

        if (ascSum > descSum)
            return 0;
        if (ascSum < descSum)
            return 1;
        return -1;
    }
};
