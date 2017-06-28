#include "ChannelCoding.h"
#include "Hamming.h"
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
Channel::Channel(){
	p=NULL;
}
Channel::Channel(string s,int n):st(s),number(n){
	p=NULL;
}
string Channel::de_code(){
	if(number==1)return st;
	else if(number==2){
		string g="";
		for(int i=0;i<st.length();++i){
			g=g+st[i];
			g=g+st[i];
			g=g+st[i];
		}
		return g;
	}
	else if(number==3){
		Hamming *p=new Hamming(st);
		return p->de_code();
	}
}
string Channel::en_code(string g){
	if(number==1)return g;
	else if(number==2){
		string ans="";
		for(int i=0;i<g.length();i+=3){
			char p1=g[i];
			char p2=g[i+1];
			char p3=g[i+2];
			if(p1==p2&&p2==p3) ans=ans+p1;
			else if(p1==p3) ans=ans+p1;
			else if(p3==p2) ans=ans+p2;
			else ans=ans+p1;
		}
		return ans;
	}
	else if(number==3){
		return p->en_code(g);
	}
}
