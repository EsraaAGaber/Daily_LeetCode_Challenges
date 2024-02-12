#define sz(s) (int)s.size()
#define all(x) x.begin(), x.end()
#define dpp(x, y) memset((x), y, sizeof(x));

class Solution {
public:
    vector<int> ans;
    int dp[1005][1005];
    int n;
    int rec(int i, int last, vector<int>& nums) {
        if (i == n)
            return 0;
        int& ret = dp[i][last];
        if (~ret)
            return ret;
        if (last == 0) {
            ret = max(rec(i + 1, last, nums), 1 + rec(i + 1, i + 1, nums));
        } else {
            ret = 0;
            if (nums[i] % nums[last - 1] == 0)
                ret = (1 + rec(i + 1, i + 1, nums));
            ret = max(ret, rec(i + 1, last, nums));
        }
        return ret;
    }
    void build(int i, int last, vector<int>& nums) {
        if (i == n)
            return;
        int& ret = dp[i][last];

        if (last == 0) {
            if (ret == rec(i + 1, last, nums)) {
                return build(i + 1, last, nums);
            } else {
                ans.push_back(nums[i]);
                return build(i + 1, i + 1, nums);
            }
        } else {

            if (nums[i] % nums[last - 1] == 0) {
                if (ret == (1 + rec(i + 1, i + 1, nums))) {
                    ans.push_back(nums[i]);
                    return build(i + 1, i + 1, nums);
                }
            }
            return build(i + 1, last, nums);
        }
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        dpp(dp, -1);
        n = sz(nums);
        sort(all(nums));
        ans.clear();
        cout << rec(0, 0, nums);
        build(0, 0, nums);
        return ans;
    }
};
