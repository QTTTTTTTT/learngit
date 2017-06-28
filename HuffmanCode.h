#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
class Huffman{
	private:
		int root;
		string st;
		int treeNodeNum;
		int treeLeaf;
		int length;      //³¤¶È 
		map<char,double> freq;    //ÆµÂÊ
		map<char,string> d;     //huffman±àÂë;
		struct HT_code{
			char date;
			int parent;
			int lch;
			int rch;
			double weight;
		};
		void select_min(int n, int& p1, int& p2);
		vector<HT_code> tree;
	public:
		Huffman();
		Huffman(string s);
		void buitTree();
		string en_code(string s);
		void de_code(string &);
		~Huffman();
};
#endif
