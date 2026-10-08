#include<map>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> cmapp;
        for (int n : nums) {
            if (cmapp.contains(n)) {
                cmapp[n]++;
            } else
                cmapp[n] = 1;
        }
        vector<pair<int, int>> pairs(cmapp.begin(), cmapp.end());
        sort(pairs.begin(), pairs.end(), [](pair<int,int> a, pair<int,int> b) { return a.second > b.second; });
        vector<int> ret;
        for(int i=0;i<k;i++){
            ret.push_back(pairs[i].first);
        }
        return ret;
    }
};
