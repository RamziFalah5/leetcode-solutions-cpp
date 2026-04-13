// https://leetcode.com/problems/number-of-beautiful-pairs/
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int f = nums[i];
                while (f / 10 != 0) {
                    f /= 10;
                }

                int l = nums[j] % 10;

                if (__gcd(f, l) == 1)
                    count++;
            }
        }
        return count;
    }
};
