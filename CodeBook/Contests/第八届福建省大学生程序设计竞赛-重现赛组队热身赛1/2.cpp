#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int cha(int x1,int y1,int x2,int y2,int x3,int y3)
{
        return((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
}
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                int x1,y1,x2,y2,x3,y3;
                int x4,y4,x5,y5,x6,y6;
                scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&x5,&y5,&x6,&y6);
                int flag=0;
if(cha( x1,y1,x2,y2,x3,y3)>0&&cha( x1,y1,x2,y2,x4,y4)<=0&&cha( x1,y1,x2,y2,x5,y5)<=0&&cha( x1,y1,x2,y2,x6,y6)<=0)
                {
                        if(cha( x1,y1,x2,y2,x4,y4)==0||cha( x1,y1,x2,y2,x5,y5)==0||cha( x1,y1,x2,y2,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }
                 if(cha( x1,y1,x2,y2,x3,y3)<0&&cha(x1,y1,x2,y2,x4,y4)>=0&&cha( x1,y1,x2,y2,x5,y5)>=0&&cha( x1,y1,x2,y2,x6,y6)>=0)
                {
                        if(cha( x1,y1,x2,y2,x4,y4)==0||cha(x1,y1,x2,y2,x5,y5)==0||cha( x1,y1,x2,y2,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }
                 if(cha(x1,y1,x3,y3,x2,y2)>0&&cha( x1,y1,x3,y3,x4,y4)<=0&&cha( x1,y1,x3,y3,x5,y5)<=0&&cha( x1,y1,x3,y3,x6,y6)<=0)
                {
                        if(cha( x1,y1,x3,y3,x4,y4)==0||cha(x1,y1,x3,y3,x5,y5)==0||cha(x1,y1,x3,y3,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }
                  if(cha( x1,y1,x3,y3,x2,y2)<0&&cha( x1,y1,x3,y3,x4,y4)>=0&&cha( x1,y1,x3,y3,x5,y5)>=0&&cha(x1,y1,x3,y3,x6,y6)>=0)
                {
                        if(cha(x1,y1,x3,y3,x4,y4)==0||cha( x1,y1,x3,y3,x5,y5)==0||cha( x1,y1,x3,y3,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }
                  if(cha(x2,y2,x1,y1,x3,y3)>0&&cha( x2,y2,x1,y1,x4,y4)<=0&&cha( x2,y2,x1,y1,x5,y5)<=0&&cha( x2,y2,x1,y1,x6,y6)<=0)
                {
                        if(cha( x2,y2,x1,y1,x4,y4)==0||cha( x2,y2,x1,y1,x5,y5)==0||cha(x2,y2,x1,y1,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }
                  if(cha( x2,y2,x1,y1,x3,y3)<0&&cha( x2,y2,x1,y1,x4,y4)>=0&&cha( x2,y2,x1,y1,x5,y5)>=0&&cha( x2,y2,x1,y1,x6,y6)>=0)
                {
                        if(cha( x2,y2,x1,y1,x4,y4)==0||cha( x2,y2,x1,y1,x5,y5)==0||cha( x2,y2,x1,y1,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }
                  if(cha( x2,y2,x3,y3,x1,y1)>0&&cha( x2,y2,x3,y3,x4,y4)<=0&&cha( x2,y2,x3,y3,x5,y5)<=0&&cha( x2,y2,x3,y3,x6,y6)<=0)
                {
                        if(cha(x2,y2,x3,y3,x4,y4)==0||cha( x2,y2,x3,y3,x5,y5)==0||cha( x2,y2,x3,y3,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }
                  if(cha( x2,y2,x3,y3,x1,y1)<0&&cha( x2,y2,x3,y3,x4,y4)>=0&&cha (x2,y2,x3,y3,x5,y5)>=0&&cha(x2,y2,x3,y3,x6,y6)>=0)
                {
                        if(cha( x2,y2,x3,y3,x4,y4)==0||cha( x2,y2,x3,y3,x5,y5)==0||cha( x2,y2,x3,y3,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }
                  if(cha( x3,y3,x1,y1,x2,y2)>0&&cha( x3,y3,x1,y1,x4,y4)<=0&&cha( x3,y3,x1,y1,x5,y5)<=0&&cha (x3,y3,x1,y1,x6,y6)<=0)
                {
                        if(cha( x3,y3,x1,y1,x4,y4)==0||cha( x3,y3,x1,y1,x5,y5)==0||cha( x3,y3,x1,y1,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }
                  if(cha(x3,y3,x1,y1,x2,y2)<0&&cha( x3,y3,x1,y1,x4,y4)>=0&&cha( x3,y3,x1,y1,x5,y5)>=0&&cha(x3,y3,x1,y1,x6,y6)>=0)
                {
                        if(cha( x3,y3,x1,y1,x4,y4)==0||cha( x3,y3,x1,y1,x5,y5)==0||cha( x3,y3,x1,y1,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }
                if(cha( x3,y3,x2,y2,x1,y1)>0&&cha( x3,y3,x2,y2,x4,y4)<=0&&cha(x3,y3,x2,y2,x5,y5)<=0&&cha(x3,y3,x2,y2,x6,y6)<=0)
                {
                        if(cha( x3,y3,x2,y2,x4,y4)==0||cha( x3,y3,x2,y2,x5,y5)==0||cha( x3,y3,x2,y2,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }
                 if(cha( x3,y3,x2,y2,x1,y1)<0&&cha( x3,y3,x2,y2,x4,y4)>=0&&cha(x3,y3,x2,y2,x5,y5)>=0&&cha( x3,y3,x2,y2,x6,y6)>=0)
                {
                        if(cha( x3,y3,x2,y2,x4,y4)==0||cha( x3,y3,x2,y2,x5,y5)==0||cha( x3,y3,x2,y2,x6,y6)==0)
                                flag=2;
                        else flag=1;
                }

                if(flag==0) printf("contain\n");
                else  if(flag==2) printf("intersect\n");
                 else  if(flag==1) printf("disjoint\n");



        }
}