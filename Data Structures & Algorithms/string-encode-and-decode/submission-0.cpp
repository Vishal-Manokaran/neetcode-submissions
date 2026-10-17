class Solution {
public:

    string encode(vector<string>& strs) {
        string limiter = "🌍"; 
        string encoded;
        for(string str:strs){
            encoded.append(str);
            encoded.append(limiter);
        }
        return encoded;
    }

    vector<string> decode(string s) {
        string limiter = "🌍"; 
        vector<string> decoded;
        size_t start = 0;
        size_t end = s.find(limiter);
        while(end != string::npos){
            decoded.push_back(s.substr(start, end-start));
            start = end+limiter.length();
            end = s.find(limiter,start);
        }
        // decoded.push_back(s.substr(start));
        return decoded;
    }
};
