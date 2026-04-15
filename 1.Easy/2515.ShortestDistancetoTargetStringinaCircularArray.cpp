// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        if (words[startIndex] == target)
            return 0;

        int b1 = (startIndex + 1) % n;
        bool is1 = false;
        int count1 = 1;

        int b2 = (startIndex - 1 + n) % n;
        bool is2 = false;
        int count2 = 1;

        while (b2 != startIndex) {
            if (words[b2] == target) {
                is2 = true;
                break;
            }
            b2 = (b2 - 1 + n) % n;
            count2++;

            if (words[b1] == target) {
                is1 = true;
                break;
            }
            b1 = (b1 + 1) % n;
            count1++;
        }
        if (!is1 && !is2)
            return -1;
        else if (is1 == true && is2 == false)
            return count1;
        else if (is1 == false && is2 == true)
            return count2;
        else
            return min(count1, count2);
    }
};
