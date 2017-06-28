#ifndef SHANNONCODE_H
#define SHANNONCODE_H
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <iostream>;
#include <vector>
using namespace std;
class Shannon{
	private:
		int length;
		string st;
		vector<pair<char,double> > freq;
		map<char,string> code;
		int flag1;
		int ncount;
	public:
		Shannon();
		Shannon(string s);
		int r();
		void built(int m,int n);
		string de_code();
		string en_code(string s);
		~Shannon();
};
#endif;
