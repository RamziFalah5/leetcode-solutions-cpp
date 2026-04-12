// https://leetcode.com/problems/number-of-common-factors/description/

class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 0;
        int g = gcd(a, b);
        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                count++;
                if (i != g / i)
                    count++;
            }
        }
        return count;
    }
};
