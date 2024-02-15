class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int i = 0;
        long long sum = 0, u = -1;
        for (auto it : nums) {
            if (sum > it) {
                u = max(u, sum + it);
            }
            sum += it;
            i++;
        }
        return u;
    }
};
