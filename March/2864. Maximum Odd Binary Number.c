char* maximumOddBinaryNumber(char* s) {
    int one = 0, zero = 0;
    int j = 0;
    for (int i = 0; i < strlen(s); i++) {

        if (s[i] == '1')
            one++;
        else
            zero++;
    }
    char* ans = (char*)malloc((strlen(s) + 1) * sizeof(char));
    ans[strlen(s)] = '\0';
    one--;
    int i = 0;

    while (one--) {
        ans[i++] = '1';
    }
    while (zero--) {
        ans[i++] = '0';
    }
    ans[i] = '1';
    printf("%s", ans);
    return ans;
}
