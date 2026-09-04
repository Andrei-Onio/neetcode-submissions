class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int max = (right - left) * std::min(heights[left], heights[right]);
        
        while(left < right) {

            if(heights[left] < heights[right]) {
                left++;
            } else {
                right --;
            }

            int area = (right - left) * std::min(heights[left], heights[right]);

            max = area > max ? area : max;

        }

        return max;
    }
};
