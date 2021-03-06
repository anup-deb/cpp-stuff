class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_area = 0;
        while (left <= right) {
            int area = (right-left)*(min(height[left], height[right]));
            max_area = max(area, max_area);
            if (height[left] < height[right]) {
                left++;
            } else if (height[right] < height[left]) {
                right--;
            } else {
                left++;
                right--;
            }
        }
        return max_area;
    }
};