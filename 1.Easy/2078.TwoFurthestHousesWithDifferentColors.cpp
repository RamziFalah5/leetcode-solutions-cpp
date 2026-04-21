// https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int j = 0;
        int mx1 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (colors[j] != colors[i]) {
                mx1 = abs(j - i);
                break;
            }
        }

        int m = n - 1;
        int mx2 = 0;
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[m]) {
                mx2 = abs(m - i);
                break;
            }
        }
        return max(mx1, mx2);
    }
};
