class Solution {
public:
    string frequencySort(string s) {
        map<char, int> frq;
        for (auto it : s) {
            frq[it]++;
        }
        vector<pair<int, char>> vec;
        for (auto it : frq) {

            vec.push_back({it.second, it.first});
        }
        sort(vec.begin(), vec.end());
        string a = "";
        for (auto it : vec) {
            for (int i = 0; i < it.first; i++) {
                a += it.second;
            }
        }
        reverse(a.begin(), a.end());
        return a;
    }
};
