class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> vec;
        int u = arr[0];
        int c = 0;
        for (auto it : arr) {
            if (it != u) {
                u = it;
                vec.push_back(c);
                c = 1;
            } else
                c++;
        }
        vec.push_back(c);
        sort(vec.begin(), vec.end());
        int i = vec.size();
        for (auto it : vec) {
            if (k - it < 0)
                return i;
            i--;
            k -= it;
        }
        return i;
    }
};
