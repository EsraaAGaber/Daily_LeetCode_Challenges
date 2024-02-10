class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i, k = i; j < s.length() && k >= 0; j++, k--) {
                if (s[j] == s[k])
                    cnt++;
                else
                    break;
            }
            if (i != 0) {
                for (int j = i, k = i - 1; j < s.length() && k >= 0; j++, k--) {
                    if (s[j] == s[k])
                        cnt++;
                    else
                        break;
                }
            }
        }
        return cnt;
    }
};
