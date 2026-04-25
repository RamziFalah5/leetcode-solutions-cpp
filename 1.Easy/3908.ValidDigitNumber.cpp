// https://leetcode.com/problems/valid-digit-number/description/

class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        char digit = x + '0';

        return s.find(digit) != string::npos && s[0] != digit;
    }
};
