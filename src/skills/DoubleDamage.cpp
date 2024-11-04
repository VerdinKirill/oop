#include "DoubleDamage.h"

DoubleDamage::DoubleDamage(Field& field)
{
	this->field = &field;
}

bool DoubleDamage::use()
{
	this->field->SetDoubleDamageFlag();
	return true;
}