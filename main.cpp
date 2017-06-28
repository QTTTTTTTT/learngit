#include <iostream>
#include <string>
#include "CreateSepuence.h"
#include "SourceCode.h"
#include "ChannelCoding.h"
#include "Channel.h"
using namespace std;
int main() {
	double p;
	cout<<"请输入生成二进制概率p："<<endl;
	cin>>p;
	int n;
	cout<<"请输入生成二进制长度n："<<endl;
	cin>>n;
	Sepuence *g=new Sepuence(n,p);
	string s=g->Create();
	cout<<s<<endl;
	cout<<"信源编码后为："<<endl;
	cout<<s<<endl;
	cout<<"请选择下列的信源编码器："<<endl;
	cout<<"1:无编码"<<endl<<"2:二进制香农-费诺编码"<<endl<<"3:二进制霍夫曼编码"<<endl<<"请输入1-3选择相应的编码"<<endl;
	int num1;
	cin>>num1;
	int same=0;
	SourceCode *e;
	for(int i=1;i<s.length();++i){
		if(s[i]==s[i-1])++same;
	}
	if(same!=s.length()-1){
		e=new SourceCode(num1,s);
		s=e->de_code();
	}
	cout<<"信源编码后为："<<endl;
	cout<<s<<endl;
	cout<<"请选择下列的信道编码器："<<endl;
	cout<<"1:使用无编码"<<endl<<"2:3次重复编码"<<endl<<"3:Hamming（7，4）码"<<endl<<"请输入1-3选择相应的编码"<<endl;
	int num2;
	cin>>num2;
	Channel *ss=new Channel(s,num2);
	s=ss->de_code();
	cout<<"信道编码后为："<<endl;
	cout<<s<<endl;
	cout<<"请选择下列的信道进行传输："<<endl;
	cout<<"1:理想信道"<<endl<<"2:给定错误概率为p的BSC"<<endl<<"3:给定符号0，1各自错误概率p,q的任意二进制信道"<<endl<<"请输入1-3选择相应的信道"<<endl;
	int num3;
	cin>>num3;
	cha *gg=new cha(num3);
	s=gg->TranSport(s);
	cout<<"信道传输后为："<<endl;
	cout<<s<<endl;
	s=ss->en_code(s);
	cout<<"信道解码后为: "<<endl;
	cout<<s<<endl;
	same=0; 
	for(int i=1;i<s.length();++i){
		if(s[i]==s[i-1])++same;
	}
	if(same!=s.length()-1)s=e->en_code(s); 
	cout<<"信源解码后为："<<endl;
	cout<<s<<endl;
	return 0;
}
