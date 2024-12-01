#include "SkillPrinter.h"

std::string  SkillPrinter::visit(BombardmentFactory* creator)
{
	return "Bombardment";
}

std::string SkillPrinter:: visit(DoubleDamageFactory* creator)
{
	return "DoubleDamage";
}


std::string SkillPrinter::visit(ScanerFactory* creator)
{
	return "Scaner";
}



