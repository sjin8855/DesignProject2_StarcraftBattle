#pragma once
#include "Strategy.h"
#include "Unit.h"

class UnitFactory
{
public:
	UnitFactory();
	Unit* createUnit(int type); // À¯´Ö »ý»ê
	Unit* createUnit(char type); // À¯´Ö »ý»ê
};

