class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= (int)nums.size() / 2; i++) {
            int j = i + nums.size() / 2;
            if (j > nums.size())
                break;
            if (nums[i] == nums[j])
                return nums[i];
        }
        return 0;
    }
};
