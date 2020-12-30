class Solution {
public:
    int trap(vector<int>& height) {
        int min_left = 0;
        int left[height.size()];
        int right[height.size()];
        for (size_t i = 0; i < height.size(); ++i) {
            if (i == 0) {
                left[i] = height[i];
            } else {
                left[i] = max(left[i-1], height[i]);
            }
            
        }
        for (int i = height.size()-1; i >= 0; --i) {
            if (i == height.size()-1) {
                right[i] = height[i];
            } else {
                right[i] = max(right[i+1], height[i]);
            }
        }
        int water = 0;
        for (size_t i = 0; i < height.size(); ++i) {
            water += min(left[i], right[i]) - height[i];
        }
        return water;
    }
};