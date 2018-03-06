//题意着急
//首先给出7位的内存地址，我们要做一个映射到缓存中，内存256MB
//每条指令指向1byte数据，但是我们要先主内存中对齐数据，即在主内存中找到地址所处的块，把这块整体映射到缓存中
//如果映射后不是来自同一个内存块的空间请求输出Hit,否则成功申请输出Miss

#include<bits/stdc++.h>
using namespace std;
bool used[70];
int  add_in_memory[70];
int main()
{
    string add;
    int hit=0,miss=0,tot=0;
    while(cin>>add && add!="END")
    {
        int to=0;
        for(int i=0;i<=6;i++)
        {
            int tmp;
            if(add[i]>='0'&&add[i]<='9')
                tmp=(add[i]-'0');
            else tmp=(add[i]-'A'+10);
            to=tmp+to*16;
        }
        //cout<<to<<endl;
        tot++;
        int block_in_cache = (to/16+1) % 64;
        if(used[block_in_cache]==0||(used[block_in_cache]==1&&add_in_memory[block_in_cache]!=to/16+1))
        {
            printf("Miss\n");
            used[block_in_cache]=1;
            add_in_memory[block_in_cache]=to/16+1;
        }
        else
        {
            printf("Hit\n");
            hit++;
        }
    }
    printf("Hit ratio = %.2f%%",1.0*hit/tot*100);
}
