class Solution {
public:

    string encode(vector<string>& strs) {
        string coded = "";
        for(string s: strs){
            coded += s + '~';
        }
        return coded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string sub="";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '~'){
                sub += s[i];
                continue;
            }
            else{
                result.push_back(sub);
                sub = "";
            }
        }
        return result;
    }
};
