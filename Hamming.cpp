#include "Hamming.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
Hamming::Hamming(){
}
Hamming::Hamming(string s){
	st=s;
}
string Hamming::de_code(){
	string g="";
	char p1=(st[0]-'0')^(st[1]-'0')^(st[3]-'0')+'0';
	char p2=(st[0]-'0')^(st[2]-'0')^(st[3]-'0')+'0';
	char p3=(st[1]-'0')^(st[2]-'0')^(st[3]-'0')+'0';
	g=g+p1;
	g=g+p2;
	g=g+st[0];
	g=g+p3;
	g=g+st[1];
	g=g+st[2];
	g=g+st[3];
	return g;
}
string Hamming::en_code(string s){
	string ans="";
	char c1=s[2],c2=s[4],c3=s[5],c4=s[6];
	int p1=(s[0]-'0')^(s[2]-'0')^(s[4]-'0')^(s[6]-'0');
	int p2=(s[1]-'0')^(s[2]-'0')^(s[5]-'0')^(s[6]-'0');
	int p3=(s[3]-'0')^(s[4]-'0')^(s[5]-'0')^(s[6]-'0');
	if(p1+p2+p3==3)c4=1^(s[6]-'0')+'0';
	else if(p1+p2==2)c1=1^(s[2]-'0')+'0';
	else if(p2+p3==2)c3=1^(s[5]-'0')+'0';
	else if(p1+p3==2)c2=1^(s[4]-'0')+'0';
	ans=ans+c1;
	ans=ans+c2;
	ans=ans+c3;
	ans=ans+c4;
	return ans;
}
