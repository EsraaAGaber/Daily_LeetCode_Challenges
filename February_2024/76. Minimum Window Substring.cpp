class Solution {
public:
    string minWindow(string s, string t) {
        int mp[150] = {0};
        for (auto it : t)
            mp[it]++;
        int mn = 1e9;
        int j = 0;
        int a = -1, b = -1;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]--;
            int ok = 1;
            for (char x = 'a'; x <= 'z'; x++) {
                if (mp[x] > 0)
                    ok = 0;
            }
            for (char x = 'A'; x <= 'Z'; x++) {
                if (mp[x] > 0)
                    ok = 0;
            }

            while (ok) {
                if (i - j + 1 < mn) {
                    a = j;
                    b = i;
                }
                mn = min(i - j + 1, mn);
                mp[s[j]]++;
                j++;
                if (mp[s[j - 1]] > 0)
                    break;
            }
        }
        string ss = "";
        if (a == -1)
            return ss;
        for (int i = a; i <= b; i++)
            ss += s[i];
        return ss;
    }
};
