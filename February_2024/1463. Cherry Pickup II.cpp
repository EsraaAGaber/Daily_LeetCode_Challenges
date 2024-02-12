#define dpp(x, y) memset((x), y, sizeof(x));
#define sz(s) (int)s.size()
#define all(x) x.begin(), x.end()
class Solution {
public:
    int dp[80][80][80];
    int r, c;
    int rec(int i, int j, int jj, vector<vector<int>>& vec) {
        if (i == r)
            return 0;
        int& ret = dp[i][j][jj];
        if (~ret)
            return ret;
        ret = 0;
        for (int h = -1; h < 2; h++) {
            for (int hh = -1; hh < 2; hh++) {
                if (i + 1 < r && j + h < c && j + h >= 0 && jj + hh < c &&
                    jj + hh >= 0) {
                    if (j + h != jj + hh)
                        ret = max(ret, vec[i + 1][j + h] + vec[i + 1][jj + hh] +
                                           rec(i + 1, j + h, jj + hh, vec));
                    else
                        ret = max(ret, vec[i + 1][j + h] +
                                           rec(i + 1, j + h, jj + hh, vec));
                }
            }
        }
        return ret;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        dpp(dp, -1);
        r = sz(grid);
        c = sz(grid[0]);
        return rec(0, 0, c - 1, grid) + grid[0][0] + grid[0][c - 1];
    }
};
