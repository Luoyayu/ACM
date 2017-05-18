// binary_search
#include <iostream>    
#include <algorithm> 
#include <cstdio> 
#include <cstring>
#include <vector>  
using namespace std;
int n;
//bool cmp (int i,int j) { return (i>j); }
int binary_search(int a[])
{
	vector<int> v(a,a+n*sizeof(int));     
	sort (v.begin(), v.end());
	while(scanf("%d",&n)!=EOF)
	  if ( binary_search (v.begin(), v.end(),n)) return 1;
	  else return 0;
}
int main () 
{
   int myints[100];
   memset(myints,-1,sizeof myints);
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   		scanf("%d",&myints[i]);
   if(binary_search(myints))
	     cout << "found!\n";
	  else  
	  	cout << "not found.\n";
  return 0;
}
