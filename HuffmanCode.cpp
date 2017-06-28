#include "HuffmanCode.h"
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
Huffman::Huffman(){
	st="";
};
Huffman::Huffman(string s){
	st=s;
	length=s.length();
	treeLeaf=0;
	root=length-1;
	for(int i=0;i<length;++i){
		freq[s[i]]+=1;
	}
	for(map<char,double>::iterator it=freq.begin();it!=freq.end();++it){
		it->second=it->second/(double)length;
		treeLeaf+=1;
	}
	treeNodeNum=2*treeLeaf-1;
	tree.resize(treeNodeNum);
}
void Huffman::select_min(int n,int &p1,int &p2){
	int i,j;
	for(i=0;i<n;++i){
		if(tree[i].parent==-1){
			p1=i;
			break;
		}
	}
	for(int j=i+1;j<n;++j){
		if(tree[j].parent==-1){
			p2=j;
			break;
		}
	}
	for(i=0;i<n;++i){
		if((tree[i].weight<tree[p1].weight)&&(tree[i].parent==-1)&&(i!=p2)){
			p1=i;
		}
	}
	for(j=0;j<n;++j){
		if((tree[j].weight<tree[p2].weight)&&(tree[j].parent==-1)&&(j!=p1)){
			p2=j;
		}
	} 
}
void Huffman::buitTree(){
	tree.resize(treeNodeNum);
	for(int i=0;i<treeNodeNum;++i){
		tree[i].weight=0.0;
		tree[i].date='3';
		tree[i].lch=-1;
		tree[i].rch=-1;
		tree[i].parent=-1;
	}
	int i=0;
	for(map<char,double>::iterator it=freq.begin();it!=freq.end();++it){
		tree[i].date=it->first;
		tree[i].weight=it->second;
		++i;
	}
	int p1,p2;
	for(i=treeLeaf;i<treeNodeNum;++i){
		p1=-1;
		p2=-1;
		select_min(i,p1,p2);
		tree[p1].parent=tree[p2].parent=i;
		tree[i].lch=p1;
		tree[i].rch=p2;
		tree[i].weight=tree[p1].weight+tree[p2].weight;
	}
}
void Huffman::de_code(string &ans){
	ans="";
	int parent;
	for(int i=0;i<treeLeaf;++i){
		parent=tree[i].parent;
		char dd=tree[i].date;
		while(parent!=-1){
			if(tree[parent].lch==i){
				d[dd]='0'+d[dd];
				parent=tree[parent].parent;
			}
			else{
				d[dd]='1'+d[dd];
				parent=tree[parent].parent;
			}
		}
	}
	for(int i=0;i<st.length();++i){
		for(map<char,string>::iterator it=d.begin();it!=d.end();++it){
			if(it->first==st[i]){
				ans=ans+it->second;
			}
		}
	}
}
string Huffman::en_code(string a){
	string ans="";
	for(int i=treeNodeNum;i>0;--i){
		if(tree[i].lch!=-1||tree[i].rch!=-1){
			root=i;
			break;
		}
	}
	int parent=root-1; 
	for(int i=0;i<a.length();++i){
		if(a[i]=='0'){
			parent=tree[parent].lch;
			if(tree[parent].lch==-1&&tree[parent].rch==-1){
				ans=ans+tree[parent].date;
				parent=root-1;
			}
		}
		else{
			parent=tree[parent].rch;
			if(tree[parent].lch==-1&&tree[parent].rch==-1){
				ans=ans+tree[parent].date;
				parent=root-1;
			}
		}
	}
	return ans;
}
Huffman::~Huffman(){
	freq.clear();
	d.clear();
}
