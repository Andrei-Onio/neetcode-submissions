class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int pro = 1, zero = 0, zero_pos = -1;
        for(int i = 0;  i < nums.size(); i++){
            if (nums[i] == 0){
                zero ++;
                zero_pos = i;
                if(zero > 1){
                    break;
                }
            }
            else{
                pro *= nums[i];
            }
        }
        
        if(zero > 1){
            for(int i = 0; i < nums.size(); i++){
                result.push_back(0);
            }
        }
        else if(zero == 1){
            for(int i = 0; i < nums.size(); i++){
                if(i == zero_pos){
                    result.push_back(pro);
                }
                else
                    result.push_back(0);
            }
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                result.push_back((pro/nums[i]));
            }
        }
        
        return result;
    }
};
