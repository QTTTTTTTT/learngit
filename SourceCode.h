#ifndef SOURCECODE_H
#define SOURCECODE_H
#include<string>
#include "ShannonCode.h"
#include "HuffmanCode.h"
#include<map>
#include<cstring>
class SourceCode{
	private:
		int len;
		string st;
		Huffman *p;
		Shannon *q;
	public:
		SourceCode();
		SourceCode(int n,string s);
		string de_code();
		string en_code(string g);
		~SourceCode();
};
#endif
