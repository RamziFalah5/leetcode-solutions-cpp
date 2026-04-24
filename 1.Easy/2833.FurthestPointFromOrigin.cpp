// https://leetcode.com/problems/furthest-point-from-origin/description/
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0;
        int l = 0;
        int u = 0;
        for (char c : moves) {
            if (c == 'R')
                r++;
            else if (c == 'L')
                l++;
            else
                u++;
        }

        return abs(r - l) + u;
    }
};
