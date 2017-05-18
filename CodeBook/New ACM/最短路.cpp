# include <iostream>
# include <string>
# include <queue>
#include<algorithm>
# define MAX 1005
const int inf= 99999999;
using namespace std;
string data[MAX]; 
int G[MAX][MAX]; 
int N; 
int Num_index(string str) 
{
    for (int i = 0; i < N; i++)
        if (data[i] == str) 
            return i;
    return -1;
}
void Floyd() 
{
    for (int k = 0; k < N; k++) 
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++) 
                    G[i][j] = min(G[i][k] + G[k][j],G[i][j]);
}
int mini_lenth(string str1, string str2)
 {
    Floyd();
    if (G[Num_index(str1)][Num_index(str2)] == inf) 
        return -1;
    return G[Num_index(str1)][Num_index(str2)];
}
int main(void) 
{
	int T,n;
	cin >> T;
	while(T--) 
	{
		cin>>n;
 	   for (int i = 0; i < MAX; i++) 
	        for (int j = 0; j < MAX; j++) 
	            if (i == j) 
	                G[i][j] = 0; 
	             else 
	                G[i][j] = inf;
	    for (int i = 0; i < n; i++) 
		{
	        string str1, str2;
	        int w;
	        cin >> str1 >> str2 >> w;
	        int str1_index, str2_index;
	        str1_index = Num_index(str1),str2_index = Num_index(str2);
	        
	        if (str1_index == -1) 
	            data[N++] = str1, str1_index = N-1;
	        if (str2_index == -1)
	            data[N++] = str2,str2_index = N-1;
	            
	        G[str1_index][str2_index] = G[str2_index][str1_index] = w;
	    }
	    string strS, strT;
	    cin >> strS >> strT;
	    if (Num_index(strS) == -1 || Num_index(strT) == -1)
	        if (strS == strT)
	            cout << "0" << endl;
	        else 
	            cout << "-1" << endl;
		else 
	        cout << mini_lenth(strS, strT) << endl;
	}
	return 0;
}