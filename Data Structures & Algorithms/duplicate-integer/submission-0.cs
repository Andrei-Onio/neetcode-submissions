public class Solution {
    public bool hasDuplicate(int[] nums) {
        int i, j, l = nums.Length;
        for(i=0; i<l-1; i++){
            for(j=i+1; j<l; j++){
                if(nums[i]==nums[j])
                    return true;
            }
        }
        return false;
    }
}