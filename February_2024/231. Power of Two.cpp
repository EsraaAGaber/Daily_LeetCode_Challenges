class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0)return 0;
        int a=log2(n);
        if ((1<<a)==n)return true;
        return false;
    }
};
