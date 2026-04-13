// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int m = *max_element(candies.begin(), candies.end());
    int n = candies.size();
    vector<bool> v(n, false);
    for (int i = 0; i < n; i++)
    {
        if (candies[i] + extraCandies >= m)
            v[i] = true;
    }
    return v ;
}
};
