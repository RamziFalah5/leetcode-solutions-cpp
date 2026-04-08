//https://leetcode.com/problems/robot-return-to-origin/

class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        vector<int> v(26, 0);

        for (int i = 0; i < n; i++) {
            v[moves[i] - 'A']++;
        }

        return v[20] == v[3] && v[11] == v[17];
    }
};
