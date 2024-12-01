class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,0), ans;
        for(auto x:nums) {
            v[x-1]++;
        }
        for(int i=1;i<=n;i++) {
            if (v[i-1]==0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};