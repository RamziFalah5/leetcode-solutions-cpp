// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        vector<pair<int, int>> v;
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            int s = count(mat[i].begin(), mat[i].end(),1);
            v.push_back({s, i});
        }
        sort(v.begin(), v.end());
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = v[i].second;
        }
        return ans ;
    }
};
