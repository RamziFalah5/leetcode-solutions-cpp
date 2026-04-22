// https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for (string& q : queries) {
            bool ok = false;

            for (string& d : dictionary) {
                int diff = 0;

                for (int i = 0; i < q.size(); i++) {
                    if (q[i] != d[i]) {
                        diff++;
                        if (diff > 2) break;
                    }
                }

                if (diff <= 2) {
                    ok = true;
                    break;
                }
            }

            if (ok) ans.push_back(q);
        }

        return ans;
    }
};
