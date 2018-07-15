#include <cstdio>
#include <cstdlib>
#include <cstring>
char A1[10002], B1[10002];
int A[20002], B[20002];
int lena, lenb;
int mini(int *s, int l) {
    int i = 0, j = 1, k;
    while (i < l && j < l) {
        int k = 0;
        while (s[i + k] == s[j + k] && k < l) k++;
        if (k == l) return i;
        if (s[i + k] > s[j + k]) {
            if (i + k + 1 > j)
                i = i + k + 1;
            else
                i = j + 1;
        } else if (j + k + 1 > i)
            j = j + k + 1;
        else
            j = i + 1;
    }
    if (i < l)
        return i;
    else
        return j;
}

int cmp(int s, int S) {
    int i = s, I = S;
    do {
        if (A[i] > B[I])
            return 1;
        else if (A[i] < B[I])
            return -1;
        i++, I++;
    } while ((i - s) != (lena - 1) && (I - S) != (lenb - 1));
    if ((i - s) == (lena - 1) && (I - S) == (lenb - 1))
        return 0;
    else if ((i - s) == (lena - 1))
        return -1;
    else if ((I - S) == (lenb - 1))
        return 1;
}
int main() {
    int T;
    scanf("%d", &T);
    gets(A1);
    while (T--) {
        gets(A1), gets(B1);
        lena = strlen(A1), lenb = strlen(B1);
        for (int i = 0; A1[i] != '\0'; i++)
            if ('0' <= A1[i] && A1[i] <= '9')
                A[i + lena] = A[i] = A1[i] - '0';
            else if ('A' <= A1[i] && A1[i] <= 'Z')
                A[i + lena] = A[i] = A1[i] - 'A' + 10;
            else if ('a' <= A1[i] && A1[i] <= 'z')
                A[i + lena] = A[i] = A1[i] - 'a' + 36;

        for (int i = 0; B1[i] != '\0'; i++)
            if ('0' <= B1[i] && B1[i] <= '9')
                B[i + lenb] = B[i] = B1[i] - '0';
            else if ('A' <= B1[i] && B1[i] <= 'Z')
                B[i + lenb] = B[i] = B1[i] - 'A' + 10;
            else if ('a' <= B1[i] && B1[i] <= 'z')
                B[i + lenb] = B[i] = B1[i] - 'a' + 36;

        int k1 = mini(A, lena), int k2 = mini(B, lenb), int k3 = cmp(k1, k2);
        if (k3 == 1)
            printf("bb\n");
        else if (k3 == 0)
            printf("ddbb\n");
        else if (k3 == -1)
            printf("dd\n");
    }
    return 0;
}