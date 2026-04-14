// https://leetcode.com/problems/reverse-words-in-a-string/description/
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans = "";
        vector<string> v;
        while (ss >> word) {
            v.push_back(word);
        }
        reverse(v.begin(), v.end());
        bool is = true;
        for (auto& w : v) {
            if (!is)
                ans += " ";
            ans += w;
            is = false;
        }
        return ans;
    }
};
