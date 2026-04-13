// https://leetcode.com/problems/can-place-flowers/description/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        if (l > 1) {
            if (flowerbed[0] == 0 && flowerbed[1] == 0) {
                n--;
                flowerbed[0] = 1;
            }
        }
        for (int i = 1; i < l - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 &&
                flowerbed[i] == 0) {
                flowerbed[i] = 1;

                n--;
            }
        }
        if (l > 1) {
            if (flowerbed[l - 1] == 0 && flowerbed[l - 2] == 0) {
                n--;
            }
        }
        if(l==1 && flowerbed[0]==0 && n<=1)
        n-- ;
        return n <= 0;
    }
};
