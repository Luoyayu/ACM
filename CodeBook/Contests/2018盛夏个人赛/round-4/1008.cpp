#include <bits/stdtr1c++.h>

using namespace std;
const int maxn = 1e6 + 7;
// 思路直接读入处理,遇到分隔号把之前string中的反向输出, 再输出分隔符
void Print(const string &s) {
    int len = s.length();
    if (len == 0) return;
    for (int i = len - 1; i >= 0; i--) printf("%c", s[i]);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char c;
    string s;
    while (scanf("%c", &c) != EOF) {
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') &&
            (c != '-')) {  // '-'不算分隔符
            Print(s);
            s = "";
            printf("%c", c);
        } else
            s.push_back(c);
    }
    return !printf("\n");
}
/*
Problem Description
Alice and Bob are a couple friends. But Gao FuShuai loves Alice. So Gao has sent
Alice letters signed Bob in order to ruin the relationship between Bob and
Alice. Alice found it and Alice and Bob decide to use a system of cryptography.
The system is to reverse words of sentences, easily but efficiently.


Input
The input contains several test cases.
The first line of input contains an integer N (1 <= N <= 10000) that indicates
the number of test cases.

Each test case is composed by one line. This line contains a string that is a
sentence. This string will contain between 0 and 100 characters, inclusive. Each
character is a lowercase letter ('a'-'z'), an uppercase letter ('A'-'Z'), a
comma (','), a space (' '), a hyphen ('‐') or a period ('.').


Output
For each test case, please output the result in a separate line. The result
should only reverse words of the corresponding sentences. 0 < N ≤ 10000.


Sample Input
3
I am Bob.
There is a good ACM atmosphere at Sun Yat-sen University, so I am going to
participate SYSU-ICPC. By the way, I love you


Sample Output
I ma boB.
erehT si a doog MCA erehpsomta ta nuS nes-taY ytisrevinU, os I ma gniog ot
etapicitrap CPCI-USYS. yB eht yaw, I evol uoy
*/