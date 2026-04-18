// https://leetcode.com/problems/mirror-distance-of-an-integer/description/

class Solution {
public:
    long long reverseNumber(long long n) {
        long long rev = 0;

        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }

        return rev;
    }
    int mirrorDistance(int n) { return abs(reverseNumber(n) - n); }
};
