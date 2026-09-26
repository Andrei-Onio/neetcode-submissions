class Solution {
public:
    typedef struct node {
        int temp;
        int pos;
    } great;

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int i, diff;
        stack<great> greater;
        vector<int> result(temperatures.size(), 0);

        if(temperatures.size() == 1) {
            return result;
        }
        
        for(i = 0; i < temperatures.size() - 1; i++) {
            if(temperatures[i] < temperatures[i + 1]) {
                while(!greater.empty() && temperatures[i + 1] > greater.top().temp) {
                    result[greater.top().pos] = i + 1 - greater.top().pos;
                    greater.pop();
                }
                result[i] = 1;
            } else {
                greater.push({temperatures[i], i});
            }
        }

        result[i] = 0;

        return result;
    }
};