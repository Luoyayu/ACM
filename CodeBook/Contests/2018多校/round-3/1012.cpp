#include <bits/stdc++.h>

using namespace std;
const int maxn = 4e2 + 5;
char st[maxn][maxn];

int main() {
    int T, a, b, c, H, W;
    for (scanf("%d", &T); T--;) {
        scanf("%d%d%d", &a, &b, &c);
        H = c * 2 + 1 + b * 2;
        W = a * 2 + 1 + b * 2;
        for (int i = 0; i < H; i++) {
            st[i][W] = '\0';
            for (int j = 0; j < W; j++) {
                if (i < c * 2 + 1 && j < a * 2 + 1) {
                    if (i % 2 == 0 && j % 2 == 0) {
                        st[i][j] = '+';
                    } else if (i % 2 == 1 && j % 2 == 0) {
                        st[i][j] = '|';
                    } else if (i % 2 == 0 && j % 2 == 1) {
                        st[i][j] = '-';
                    } else {
                        st[i][j] = '.';
                    }
                } else if (i >= c * 2 + 1 && j < a * 2 + 1) {
                    if (j <= i - c * 2 - 1) {
                        st[i][j] = '.';
                    } else if (i % 2 == 1) {
                        if (j % 2 == 1)
                            st[i][j] = '/';
                        else
                            st[i][j] = '.';
                    } else {
                        if (j > i - c * 2 - 1 && j % 2 == 0)
                            st[i][j] = '+';
                        else
                            st[i][j] = '-';
                    }
                } else if (i < c * 2 + 1 && j >= a * 2 + 1) {
                    if (i <= j - a * 2 - 1) {
                        st[i][j] = '.';
                    } else if (j % 2 == 1) {
                        if (i % 2 == 1)
                            st[i][j] = '/';
                        else
                            st[i][j] = '.';
                    } else {
                        if (i > j - a * 2 - 1 && i % 2 == 0)
                            st[i][j] = '+';
                        else
                            st[i][j] = '|';
                    }
                } else {
                    int ii = i - c * 2 - 1;
                    int jj = j - a * 2 - 1;
                    if (ii >= jj) {
                        if (j <= i - c * 2 - 1) {
                            st[i][j] = '.';
                        } else if (j > i - c * 2 - 1) {
                            if (i % 2 == 1) {
                                if (j % 2 == 1)
                                    st[i][j] = '/';
                                else
                                    st[i][j] = '.';
                            } else {
                                if (j > i - c * 2 - 1 && j % 2 == 0)
                                    st[i][j] = '+';
                                else
                                    st[i][j] = '-';
                            }
                        }
                    } else {
                        if (i <= j - a * 2 - 1) {
                            st[i][j] = '.';
                        } else if (j % 2 == 1) {
                            if (i % 2 == 1)
                                st[i][j] = '/';
                            else
                                st[i][j] = '.';
                        } else {
                            if (i > j - a * 2 - 1 && i % 2 == 0)
                                st[i][j] = '+';
                            else
                                st[i][j] = '|';
                        }
                    }
                }
            }
        }
        for (int i = H - 1; i >= 0; i--) printf("%s\n", st[i]);
    }
    return 0;
}