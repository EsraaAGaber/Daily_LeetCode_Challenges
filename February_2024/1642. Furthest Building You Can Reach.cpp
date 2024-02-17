class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int> vec;
        int n = heights.size();
        for (int i = 1; i < n; i++) {
            if (heights[i] > heights[i - 1])
                vec.push_back(heights[i] - heights[i - 1]);
            else
                vec.push_back(0);
        }
        multiset<int> st;
        for (int i = 0; i < min(n - 1, ladders); i++) {
            st.insert(vec[i]);
        }
        for (int i = ladders; i < n - 1; i++) {
            if (!st.empty()) {
                auto it = *st.begin();
                if (vec[i] > it) {
                    st.erase(st.begin());
                    st.insert(vec[i]);
                    bricks -= (it);
                } else
                    bricks -= vec[i];

            } else
                bricks -= vec[i];
            if (bricks < 0)
                return i;
        }
        return n - 1;
    }
};
