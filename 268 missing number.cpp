class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int xorResult = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            xorResult ^= i ^ nums[i];
        }
        xorResult ^= n;
        return xorResult;
    }
};
