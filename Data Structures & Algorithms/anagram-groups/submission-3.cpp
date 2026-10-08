class Solution {
   public:
    string str_to_encode(string s) {
        string deflt = "00000000000000000000000000";
        for (char i:s) {
            deflt[i-'a']++;
        }
        return deflt;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string,vector<string>> retdict;
        for(string str:strs){
            if(retdict.contains(str_to_encode(str))){
                retdict[str_to_encode(str)].push_back(str);
            }
            else{
                retdict[str_to_encode(str)] = vector<string>{str};
            }
        }
        for(auto& [key,value]:retdict){
            ret.push_back(value);
        }
        return ret;
    }
};
