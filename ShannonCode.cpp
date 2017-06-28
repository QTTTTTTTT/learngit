#include "ShannonCode.h"
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
Shannon::Shannon(){
	length=0;
}
bool cmp(pair<char,double> a,pair<char,double> b){
	return a.second<b.second;
}
Shannon::Shannon(string s){
	length=s.length();
	st=s;
	bool flag=true;
	for(int i=0;i<s.length();++i){
		flag=true;
		for(int j=0;j<freq.size();++j){
			if(freq[j].first==s[i])
			{
				freq[j].second+=1.0;
				flag=false;
				break;
			}
		}
		if(flag){
			pair<char,double> d;
			d.first=s[i];
			d.second=1.0;
			freq.push_back(d);
		}
	}
	for(int i=0;i<freq.size();++i){
		freq[i].second/=(double)length;
	}
	sort(freq.begin(),freq.end(),cmp);
	for(int i=0;i<freq.size();++i){
		code[freq[i].first]="";
	}
	flag1=0;
}
int Shannon::r(){
	return freq.size();
}
void Shannon::built(int m,int n){
	int j,k;
	double sum=0.0,s=0.0,s1,z[freq.size()];
	++flag1;
	if(m==n){
		return ;
	}
	for(j=0;j<=n;++j){
		z[j]=freq[j].second;
	}
	for(j=m;j<=n;++j)
		sum+=z[j];
	k=m;
	do{
		s1=s;
		s=s+freq[k++].second;
	}while(s<=sum-s);
	if((sum-2*s1)<=(2*s-sum))--k;
	for(j=m;j<k;++j)
		code[freq[j].first]=code[freq[j].first]+'0';
	for(j=k;j<=n;++j)
		code[freq[j].first]=code[freq[j].first]+'1';
	built(m,k-1);
	built(k,n);
}
string Shannon::de_code(){
	string ans="";
	for(int i=0;i<length;++i){
		ans=ans+code[st[i]];
	}
	return ans;
}
char find(string g,map<char,string> code){
	for(map<char,string>::iterator it=code.begin();it!=code.end();++it){
		if(g==it->second)return it->first;
	}
}
bool in(string g,map<char,string> code){
	for(map<char,string>::iterator it=code.begin();it!=code.end();++it){
		if(g==it->second)return true;
	}
	return false;
}
string Shannon::en_code(string s){
	string ans="";
	string g="";
	for(int i=0;i<s.length();++i){
		g=g+s[i];
		if(in(g,code)){
			char index=find(g,code);
			ans=ans+index;
			g="";
		}
	}
	return ans;
}
Shannon::~Shannon(){
	freq.clear();
	code.clear();
}
