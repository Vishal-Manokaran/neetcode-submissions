class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return nums.size();
        sort(nums.begin(), nums.end());
        int maxCount = 0;
        int sessionCount = 1;
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + 1 == nums[i + 1]) {
                sessionCount += 1;
                maxCount = max(sessionCount, maxCount);
            } else if (nums[i] == nums[i + 1])
                ;
            else
                sessionCount = 1;
        }
        maxCount = max(sessionCount, maxCount);
        return maxCount;
    }
};
