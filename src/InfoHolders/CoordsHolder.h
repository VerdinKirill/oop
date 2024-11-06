#include "InfoHolder.h"

class CoorcHolder: public InfoHolder{
	unsigned char x;
	unsigned char y;
	public:
	void read() override;
};