int ss,tt,n,m;
struct cell         //方块
{
     int clour;
     int x,y;
}ces[102][102];
void read_build()
{
    string ts;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>ts;
            if(ts=="XXXXXXX")      //黑色
              {
                  ces[i][j].clour=0;
                  ces[i][j].x=ces[i][j].y=-1;
              }
            else if(ts==".......")   //白色
            {
                 ces[i][j].clour=5;
                 ces[i][j].x=ces[i][j].y=0;
            }
            else if(ts[0]=='X'&&ts[4]!='X')    //横向要填
            {
                 ces[i][j].clour=2;
                 ces[i][j].x=((ts[4]-'0')*10+(ts[5]-'0'))*10+(ts[6]-'0');
                 ces[i][j].y=-1;
            }
             else if(ts[0]!='X'&&ts[4]=='X')   //纵向要填
            {
                 ces[i][j].clour=3;
                 ces[i][j].y=((ts[0]-'0')*10+(ts[1]-'0'))*10+(ts[2]-'0');
                 ces[i][j].x=-1;
            }
            else                          //都要
            {
                 ces[i][j].clour=4;
                 ces[i][j].y=((ts[0]-'0')*10+(ts[1]-'0'))*10+(ts[2]-'0');
                 ces[i][j].x=((ts[4]-'0')*10+(ts[5]-'0'))*10+(ts[6]-'0');
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int counts=0;
            if(ces[i][j].clour==2) //横向的
            {
                for(int k=j+1;k<m;k++)
                {
                    if(ces[i][k].clour!=5)break;
                    adde(i*m+j,i*m+k,8);
                    counts++;
                }
                adde(ss,i*m+j,ces[i][j].x-counts);
            }
            else if(ces[i][j].clour==3)   //纵向的
            {
                for(int k=i+1;k<n;k++)
                {
                    if(ces[k][j].clour!=5)break;
                    adde(k*m+j,i*m+j,8);
                    counts++;
                }
                adde(i*m+j,tt,ces[i][j].y-counts);
            }

            else if(ces[i][j].clour==4)    //都要填的，一个格子要2个编号，注意。
            {
                for(int k=j+1;k<m;k++)
                {
                    if(ces[i][k].clour!=5)break;
                    adde(i*m+j,i*m+k,8);
                    counts++;
                }
                adde(ss,i*m+j,ces[i][j].x-counts);
                counts=0;
                for(int k=i+1;k<n;k++)
                {
                    if(ces[k][j].clour!=5)break;
                    adde(k*m+j,i*m+j+n*m+2,8);
                    counts++;
                }
                adde(i*m+j+n*m+2,tt,ces[i][j].y-counts);
            }
        }
}
void out()
{
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
          if(ces[i][j].clour!=5) printf("_");
          else
          {
              int sflow=0;
              for(int k=head[i*m+j];k!=-1;k=edge[k][1])      //统计的时候只要正向边（这里注意！），其实每个点也就一条出的正向边
              {
                  if(k%2==0)
                   sflow+=8-e[k][2];
              }
              printf("%d",sflow+1);
          }
          if(j==m-1)printf("\n");
          else printf(" ");
      }
}