#ifndef SKILLVISITOR_H
#define SKILLVISITOR_H
#include <string>

class DoubleDamageFactory;
class ScanerFactory;
class BombardmentFactory;

class SkillVisitor {
public:
	virtual std::string visit(BombardmentFactory* creator) = 0;
	virtual std::string visit(DoubleDamageFactory* creator) = 0;
	virtual std::string visit(ScanerFactory* creator) = 0;
};

#endif