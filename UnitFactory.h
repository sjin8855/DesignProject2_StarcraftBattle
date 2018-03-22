#pragma once
#include "Strategy.h"
#include "Unit.h"

class UnitFactory
{
public:
	UnitFactory();
	Unit* createUnit(int type); // ���� ����
	Unit* createUnit(char type); // ���� ����
};

