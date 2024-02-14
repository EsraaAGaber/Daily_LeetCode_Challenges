class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        ans = nums;
        int i = 1;
        int u = 0;
        for (auto it : nums) {
            if (it > 0) {
                ans[u] = it;
                u += 2;
            } else {
                ans[i] = it;
                i += 2;
            }
        }
        return ans;
    }
};
