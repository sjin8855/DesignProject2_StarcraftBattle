#pragma once
#include "Unit.h"
class Unit;

class BattleAlgorithm
{
private:	// ������ �����ʿ� ����
	BattleAlgorithm();
public:
	static int EstimateDamage(Unit &Attacker, Unit &Defender); // ������ ��� Attacker.offence - Defender.defense
	
};

