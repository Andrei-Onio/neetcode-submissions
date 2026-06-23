#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<string> strings = strs;
        std::vector<vector<string>> result;
        for(int i = 0; i < strings.size(); i++){
            std::sort(strings[i].begin(), strings[i].end() );
        }
        for(int i = 0; i < strings.size(); i++){
            std::vector<string> group;
            if(strs[i]!="*"){
                group.push_back(strs[i]);
                strs[i] = "*";
            }
            for(int j = i + 1; j < strings.size(); j++){
                if(strings[i]==strings[j] && strs[j]!="*"){
                    group.push_back(strs[j]);
                    strs[j] = "*";
                }
            }
            result.push_back(group);
        }
        for(int i = 0; i < result.size(); i++){
            if(result[i].empty()){
                result.erase(result.begin() + i);
                i--;
            }
   
        }
        return result;
    }
};
