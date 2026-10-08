#include <string>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> compliment;
        int c = 0;
        for (int i : nums) {
            compliment[i] = c;
            c++;
        }
        c = 0;
        for (int i : nums) {
            if (compliment.contains(target - i) && c != compliment[target - i]) {
                return vector<int>{c, compliment[target - i]};
            }
            c++;
        }
        return vector<int>{0, 0};
    }
};
