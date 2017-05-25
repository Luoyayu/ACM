//扩展KMP/Manacher算法 回文串判定
//扩展KMP算法：应用与给定文本串S，模式串P，对于每个S[i]求出S[i...Slen-1]与T的最长公共前缀长度，
//记作extend[i]，如果S在某个位置i有entend[i]=m，则可知在S中好到了匹配串T，并且匹配的首位置为i,匹配了模式串extend[i]个位置
#include <cstdio>
#include <cstring>
#include <string>
#include "iostream"
using namespace std;
int main(int argc, char const *argv[]) {

    string a;
    cin>>a;
    cout<<a<<endl;
    return 0;
}
