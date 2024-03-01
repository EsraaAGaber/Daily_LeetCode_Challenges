

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end());
        string ss = "1";
        for (int i = 0; i < s.length() - 1; i++)
            ss = s[i] + ss;
        return ss;
    }
};
