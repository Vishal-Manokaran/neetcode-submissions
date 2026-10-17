class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zero_count = 0;
        for (int num : nums) {
            if (num != 0)
                product *= num;
            else {
                zero_count++;
                if (zero_count > 1) {
                    return vector<int>(nums.size(), 0);
                }
            }
        }
        vector<int> results(nums.size());
        for (size_t i = 0; i < nums.size(); i++) {
            if (zero_count == 1)
                results[i] = (nums[i] == 0) ? product : 0;
            else
                results[i] = product / nums[i];
        }
        return results;
    }
};
