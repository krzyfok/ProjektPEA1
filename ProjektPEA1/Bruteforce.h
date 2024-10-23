#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include"MenuAbstr.h"
class Bruteforce:public MenuAbstr {
public:
	double start() override;
	bool nastepna_permutacja(vector<int>& kolejnosc);
};

#endif