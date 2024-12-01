#ifndef COMMANDHOLDER_H
#define COMMANDHOLDER_H

#include "InfoHolder.h"
#include "commandReader.h"


class CommandHolder : public InfoHolder {
	Command cmd;
	CommandReader reader;
	public:
	void read() override;
	Command getCommand();
};

#endif