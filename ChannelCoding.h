#ifndef CHANNELCODING_H
#define CHANNELCODING_H
#include <string>
#include <cstring>
#include "Hamming.h"
using namespace std;
class Channel{
	private:
		string st;
		int number;
		int n;
		Hamming *p;
	public:
		Channel();
		Channel(string s,int n);
		string de_code();
		string en_code(string g);
};
#endif
