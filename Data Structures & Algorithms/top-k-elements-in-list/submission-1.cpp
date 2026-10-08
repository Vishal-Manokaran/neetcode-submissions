#include<map>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counts;
        for (int n : nums) {
            counts[n]++;
        }
        vector<int> ret;
        vector<vector<int>> buckets(nums.size()+1);
        for (auto&[item,count]:counts){
            buckets[count].push_back(item);
        }
        for(int i=buckets.size()-1;i>0;i--){
            for(int n:buckets[i]){
                ret.push_back(n);
                if(ret.size()==k){
                    return ret;
                }
            }
        }
    }
};
