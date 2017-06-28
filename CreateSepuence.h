#ifndef CREATESEPUENCE_H
#define CREATESEPUENCE_H
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Sepuence{
	private:
		int len;
		double pn;
		string s;
	public:
		Sepuence();
		Sepuence(int n,double p);
		string Create();
};
#endif
