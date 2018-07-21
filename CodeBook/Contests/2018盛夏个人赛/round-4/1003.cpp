#include <bits/stdtr1c++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll sum = 0;
        bool flag = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (x >= n) flag = 1;
            sum += x;
        }
        if (sum % 2 || flag)
            puts("N");
        else
            puts("Y");
    }
}
/*
Problem Description
As we all know, Sister Ye is good at Graph Theory. Now he is intending to examine your Graph Theory level. Sister Ye would show you a degree sequence and ask you to find a simple graph that satisfies the sequence of degrees. Because the graph may be too large, you have to answer if such a graph exists or not only. In order to prevent you from guessing, Sister Ye will ask you more than once.
 

Input
The first line contains an integer T, the times Sister Ye ask you.

Each question will begin with a line contains an integer n, the size of sequence.
The following line contains a degree sequence a1,...,an.
 

Output
You should answer 'Y'(yes) or 'N'(no) for each question in one line.
1 ≤ T ≤ 50.
1 ≤ n ≤ 100000.
1 ≤ ai ≤ 10^9.
 

Sample Input
2
1
1
3
2 1 1
 

Sample Output
N
Y

Hint

loop:a loop is an edge that connects a vertex to itself. 

simple graph: a graph without loops and multiple edges between two vertexes.

degree:the degree of a vertex in a graph is the number of edges connected to the vertex.

degree sequence: An integer sequence of the degrees for each vertex in the graph.
*/