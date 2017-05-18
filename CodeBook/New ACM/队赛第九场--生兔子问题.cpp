#include<stdio.h>
#define MAX 101
int rabbit[MAX][MAX] = {1};
void generate( int m, int d );
void add( int des, int a, int b );
int main()
{
    int m, d;
    while( scanf("%d %d", &m, &d) && m != 0 )
        generate(m, d);
    return 0;
}
void add( int des, int a, int b )
{
    int temp, carry = 0;
    
    for ( int i = 0; i < MAX; i++ )
    {
        temp = rabbit[a][i] + rabbit[b][i] + carry;
        rabbit[des][i] = temp % 10;
        carry = temp / 10;
    }
 
}
void generate( int m, int d )
{
    int i, j;
    for ( i = 1; i <= d; i++ )
        for ( j = 0; j < MAX; j++ )
            rabbit[i][j] = 0;
    for ( i = 1; i <= d; i++ )
        if ( i < m )
            add( i, i - 1, 0 );
        else
            add( i, i - 1, i - m );
    i = MAX - 1;
    while( rabbit[d][i] == 0)
        i--;
    for( j = i; j >= 0; j-- )
        printf("%d", rabbit[d][j]);
    printf("\n");
}