#include "CreateSepuence.h"
#include <string>
#include <ctime>
#include <cstdlib> 
#include <iostream>
using namespace std;
Sepuence::Sepuence(){
	len=0;
	pn=0.0;
	s="";
};
Sepuence::Sepuence(int n,double p){
	len=n;
	pn=p;
}
string Sepuence::Create(){
	s="";
	srand((unsigned)time(0));
	for(int i=0;i<len;++i){
		double num=rand()%100/(double)101;
		if(num<=pn)s=s+'0';
		else s=s+'1';
	}
	return s;
}
