#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef unsigned long long ll;

class aclass
{
	private:
		int x,y;
		inline void init();
	public:
		void initt(int x=0,int y=0);
		int init(){return x;}
};

class Complex
{
private:
	double real,imag;
public:
	Complex(double r,double i=0);
	Complex(const Complex &c)//本类的引用//复制构造函数默认具有复制功能：1)一个对象去初始化另一个对象。2)如果某函数有一个参数是类的对象，那么改旱火速被调用是，类的复制构造函数将被调用。3)如果函数的返回值是类的对象，则函数返回时，类的复制构造函数被调用。
	{
		real=c.real;
		imag=c.imag;
		cout<<"copy constructor called"<<endl
	}
};

Complex::Complex(double r,double i)
{
	real=r,imag=i;
}

void a::init(){}

int main(int argc,char * argv[])
{
	a A;
	A.initt(5);
	Complex c1(2);
	Complex c2(c1);//Complex c2=c1
	Complex *pc=new Complex(2,8);
	for(int i=0;i<argc;i++)
		printf("%s",argv[i]);
	return 0;
}
