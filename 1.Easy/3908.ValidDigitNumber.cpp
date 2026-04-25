// https://leetcode.com/problems/valid-digit-number/description/

class Solution {
public:
    bool validDigit(int n, int x) {
        bool is1 = false;
        bool is2 = false;
        while (n != 0) {
            if (n / 10 == 0) {
                if (n % 10 != x)
                    is2 = true;
            }
            int num = n % 10;
            if (num == x)
                is1 = true;
            n /= 10;
        }
        if (is1 == true && is2 == true)
            return true;
        else
            return false;
    }
};
