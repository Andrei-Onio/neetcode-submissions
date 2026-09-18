class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;

        if(height.size() < 3){
            return water;
        }

        int left = 0, right = height.size() - 1;
        while(height[left] < height[left + 1]) {
            left++;
        }

        while(height[right] < height[right - 1]){
            right--;
            if(right == 0){
                return water;
            } 
        }

        if(left == right) {
            return water;
        }

        int current, minimum;
        while(left < right){
            if(left + 1 == right) {
                return water;
            }
            minimum = min(height[left], height[right]);

            if(height[left] <= height[right]) {
                current = left + 1;
                while(height[current] < minimum) {
                    water += minimum - height[current];
                    current++;
                }
                left = current;
            } else {
                current = right - 1;
                while(height[current] < minimum) {
                    water += minimum - height[current];
                    current--;
                }
                right = current;
            }
        }

        return water;        
    }
};
