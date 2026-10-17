class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> results;
        int product = 1, zero_count = 0;
        for (int num : nums) {
            if (num != 0)
                product = product * num;
            else {
                zero_count++;
                if(zero_count>1){
                    return vector<int>(nums.size(),0);
                }
            }
        }
        // std::cout << product << endl;
        for (size_t i = 0; i < nums.size(); i++) {
            if(zero_count==1){
                if(nums[i]!=0)
                    results.push_back(0);
                else
                    results.push_back(product);
            }
            else
                results.push_back(product/nums[i]);
        }
        return results;
    }
};
