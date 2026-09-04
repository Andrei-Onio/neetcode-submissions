class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int max = (right - left) * std::min(heights[left], heights[right]);
        
        if(heights[left] <= heights[right]) {
            left++;
        } else {
            right --;
        }

        while(left < right) {
            int area = (right - left) * std::min(heights[left], heights[right]);

            max = area > max ? area : max;

            if(heights[left] < heights[right]) {
                left++;
            } else {
                right --;
            }

        }

        return max;
    }
};
