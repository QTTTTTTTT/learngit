#include "Channel.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;
cha::cha(){
}
cha::cha(int num){
	number=num;
}
string BSC(string s,double p){
	string ans="";
	srand((unsigned)time(0));
	for(int i=0;i<s.length();++i){
		double num=rand()%100/(double)101;
		if(num<=p){
			if(s[i]=='1')ans=ans+'0';
			else ans=ans+'1';
		}
		else ans=ans+s[i];
	}
	return ans;
}
string TOW(string s,double p,double q){
	string ans="";
	srand((unsigned)time(0));
	for(int i=0;i<s.length();++i){
		double num=rand()%100/(double)101;
		if(s[i]=='0'){
			if(num<=p)ans=ans+'1';
			else ans=ans+s[i];
		}
		else{
			if(num<=q)ans=ans+'0';
			else ans=ans+s[i];
		}
	}
	return ans;
}
string cha::TranSport(string s){
	if(number==1)return s;
	else if(number==2){
		double p;
		cout<<"����BSC�ĸ���p"<<endl;
		cin>>p;
		return BSC(s,p); 
	}
	else if(number==3){
		double p,q;
		cout<<"����0�ĸ���p��1�ĸ���q"<<endl; 
		cin>>p>>q;
		return TOW(s,p,q);
	}
}
