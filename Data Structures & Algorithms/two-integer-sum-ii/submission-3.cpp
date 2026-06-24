class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lower = 0;
        int upper = numbers.size()-1;

        while(lower < upper){
            int sum =  numbers[lower] + numbers[upper];

            if(sum == target)
                return {lower + 1, upper + 1};
            else if(sum > target)
                upper--;
            else
                lower++;
        }
        return {};
    }
};