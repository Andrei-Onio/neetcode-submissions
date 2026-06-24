class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++) {

            int diff = target - numbers[i];

            int lower = i + 1;
            int upper = numbers.size()-1;

            while (lower <= upper) {
                int mid = (lower + upper) / 2;

                if (numbers[mid] == diff) {
                    return {i + 1, mid + 1};
                }
                else if (numbers[mid] > diff) {
                    upper = mid - 1;
                } 
                else {
                    lower = mid + 1;
                }
            }
        }
        return {};
    }
};