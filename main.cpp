#include <iostream>
#include <string>
#include "CreateSepuence.h"
#include "SourceCode.h"
#include "ChannelCoding.h"
#include "Channel.h"
using namespace std;
int main() {
	double p;
	cout<<"���������ɶ����Ƹ���p��"<<endl;
	cin>>p;
	int n;
	cout<<"���������ɶ����Ƴ���n��"<<endl;
	cin>>n;
	Sepuence *g=new Sepuence(n,p);
	string s=g->Create();
	cout<<s<<endl;
	cout<<"��Դ�����Ϊ��"<<endl;
	cout<<s<<endl;
	cout<<"��ѡ�����е���Դ��������"<<endl;
	cout<<"1:�ޱ���"<<endl<<"2:��������ũ-��ŵ����"<<endl<<"3:�����ƻ���������"<<endl<<"������1-3ѡ����Ӧ�ı���"<<endl;
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
	cout<<"��Դ�����Ϊ��"<<endl;
	cout<<s<<endl;
	cout<<"��ѡ�����е��ŵ���������"<<endl;
	cout<<"1:ʹ���ޱ���"<<endl<<"2:3���ظ�����"<<endl<<"3:Hamming��7��4����"<<endl<<"������1-3ѡ����Ӧ�ı���"<<endl;
	int num2;
	cin>>num2;
	Channel *ss=new Channel(s,num2);
	s=ss->de_code();
	cout<<"�ŵ������Ϊ��"<<endl;
	cout<<s<<endl;
	cout<<"��ѡ�����е��ŵ����д��䣺"<<endl;
	cout<<"1:�����ŵ�"<<endl<<"2:�����������Ϊp��BSC"<<endl<<"3:��������0��1���Դ������p,q������������ŵ�"<<endl<<"������1-3ѡ����Ӧ���ŵ�"<<endl;
	int num3;
	cin>>num3;
	cha *gg=new cha(num3);
	s=gg->TranSport(s);
	cout<<"�ŵ������Ϊ��"<<endl;
	cout<<s<<endl;
	s=ss->en_code(s);
	cout<<"�ŵ������Ϊ: "<<endl;
	cout<<s<<endl;
	same=0; 
	for(int i=1;i<s.length();++i){
		if(s[i]==s[i-1])++same;
	}
	if(same!=s.length()-1)s=e->en_code(s); 
	cout<<"��Դ�����Ϊ��"<<endl;
	cout<<s<<endl;
	return 0;
}
