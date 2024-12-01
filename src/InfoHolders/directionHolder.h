#ifndef DIRECTIONHOLDER_H
#define DIRECTIONHOLDER_H

#include "directionReader.h"
#include "InfoHolder.h"


class DirectionHolder : public InfoHolder{
	DirectionReader reader;
	Direction d;
	public:
	void read() override;
	Direction getDirection();
};

#endif