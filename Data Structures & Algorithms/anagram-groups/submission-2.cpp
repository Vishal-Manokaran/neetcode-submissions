class Solution {
   public:
    unordered_map<char, int> str_to_dict(string s) {
        unordered_map<char, int> d = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0},
                                      {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0},
                                      {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0},
                                      {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0},
                                      {'y', 0}, {'z', 0}};
        for (char i : s) d[i]++;
        return d;
    }
    bool isAnagram(string s1, string s2) {
        return str_to_dict(s1) == str_to_dict(s2) ? true : false;
    }
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
