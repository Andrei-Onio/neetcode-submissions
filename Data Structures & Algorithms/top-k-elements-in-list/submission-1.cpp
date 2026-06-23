class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<pair<int,int>> groups; // {frequency, value}

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int count = 1;
            visited[i] = true;

            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                    visited[j] = true;
                }
            }
            groups.push_back({count, nums[i]});
        }

        sort(groups.begin(), groups.end()); // sort by frequency

        int m = groups.size();
        k = min(k, m);   // prevent underflow

        vector<int> result;
        for (int i = m - 1; i >= m - k; i--) {
            result.push_back(groups[i].second);
        }
        return result;
    }
};
