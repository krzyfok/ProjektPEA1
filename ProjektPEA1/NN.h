#ifndef NN_H
#define NN_H

#include"MenuAbstr.h"
class NN :public MenuAbstr {
public:
	double start() override;

	int nn(int start);
};

#endif