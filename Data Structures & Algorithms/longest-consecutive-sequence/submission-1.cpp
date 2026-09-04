class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2){
            return nums.size();
        }

        std::sort(nums.begin(), nums.end());
        int len_max = 1, i = 0, len = 1;

        for(i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1] + 1) {
                len++;
            } else if(nums[i] == nums[i-1]) {
                ;
            } else {
                if (len > len_max) {
                    len_max = len;
                }
                len = 1;
                continue;
            }
        }
        if (len > len_max) {
            len_max = len;
        }
        return len_max;

    }
};
