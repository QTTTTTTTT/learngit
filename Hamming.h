#ifndef HAMMING_H
#define HAMMING_H
#include <string>
#include <cstring> 
using namespace std;
class Hamming{
	private:
		string st;
	public:
		Hamming();
		Hamming(string s);
		string de_code();
		string en_code(string g);
};
#endif
