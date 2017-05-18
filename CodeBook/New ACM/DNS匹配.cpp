#include<stdio.h>
#include<string.h>
char* strrev(char* str) 
{
  char *h = str, *t = str, ch;
  while (*t++);
  t -= 2;
  while (h < t) 
	{
	    ch = *h;
	    *h++ = *t;
	    *t-- = ch;
  	}
  return str;
}
int match_DNA(char* str1, char*str2) 
{
	int i;
  	for (i = 0; str1[i] && str2[i]; i++) 
	{
	    if (str1[i] == 'A' && str2[i] != 'T') break;
	    else if (str1[i] == 'T' && str2[i] != 'A') break;
	    else if (str1[i] == 'G' && str2[i] != 'C') break;
	    else if (str1[i] == 'C' && str2[i] != 'G') break;
  	}
  return (str1[i]||str2[i])?0:1;
}
int main()
{
  int T, n;
  char str[101][101];
  scanf("%d", &T);
  while (T--)
   {
   	 memset(str, 0, sizeof(str));
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
		scanf("%s", str[i]);
    for (int i = 0; i < n; i++) 
    	for (int j = i + 1; j < n; j++) 
        	if (str[i][0] && str[j][0] && match_DNA(str[i], str[j]))
		 	{
	          cnt++;
	          memset(str[i], 0, sizeof(str[i]));
	          memset(str[j], 0, sizeof(str[j]));
	 		}
    printf("%d\n", cnt);
  }

  return 0;
}