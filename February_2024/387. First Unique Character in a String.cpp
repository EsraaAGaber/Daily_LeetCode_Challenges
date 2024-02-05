class Solution {
public:
    int firstUniqChar(string s) {
        uint32_t x[30] = {0};
        for (auto it : s)
            x[it - 'a']++;
        int i = 0;
        for (auto it : s) {
            if (x[it - 'a'] == 1)
                return i;
            i++;
        }
        return -1;
    }
};
