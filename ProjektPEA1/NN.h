#ifndef NN_H
#define NN_H

#include"MenuAbstr.h"
class NN :public MenuAbstr {
public:
	void start() override;

	int nn(int start);
};

#endif