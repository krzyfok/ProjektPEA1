#ifndef RANDOM_H
#define RANDOM_H

#include"MenuAbstr.h"
class Random :public MenuAbstr {
public:
	double start() override;
	int losowanie_wierzcholka(vector <bool> odwiedz) ;
	

	
};

#endif