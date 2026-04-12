//https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return gcd(nums[0], nums[n - 1]);
    }
};
