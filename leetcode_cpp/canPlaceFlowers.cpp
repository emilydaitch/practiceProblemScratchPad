class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); ++i) {
            if(n == 0) return true;
            if(i == 0) {
                if(flowerbed[0] == 0 && flowerbed[1] == 0) {
                    flowerbed[0] = 1;
                    --n;
                }
                else if(i == flowerbed.size() - 1) {
                    if(flowerbed[flowerbed.size() - 2] == 0 && flowerbed[flowerbed.size() - 1] == 0) {
                        flowerbed[flowerbed.size() - 1] = 1;
                        --n;
                    }
                }
                else {
                    if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                        flowerbed[i] = 1;
                        --n;
                    }
                }
            }
        }
        return false;
    }
};
