#define dpp(x, y) memset((x), y, sizeof(x));

class Solution {
public:
    int dp[10005];
    int rec(int re) {
        if (re == 0)
            return 0;
        int a = sqrt(re);
        if (a == 1)
            return re;
        int& ret = dp[re];
        if (~ret)
            return ret;
        ret = 1e9;
        for (int i = 1; i <= a; i++) {
            if (re - i * i >= 0)
                ret = min(ret, 1 + rec(re - i * i));
        }
        return ret;
    }
    int numSquares(int n) {
        dpp(dp, -1);
        return rec(n);
    }
};
