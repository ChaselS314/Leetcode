// First, I only come up with a solution used O(n^2) time
// this below solution is came up with here(https://discuss.leetcode.com/topic/3462/yet-another-way-to-see-what-happens-in-the-o-n-algorithm)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxarea = 0;
        while(left < right)
        {
            auto area = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
            maxarea = maxarea > area ? maxarea : area;
            if(height[left] < height[right])
                left ++;
            else
                right --;
        }
        return maxarea;
    }
};
