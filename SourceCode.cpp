#include "SourceCode.h"
#include "HuffmanCode.h"
#include "ShannonCode.h"
#include <iostream>
#include <string>
#include <cstring>
SourceCode::SourceCode(){
	len=0;
	st="";
}
SourceCode::SourceCode(int n,string s){
	len=n;
	st=s;
	p=NULL;
	q=NULL;
}
string SourceCode::de_code(){
	if(len==1)return st;
	else if(len==2){
		q=new Shannon(st);
		int len=q->r();
		q->built(0,len-1);
		return q->de_code();
	}
	else if(len==3){
		string s=st;
		p=new Huffman(st);
		p->buitTree();
		p->de_code(s);
		return s;
	}
}
string SourceCode::en_code(string g){
	if(len==1)return g;
	else if(len==2){
		return q->en_code(g);
	}
	else if(len==3)
		return p->en_code(g);
}
SourceCode::~SourceCode(){
	if(q!=NULL)
		delete q;
	if(p!=NULL)delete p;
}

